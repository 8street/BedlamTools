
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
