/********************************************************************************
** Form generated from reading UI file 'openfileZhVAaM.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef OPENFILEZHVAAM_H
#define OPENFILEZHVAAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openfile
{
public:

    void setupUi(QWidget* openfile)
    {
        if (openfile->objectName().isEmpty())
            openfile->setObjectName(QString::fromUtf8("openfile"));
        openfile->resize(400, 300);

        retranslateUi(openfile);

        QMetaObject::connectSlotsByName(openfile);
    } // setupUi

    void retranslateUi(QWidget* openfile)
    {
        openfile->setWindowTitle(QApplication::translate("openfile", "openfile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class openfile : public Ui_openfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // OPENFILEZHVAAM_H
