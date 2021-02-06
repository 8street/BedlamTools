#pragma once

#include <QWidget>
#include "ui_openfile.h"

class openfile : public QWidget
{
    Q_OBJECT

public:
    openfile(QWidget *parent = Q_NULLPTR);
    ~openfile();

private:
    Ui::openfile ui;
};
