#include "bedlamtools.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // set stylesheet
    QFile file("Genetive.qss");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    app.setStyleSheet(stream.readAll());

    BedlamTools w;
    w.show();
    return app.exec();
}
