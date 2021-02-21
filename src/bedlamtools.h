#pragma once
#include <vector>
#include <QDir>
#include <qfile.h>
#include <QtMultimedia/QAudioOutput>
#include <QtWidgets/QMainWindow>=

#include "bin_file.h"
#include "file.h"
#include "ui_bedlamtools.h"

class BedlamTools : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_button_open_img_clicked();
    void on_button_open_pal_clicked();
    void on_button_update_clicked();
    void update_image();


    void on_button_open_dir_clicked();
    void on_button_play_clicked();
    void on_button_stop_clicked();
    void handleStateChanged(QAudio::State);
public:
    BedlamTools(QWidget *parent = Q_NULLPTR);
    
private:
    Ui::BedlamToolsClass ui;
    BIN_File file_bin;
    File file_pal;
    std::vector<uint8_t> screen_bufer;
    void bin_redraw();
    QRgb get_color(uint8_t value);

    QDir raw_directory;
    QFile m_playFile;
    QAudioOutput* m_audio;
};
