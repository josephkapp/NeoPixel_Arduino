/********************************************************************************
** Form generated from reading UI file 'RGB_Neopixel_Desktop_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGB_NEOPIXEL_DESKTOP_GUI_H
#define UI_RGB_NEOPIXEL_DESKTOP_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RGB_Neopixel_Desktop_GUIClass
{
public:
    QAction *actionAbout;
    QAction *actionQuit;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *Animation_Label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *White_Label;
    QSpacerItem *horizontalSpacer_4;
    QSlider *White_horizontalSlider;
    QSpinBox *White_Spbinbox;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *Off_pushButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *Apply_pushButton;
    QLabel *COMPort_label;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Animation_Speed_Label;
    QSlider *Animation_Speed_horizontalSlider;
    QSpinBox *Animation_Speed_Spbinbox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Blue_Label;
    QSpacerItem *horizontalSpacer_3;
    QSlider *Blue_horizontalSlider;
    QSpinBox *Blue_Spbinbox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Red_Label;
    QSpacerItem *horizontalSpacer;
    QSlider *Red_horizontalSlider;
    QSpinBox *Red_Spbinbox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Green_Label;
    QSpacerItem *horizontalSpacer_2;
    QSlider *Green_horizontalSlider;
    QSpinBox *Green_Spbinbox;
    QLabel *Animation_Direction_Label;
    QComboBox *Animation_Direction_comboBox;
    QComboBox *Animation_comboBox;
    QComboBox *COMPort_comboBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RGB_Neopixel_Desktop_GUIClass)
    {
        if (RGB_Neopixel_Desktop_GUIClass->objectName().isEmpty())
            RGB_Neopixel_Desktop_GUIClass->setObjectName(QString::fromUtf8("RGB_Neopixel_Desktop_GUIClass"));
        RGB_Neopixel_Desktop_GUIClass->resize(794, 456);
        actionAbout = new QAction(RGB_Neopixel_Desktop_GUIClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionQuit = new QAction(RGB_Neopixel_Desktop_GUIClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(RGB_Neopixel_Desktop_GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 9, 751, 361));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Animation_Label = new QLabel(layoutWidget);
        Animation_Label->setObjectName(QString::fromUtf8("Animation_Label"));

        gridLayout->addWidget(Animation_Label, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        White_Label = new QLabel(layoutWidget);
        White_Label->setObjectName(QString::fromUtf8("White_Label"));

        horizontalLayout_5->addWidget(White_Label);

        horizontalSpacer_4 = new QSpacerItem(23, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        White_horizontalSlider = new QSlider(layoutWidget);
        White_horizontalSlider->setObjectName(QString::fromUtf8("White_horizontalSlider"));
        White_horizontalSlider->setMaximum(255);
        White_horizontalSlider->setOrientation(Qt::Horizontal);
        White_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        White_horizontalSlider->setTickInterval(10);

        horizontalLayout_5->addWidget(White_horizontalSlider);

        White_Spbinbox = new QSpinBox(layoutWidget);
        White_Spbinbox->setObjectName(QString::fromUtf8("White_Spbinbox"));
        White_Spbinbox->setMaximum(255);

        horizontalLayout_5->addWidget(White_Spbinbox);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        Off_pushButton = new QPushButton(layoutWidget);
        Off_pushButton->setObjectName(QString::fromUtf8("Off_pushButton"));

        horizontalLayout_9->addWidget(Off_pushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        Apply_pushButton = new QPushButton(layoutWidget);
        Apply_pushButton->setObjectName(QString::fromUtf8("Apply_pushButton"));

        horizontalLayout_9->addWidget(Apply_pushButton);


        gridLayout->addLayout(horizontalLayout_9, 9, 0, 1, 3);

        COMPort_label = new QLabel(layoutWidget);
        COMPort_label->setObjectName(QString::fromUtf8("COMPort_label"));

        gridLayout->addWidget(COMPort_label, 8, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Animation_Speed_Label = new QLabel(layoutWidget);
        Animation_Speed_Label->setObjectName(QString::fromUtf8("Animation_Speed_Label"));

        horizontalLayout_6->addWidget(Animation_Speed_Label);

        Animation_Speed_horizontalSlider = new QSlider(layoutWidget);
        Animation_Speed_horizontalSlider->setObjectName(QString::fromUtf8("Animation_Speed_horizontalSlider"));
        Animation_Speed_horizontalSlider->setMaximum(999);
        Animation_Speed_horizontalSlider->setSingleStep(2);
        Animation_Speed_horizontalSlider->setOrientation(Qt::Horizontal);
        Animation_Speed_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        Animation_Speed_horizontalSlider->setTickInterval(100);

        horizontalLayout_6->addWidget(Animation_Speed_horizontalSlider);

        Animation_Speed_Spbinbox = new QSpinBox(layoutWidget);
        Animation_Speed_Spbinbox->setObjectName(QString::fromUtf8("Animation_Speed_Spbinbox"));
        Animation_Speed_Spbinbox->setMaximum(999);

        horizontalLayout_6->addWidget(Animation_Speed_Spbinbox);


        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Blue_Label = new QLabel(layoutWidget);
        Blue_Label->setObjectName(QString::fromUtf8("Blue_Label"));

        horizontalLayout_4->addWidget(Blue_Label);

        horizontalSpacer_3 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        Blue_horizontalSlider = new QSlider(layoutWidget);
        Blue_horizontalSlider->setObjectName(QString::fromUtf8("Blue_horizontalSlider"));
        Blue_horizontalSlider->setMaximum(255);
        Blue_horizontalSlider->setOrientation(Qt::Horizontal);
        Blue_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        Blue_horizontalSlider->setTickInterval(10);

        horizontalLayout_4->addWidget(Blue_horizontalSlider);

        Blue_Spbinbox = new QSpinBox(layoutWidget);
        Blue_Spbinbox->setObjectName(QString::fromUtf8("Blue_Spbinbox"));
        Blue_Spbinbox->setMaximum(255);

        horizontalLayout_4->addWidget(Blue_Spbinbox);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Red_Label = new QLabel(layoutWidget);
        Red_Label->setObjectName(QString::fromUtf8("Red_Label"));
        Red_Label->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(Red_Label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Red_horizontalSlider = new QSlider(layoutWidget);
        Red_horizontalSlider->setObjectName(QString::fromUtf8("Red_horizontalSlider"));
        Red_horizontalSlider->setMaximum(255);
        Red_horizontalSlider->setOrientation(Qt::Horizontal);
        Red_horizontalSlider->setInvertedAppearance(false);
        Red_horizontalSlider->setInvertedControls(false);
        Red_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        Red_horizontalSlider->setTickInterval(10);

        horizontalLayout_2->addWidget(Red_horizontalSlider);

        Red_Spbinbox = new QSpinBox(layoutWidget);
        Red_Spbinbox->setObjectName(QString::fromUtf8("Red_Spbinbox"));
        Red_Spbinbox->setMaximum(255);

        horizontalLayout_2->addWidget(Red_Spbinbox);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Green_Label = new QLabel(layoutWidget);
        Green_Label->setObjectName(QString::fromUtf8("Green_Label"));

        horizontalLayout_3->addWidget(Green_Label);

        horizontalSpacer_2 = new QSpacerItem(23, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        Green_horizontalSlider = new QSlider(layoutWidget);
        Green_horizontalSlider->setObjectName(QString::fromUtf8("Green_horizontalSlider"));
        Green_horizontalSlider->setMaximum(255);
        Green_horizontalSlider->setOrientation(Qt::Horizontal);
        Green_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        Green_horizontalSlider->setTickInterval(10);

        horizontalLayout_3->addWidget(Green_horizontalSlider);

        Green_Spbinbox = new QSpinBox(layoutWidget);
        Green_Spbinbox->setObjectName(QString::fromUtf8("Green_Spbinbox"));
        Green_Spbinbox->setMaximum(255);

        horizontalLayout_3->addWidget(Green_Spbinbox);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 3);

        Animation_Direction_Label = new QLabel(layoutWidget);
        Animation_Direction_Label->setObjectName(QString::fromUtf8("Animation_Direction_Label"));

        gridLayout->addWidget(Animation_Direction_Label, 6, 0, 1, 1);

        Animation_Direction_comboBox = new QComboBox(layoutWidget);
        Animation_Direction_comboBox->addItem(QString());
        Animation_Direction_comboBox->addItem(QString());
        Animation_Direction_comboBox->setObjectName(QString::fromUtf8("Animation_Direction_comboBox"));

        gridLayout->addWidget(Animation_Direction_comboBox, 6, 2, 1, 1);

        Animation_comboBox = new QComboBox(layoutWidget);
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->setObjectName(QString::fromUtf8("Animation_comboBox"));

        gridLayout->addWidget(Animation_comboBox, 0, 2, 1, 1);

        COMPort_comboBox = new QComboBox(layoutWidget);
        COMPort_comboBox->setObjectName(QString::fromUtf8("COMPort_comboBox"));

        gridLayout->addWidget(COMPort_comboBox, 8, 2, 1, 1);

        RGB_Neopixel_Desktop_GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RGB_Neopixel_Desktop_GUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 794, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        RGB_Neopixel_Desktop_GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RGB_Neopixel_Desktop_GUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RGB_Neopixel_Desktop_GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RGB_Neopixel_Desktop_GUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RGB_Neopixel_Desktop_GUIClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAbout);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(RGB_Neopixel_Desktop_GUIClass);

        QMetaObject::connectSlotsByName(RGB_Neopixel_Desktop_GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *RGB_Neopixel_Desktop_GUIClass)
    {
        RGB_Neopixel_Desktop_GUIClass->setWindowTitle(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "RGB_Neopixel_Desktop_GUI", nullptr));
        actionAbout->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "About", nullptr));
        actionQuit->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Quit", nullptr));
        Animation_Label->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Animation</span></p></body></html>", nullptr));
        White_Label->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">White</span></p></body></html>", nullptr));
        Off_pushButton->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Turn Off", nullptr));
        Apply_pushButton->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Apply", nullptr));
        COMPort_label->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">COM Port</span></p></body></html>", nullptr));
        Animation_Speed_Label->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Animation Speed</span></p></body></html>", nullptr));
        Blue_Label->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">Blue</span></p></body></html>", nullptr));
        Red_Label->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Red</span></p></body></html>", nullptr));
        Green_Label->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#00ff00;\">Green</span></p></body></html>", nullptr));
        Animation_Direction_Label->setText(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Animation Direction</span></p></body></html>", nullptr));
        Animation_Direction_comboBox->setItemText(0, QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Forward", nullptr));
        Animation_Direction_comboBox->setItemText(1, QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Reverse", nullptr));

        Animation_comboBox->setItemText(0, QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Static Color", nullptr));
        Animation_comboBox->setItemText(1, QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Fade Color", nullptr));
        Animation_comboBox->setItemText(2, QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Rainbow Cycle", nullptr));
        Animation_comboBox->setItemText(3, QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Rainbow Chase", nullptr));
        Animation_comboBox->setItemText(4, QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Theater Chase", nullptr));
        Animation_comboBox->setItemText(5, QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Random Color Chase", nullptr));
        Animation_comboBox->setItemText(6, QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "Aurora Glow", nullptr));

        menuFile->setTitle(QApplication::translate("RGB_Neopixel_Desktop_GUIClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RGB_Neopixel_Desktop_GUIClass: public Ui_RGB_Neopixel_Desktop_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGB_NEOPIXEL_DESKTOP_GUI_H
