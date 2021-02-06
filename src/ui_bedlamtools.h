/********************************************************************************
** Form generated from reading UI file 'bedlamtoolsElnYsu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BEDLAMTOOLSELNYSU_H
#define BEDLAMTOOLSELNYSU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BedlamToolsClass
{
public:
    QWidget* centralWidget;
    QTabWidget* tabWidget;
    QWidget* tab_img;
    QGraphicsView* graphics;
    QWidget* horizontalLayoutWidget;
    QHBoxLayout* horizontalLayout;
    QPushButton* button_update;
    QLabel* label_5;
    QSpinBox* spinBox_img;
    QLabel* label_7;
    QSpinBox* spinBox_img_offset;
    QLabel* label;
    QSpinBox* spinBox_x;
    QLabel* label_2;
    QSpinBox* spinBox_y;
    QWidget* verticalLayoutWidget;
    QVBoxLayout* verticalLayout;
    QPushButton* button_open_img;
    QLabel* label_bin;
    QPushButton* button_open_pal;
    QLabel* label_pal;
    QSpacerItem* verticalSpacer;
    QGridLayout* gridLayout;
    QLabel* img_count;
    QLabel* img_header;
    QLabel* label_4;
    QLabel* label_6;
    QWidget* tab_2;
    QStatusBar* statusBar;

    void setupUi(QMainWindow* BedlamToolsClass)
    {
        if (BedlamToolsClass->objectName().isEmpty())
            BedlamToolsClass->setObjectName(QString::fromUtf8("BedlamToolsClass"));
        BedlamToolsClass->resize(799, 601);
        centralWidget = new QWidget(BedlamToolsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 800, 580));
        tab_img = new QWidget();
        tab_img->setObjectName(QString::fromUtf8("tab_img"));
        graphics = new QGraphicsView(tab_img);
        graphics->setObjectName(QString::fromUtf8("graphics"));
        graphics->setGeometry(QRect(10, 10, 640, 480));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphics->sizePolicy().hasHeightForWidth());
        graphics->setSizePolicy(sizePolicy);
        graphics->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphics->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        horizontalLayoutWidget = new QWidget(tab_img);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(90, 510, 481, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button_update = new QPushButton(horizontalLayoutWidget);
        button_update->setObjectName(QString::fromUtf8("button_update"));

        horizontalLayout->addWidget(button_update);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

        horizontalLayout->addWidget(label_5);

        spinBox_img = new QSpinBox(horizontalLayoutWidget);
        spinBox_img->setObjectName(QString::fromUtf8("spinBox_img"));
        spinBox_img->setMinimum(1);
        spinBox_img->setMaximum(9999);
        spinBox_img->setSingleStep(1);
        spinBox_img->setValue(1);

        horizontalLayout->addWidget(spinBox_img);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

        horizontalLayout->addWidget(label_7);

        spinBox_img_offset = new QSpinBox(horizontalLayoutWidget);
        spinBox_img_offset->setObjectName(QString::fromUtf8("spinBox_img_offset"));
        spinBox_img_offset->setMinimum(0);
        spinBox_img_offset->setMaximum(9999);
        spinBox_img_offset->setSingleStep(1);
        spinBox_img_offset->setValue(0);

        horizontalLayout->addWidget(spinBox_img_offset);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        spinBox_x = new QSpinBox(horizontalLayoutWidget);
        spinBox_x->setObjectName(QString::fromUtf8("spinBox_x"));
        spinBox_x->setMaximum(1000);
        spinBox_x->setSingleStep(1);
        spinBox_x->setValue(0);

        horizontalLayout->addWidget(spinBox_x);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        spinBox_y = new QSpinBox(horizontalLayoutWidget);
        spinBox_y->setObjectName(QString::fromUtf8("spinBox_y"));
        spinBox_y->setMaximum(1000);
        spinBox_y->setValue(0);

        horizontalLayout->addWidget(spinBox_y);

        verticalLayoutWidget = new QWidget(tab_img);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(660, 10, 131, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        button_open_img = new QPushButton(verticalLayoutWidget);
        button_open_img->setObjectName(QString::fromUtf8("button_open_img"));

        verticalLayout->addWidget(button_open_img);

        label_bin = new QLabel(verticalLayoutWidget);
        label_bin->setObjectName(QString::fromUtf8("label_bin"));

        verticalLayout->addWidget(label_bin);

        button_open_pal = new QPushButton(verticalLayoutWidget);
        button_open_pal->setObjectName(QString::fromUtf8("button_open_pal"));

        verticalLayout->addWidget(button_open_pal);

        label_pal = new QLabel(verticalLayoutWidget);
        label_pal->setObjectName(QString::fromUtf8("label_pal"));

        verticalLayout->addWidget(label_pal);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        img_count = new QLabel(verticalLayoutWidget);
        img_count->setObjectName(QString::fromUtf8("img_count"));

        gridLayout->addWidget(img_count, 0, 1, 1, 1);

        img_header = new QLabel(verticalLayoutWidget);
        img_header->setObjectName(QString::fromUtf8("img_header"));

        gridLayout->addWidget(img_header, 1, 1, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tabWidget->addTab(tab_img, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        BedlamToolsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BedlamToolsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BedlamToolsClass->setStatusBar(statusBar);

        retranslateUi(BedlamToolsClass);
        QObject::connect(spinBox_y, SIGNAL(valueChanged(int)), BedlamToolsClass, SLOT(update_image()));
        QObject::connect(spinBox_x, SIGNAL(valueChanged(int)), BedlamToolsClass, SLOT(update_image()));
        QObject::connect(spinBox_img_offset, SIGNAL(valueChanged(int)), BedlamToolsClass, SLOT(update_image()));
        QObject::connect(spinBox_img, SIGNAL(valueChanged(int)), BedlamToolsClass, SLOT(update_image()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BedlamToolsClass);
    } // setupUi

    void retranslateUi(QMainWindow* BedlamToolsClass)
    {
        BedlamToolsClass->setWindowTitle(QApplication::translate("BedlamToolsClass", "BedlamTools", nullptr));
        button_update->setText(QApplication::translate("BedlamToolsClass", "Update", nullptr));
        label_5->setText(QApplication::translate("BedlamToolsClass", "IMG:", nullptr));
        label_7->setText(QApplication::translate("BedlamToolsClass", "Additional offset:", nullptr));
        label->setText(QApplication::translate("BedlamToolsClass", "X:", nullptr));
        label_2->setText(QApplication::translate("BedlamToolsClass", "Y:", nullptr));
        button_open_img->setText(QApplication::translate("BedlamToolsClass", "Open BIN", nullptr));
        label_bin->setText(QApplication::translate("BedlamToolsClass", "No File", nullptr));
        button_open_pal->setText(QApplication::translate("BedlamToolsClass", "Open PAL", nullptr));
        label_pal->setText(QApplication::translate("BedlamToolsClass", "No File", nullptr));
        img_count->setText(QApplication::translate("BedlamToolsClass", "0", nullptr));
        img_header->setText(QApplication::translate("BedlamToolsClass", "0", nullptr));
        label_4->setText(QApplication::translate("BedlamToolsClass", "IMG Header", nullptr));
        label_6->setText(QApplication::translate("BedlamToolsClass", "IMG Count", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_img), QApplication::translate("BedlamToolsClass", "BIN", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("BedlamToolsClass", "RAW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BedlamToolsClass : public Ui_BedlamToolsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BEDLAMTOOLSELNYSU_H
