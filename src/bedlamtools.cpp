
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

    QFile file(bin_path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
        return;
    }
    // set path to label
    std::filesystem::path file_path = bin_path.toStdString();
    ui.label_bin->setText( QString::fromStdString( file_path.filename().string() ) );

    // read file
    file_bin.clear();
    file_bin = file.readAll();    
    file.close();

    // read image info
    char* data_ptr = file_bin.data();
    int image_count = *(uint16_t*)data_ptr;
    ui.img_count->setText(QString::number(image_count));
    ui.spinBox_img->setMaximum(image_count);
    if (ui.spinBox_img->value() > image_count) {
        ui.spinBox_img->setValue(image_count);
    }

    bin_redraw();
}

void BedlamTools::on_button_open_pal_clicked() {
    QString pal_path = QFileDialog::getOpenFileName(this, "Open a file", "", "*.pal" );

    QFile file(pal_path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
        return;
    }

    // set path to label
    std::filesystem::path file_path = pal_path.toStdString();
    ui.label_pal->setText(QString::fromStdString(file_path.filename().string()));

    // read file
    file_pal.clear();
    file_pal = file.readAll();
    file.close();

    bin_redraw();
}

void BedlamTools::on_button_update_clicked() {
    bin_redraw();
}

void BedlamTools::update_image() {
    bin_redraw();
}


void BedlamTools::bin_redraw() {

    if (file_bin.isEmpty()){
        return;
    }
    screen_bufer.clear();
    screen_bufer.resize(640 * 480 * 2);

    QImage image(640, 480, QImage::Format_RGB888);

    // read image info
    int32_t header_size = 2;
    char* data_ptr = file_bin.data();
    uint8_t* file_data_ptr = (uint8_t*)data_ptr;
    int32_t offset = 4 * (ui.spinBox_img->value() - 1);
    data_ptr = data_ptr + header_size + offset;
    int32_t image_address = *(uint32_t*)(data_ptr);
    char* img = data_ptr + image_address;
    uint16_t img_header = *(uint16_t*)img;
    ui.img_header->setText(QString::number(img_header));

    // read spinbox values
    int add_offset = ui.spinBox_img_offset->value();
    int scr_x = ui.spinBox_x->value();
    int scr_y = ui.spinBox_y->value();

    // print img in buffer, use standard bedlam function
    uint8_t* screen_buffer_ptr = screen_bufer.data();
    draw_IMG_in_buffer(ui.spinBox_img->value() - 1, 0, scr_y, scr_x, screen_buffer_ptr, file_data_ptr);

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
    if (file_pal.isEmpty() || file_pal.size() < 255 * 3) {
        return qRgb(value, value, value);
    }
    // input value is offset in .pal file. First 2 byte in .pal file is info and contain no color data
    int brightness = 4;
    return qRgb(file_pal.at(value * 3 + 2) * brightness, file_pal.at(value * 3 + 3) * brightness, file_pal.at(value * 3 + 4) * brightness);
}
