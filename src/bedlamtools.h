#pragma once

#include <vector>
#include <QtWidgets/QMainWindow>
#include "ui_bedlamtools.h"


class BedlamTools : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_button_open_img_clicked();
    void on_button_open_pal_clicked();
    void on_button_update_clicked();
    void update_image();
public:
    BedlamTools(QWidget *parent = Q_NULLPTR);
    
private:
    Ui::BedlamToolsClass ui;
    QByteArray file_bin;
    QByteArray file_pal;
    std::vector<uint8_t> screen_bufer;
    void bin_redraw();
    QRgb get_color(uint8_t value);
};
