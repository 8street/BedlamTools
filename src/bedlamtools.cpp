
#include "stdafx.h"

#include <qfiledialog.h>
#include <qmessagebox.h>
#include <QPainter>

#include "Bedlam_func.h"
#include "bedlamtools.h"


BedlamTools::BedlamTools(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void BedlamTools::on_button_open_img_clicked() {
    QString bin_path = QFileDialog::getOpenFileName(this, "Open a file", "", "*.bin");

    // set path to label
    std::filesystem::path file_path = bin_path.toStdString();
    ui.label_bin->setText( QString::fromStdString( file_path.filename().string() ) );

    // read file
    file_bin.load(bin_path.toStdString());

    if (!file_bin.get_size()) {
        return;
    }

    // read image info
    int image_count = file_bin.get_img_count();
    ui.img_count->setText(QString::number(image_count));
    ui.spinBox_img->setMaximum(image_count - 1);
    if (ui.spinBox_img->value() >= image_count) {
        ui.spinBox_img->setValue(image_count - 1);
    }

    bin_redraw();
}

void BedlamTools::on_button_open_pal_clicked() {
    QString pal_path = QFileDialog::getOpenFileName(this, "Open a file", "", "*.pal" );

    // set path to label
    std::filesystem::path file_path = pal_path.toStdString();
    ui.label_pal->setText(QString::fromStdString(file_path.filename().string()));

    // read file
    file_pal.load(pal_path.toStdString());

    bin_redraw();
}

void BedlamTools::on_button_update_clicked() {
    bin_redraw();
}

void BedlamTools::update_image() {
    bin_redraw();
}


void BedlamTools::bin_redraw() {

    if (!file_bin.get_size()){
        return;
    }
    screen_bufer.clear();
    screen_bufer.resize(640 * 480);

    QImage image(640, 480, QImage::Format_RGB888);
                                                                                                    
    // read image info
    int32_t header_size = 2;
    uint8_t* file_data_ptr = file_bin.get_ptr();
    int32_t img = ui.spinBox_img->value();
    uint16_t img_header = *reinterpret_cast<uint16_t*>(file_bin.get_img_header_ptr(img));
    ui.img_header->setText(QString::number(img_header));
    ui.img_width->setText(QString::number( file_bin.get_img_width(img) ));
    ui.img_height->setText(QString::number( file_bin.get_img_height(img) ));
    ui.img_offset_x->setText(QString::number( file_bin.get_img_x_offset(img) ));
    ui.img_offset_y->setText(QString::number( file_bin.get_img_y_offset(img) ));

    // read spinbox values
    int add_offset = ui.spinBox_img_offset->value();
    int scr_x = ui.spinBox_x->value();
    int scr_y = ui.spinBox_y->value();

    // print img in buffer, use standard bedlam function
    uint8_t* screen_buffer_ptr = screen_bufer.data();
    if (img_header == 0x0007) 
    {
        draw_tile(img, 0, 0, screen_buffer_ptr + scr_y * 640 + scr_x, file_data_ptr);
    }
    else 
    {
        draw_IMG_in_buffer(img, 0, scr_y, scr_x, screen_buffer_ptr, file_data_ptr);
    }


    // print img buffer to QImage
    int i = 0;
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            image.setPixel(x, y, get_color(screen_bufer.at(i)));
            i++;
        }
    }

    // out QImage
    QGraphicsScene* scene = new QGraphicsScene(this);
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    ui.graphics->setScene(scene);

    //QMessageBox::information(this, "You are stunning!", "Image has been drawn!");
}

QRgb BedlamTools::get_color(uint8_t value){
    // if invalid .pal file, then return value unchanged
    if (!file_pal.get_size() || file_pal.get_size() < 255 * 3) {
        return qRgb(value, value, value);
    }
    // input value is offset in .pal file. First 2 byte in .pal file is info and contain no color data
    int brightness = 4;

    return qRgb(file_pal.at(value * 3 + 2) * brightness, file_pal.at(value * 3 + 3) * brightness, file_pal.at(value * 3 + 4) * brightness);
}


void BedlamTools::on_button_open_dir_clicked()
{
    raw_directory = QFileDialog::getExistingDirectory(this, tr("Open a RAW/MRW directory"));

    // set path to label
    QString dir_str = QString::fromStdString("Directory: ") + raw_directory.path();
    ui.label_directory->setText(dir_str);

    QStringList raws = raw_directory.entryList(QStringList() << "*.raw" << "*.RAW" << "*.mrw" << "*.MRW", QDir::Files);
    ui.listWidget->clear();
    ui.listWidget->addItems(raws);
}

void BedlamTools::on_button_play_clicked()
{
    QString file_path;
    if (m_playFile.isOpen()) {
        m_playFile.close();
    }
    if (raw_directory.exists() && ui.listWidget->count()) {
        file_path = raw_directory.path() + raw_directory.separator() + ui.listWidget->currentItem()->text();
        m_playFile.setFileName(file_path);
    }
    if (m_playFile.exists()) {
        m_playFile.open(QIODevice::ReadOnly);

        QAudioFormat format;
        // Set up the format, eg.
        format.setSampleRate(ui.sampleratemultimedia->text().toInt());
        format.setChannelCount(ui.channelsmultimedia->text().toInt());
        format.setSampleSize(ui.bitsmultimedia->text().toInt());
        format.setCodec("audio/pcm");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::UnSignedInt);

        QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
        if (!info.isFormatSupported(format)) {
            qWarning() << "Raw audio format not supported by backend, cannot play audio.";
            return;
        }

        m_audio = new QAudioOutput(format, this);
        connect(m_audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
        m_audio->start(&m_playFile);
    }
}

void BedlamTools::on_button_stop_clicked()
{
    if (raw_directory.exists() && ui.listWidget->count()) {
        if (m_playFile.exists() && m_playFile.isOpen())
        {
            m_playFile.close();
            m_audio->stop();
        }
    }
}

void BedlamTools::handleStateChanged(QAudio::State newState)
{
    switch (newState) {
    case QAudio::IdleState:
        // Finished playing (no more data)
        m_audio->stop();
        m_playFile.close();
        delete m_audio;
        break;

    case QAudio::StoppedState:
        // Stopped for other reasons
        if (m_audio->error() != QAudio::NoError) {
            // Error handling
        }
        break;

    default:
        // ... other cases as appropriate
        break;
    }
}
