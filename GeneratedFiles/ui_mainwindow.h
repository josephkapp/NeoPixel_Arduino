/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionSelect_Com_Port;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
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
    QMenu *menuArduino_RGB_Controller;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(775, 406);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSelect_Com_Port = new QAction(MainWindow);
        actionSelect_Com_Port->setObjectName(QString::fromUtf8("actionSelect_Com_Port"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Animation_Label = new QLabel(centralWidget);
        Animation_Label->setObjectName(QString::fromUtf8("Animation_Label"));

        gridLayout->addWidget(Animation_Label, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        White_Label = new QLabel(centralWidget);
        White_Label->setObjectName(QString::fromUtf8("White_Label"));

        horizontalLayout_5->addWidget(White_Label);

        horizontalSpacer_4 = new QSpacerItem(23, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        White_horizontalSlider = new QSlider(centralWidget);
        White_horizontalSlider->setObjectName(QString::fromUtf8("White_horizontalSlider"));
        White_horizontalSlider->setMaximum(255);
        White_horizontalSlider->setOrientation(Qt::Horizontal);
        White_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        White_horizontalSlider->setTickInterval(10);

        horizontalLayout_5->addWidget(White_horizontalSlider);

        White_Spbinbox = new QSpinBox(centralWidget);
        White_Spbinbox->setObjectName(QString::fromUtf8("White_Spbinbox"));
        White_Spbinbox->setMaximum(255);

        horizontalLayout_5->addWidget(White_Spbinbox);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        Off_pushButton = new QPushButton(centralWidget);
        Off_pushButton->setObjectName(QString::fromUtf8("Off_pushButton"));

        horizontalLayout_9->addWidget(Off_pushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        Apply_pushButton = new QPushButton(centralWidget);
        Apply_pushButton->setObjectName(QString::fromUtf8("Apply_pushButton"));

        horizontalLayout_9->addWidget(Apply_pushButton);


        gridLayout->addLayout(horizontalLayout_9, 9, 0, 1, 3);

        COMPort_label = new QLabel(centralWidget);
        COMPort_label->setObjectName(QString::fromUtf8("COMPort_label"));

        gridLayout->addWidget(COMPort_label, 8, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Animation_Speed_Label = new QLabel(centralWidget);
        Animation_Speed_Label->setObjectName(QString::fromUtf8("Animation_Speed_Label"));

        horizontalLayout_6->addWidget(Animation_Speed_Label);

        Animation_Speed_horizontalSlider = new QSlider(centralWidget);
        Animation_Speed_horizontalSlider->setObjectName(QString::fromUtf8("Animation_Speed_horizontalSlider"));
        Animation_Speed_horizontalSlider->setMaximum(999);
        Animation_Speed_horizontalSlider->setSingleStep(2);
        Animation_Speed_horizontalSlider->setOrientation(Qt::Horizontal);
        Animation_Speed_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        Animation_Speed_horizontalSlider->setTickInterval(100);

        horizontalLayout_6->addWidget(Animation_Speed_horizontalSlider);

        Animation_Speed_Spbinbox = new QSpinBox(centralWidget);
        Animation_Speed_Spbinbox->setObjectName(QString::fromUtf8("Animation_Speed_Spbinbox"));
        Animation_Speed_Spbinbox->setMaximum(999);

        horizontalLayout_6->addWidget(Animation_Speed_Spbinbox);


        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Blue_Label = new QLabel(centralWidget);
        Blue_Label->setObjectName(QString::fromUtf8("Blue_Label"));

        horizontalLayout_4->addWidget(Blue_Label);

        horizontalSpacer_3 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        Blue_horizontalSlider = new QSlider(centralWidget);
        Blue_horizontalSlider->setObjectName(QString::fromUtf8("Blue_horizontalSlider"));
        Blue_horizontalSlider->setMaximum(255);
        Blue_horizontalSlider->setOrientation(Qt::Horizontal);
        Blue_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        Blue_horizontalSlider->setTickInterval(10);

        horizontalLayout_4->addWidget(Blue_horizontalSlider);

        Blue_Spbinbox = new QSpinBox(centralWidget);
        Blue_Spbinbox->setObjectName(QString::fromUtf8("Blue_Spbinbox"));
        Blue_Spbinbox->setMaximum(255);

        horizontalLayout_4->addWidget(Blue_Spbinbox);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Red_Label = new QLabel(centralWidget);
        Red_Label->setObjectName(QString::fromUtf8("Red_Label"));
        Red_Label->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(Red_Label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Red_horizontalSlider = new QSlider(centralWidget);
        Red_horizontalSlider->setObjectName(QString::fromUtf8("Red_horizontalSlider"));
        Red_horizontalSlider->setMaximum(255);
        Red_horizontalSlider->setOrientation(Qt::Horizontal);
        Red_horizontalSlider->setInvertedAppearance(false);
        Red_horizontalSlider->setInvertedControls(false);
        Red_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        Red_horizontalSlider->setTickInterval(10);

        horizontalLayout_2->addWidget(Red_horizontalSlider);

        Red_Spbinbox = new QSpinBox(centralWidget);
        Red_Spbinbox->setObjectName(QString::fromUtf8("Red_Spbinbox"));
        Red_Spbinbox->setMaximum(255);

        horizontalLayout_2->addWidget(Red_Spbinbox);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Green_Label = new QLabel(centralWidget);
        Green_Label->setObjectName(QString::fromUtf8("Green_Label"));

        horizontalLayout_3->addWidget(Green_Label);

        horizontalSpacer_2 = new QSpacerItem(23, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        Green_horizontalSlider = new QSlider(centralWidget);
        Green_horizontalSlider->setObjectName(QString::fromUtf8("Green_horizontalSlider"));
        Green_horizontalSlider->setMaximum(255);
        Green_horizontalSlider->setOrientation(Qt::Horizontal);
        Green_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        Green_horizontalSlider->setTickInterval(10);

        horizontalLayout_3->addWidget(Green_horizontalSlider);

        Green_Spbinbox = new QSpinBox(centralWidget);
        Green_Spbinbox->setObjectName(QString::fromUtf8("Green_Spbinbox"));
        Green_Spbinbox->setMaximum(255);

        horizontalLayout_3->addWidget(Green_Spbinbox);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 3);

        Animation_Direction_Label = new QLabel(centralWidget);
        Animation_Direction_Label->setObjectName(QString::fromUtf8("Animation_Direction_Label"));

        gridLayout->addWidget(Animation_Direction_Label, 6, 0, 1, 1);

        Animation_Direction_comboBox = new QComboBox(centralWidget);
        Animation_Direction_comboBox->addItem(QString());
        Animation_Direction_comboBox->addItem(QString());
        Animation_Direction_comboBox->setObjectName(QString::fromUtf8("Animation_Direction_comboBox"));

        gridLayout->addWidget(Animation_Direction_comboBox, 6, 2, 1, 1);

        Animation_comboBox = new QComboBox(centralWidget);
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->addItem(QString());
        Animation_comboBox->setObjectName(QString::fromUtf8("Animation_comboBox"));

        gridLayout->addWidget(Animation_comboBox, 0, 2, 1, 1);

        COMPort_comboBox = new QComboBox(centralWidget);
        COMPort_comboBox->setObjectName(QString::fromUtf8("COMPort_comboBox"));

        gridLayout->addWidget(COMPort_comboBox, 8, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 775, 21));
        menuArduino_RGB_Controller = new QMenu(menuBar);
        menuArduino_RGB_Controller->setObjectName(QString::fromUtf8("menuArduino_RGB_Controller"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArduino_RGB_Controller->menuAction());
        menuArduino_RGB_Controller->addSeparator();
        menuArduino_RGB_Controller->addSeparator();
        menuArduino_RGB_Controller->addAction(actionQuit);
        menuArduino_RGB_Controller->addSeparator();
        menuArduino_RGB_Controller->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(Red_horizontalSlider, SIGNAL(valueChanged(int)), Red_Spbinbox, SLOT(setValue(int)));
        QObject::connect(Green_horizontalSlider, SIGNAL(valueChanged(int)), Green_Spbinbox, SLOT(setValue(int)));
        QObject::connect(Blue_horizontalSlider, SIGNAL(valueChanged(int)), Blue_Spbinbox, SLOT(setValue(int)));
        QObject::connect(White_horizontalSlider, SIGNAL(valueChanged(int)), White_Spbinbox, SLOT(setValue(int)));
        QObject::connect(Animation_Speed_horizontalSlider, SIGNAL(valueChanged(int)), Animation_Speed_Spbinbox, SLOT(setValue(int)));
        QObject::connect(Red_Spbinbox, SIGNAL(valueChanged(int)), Red_horizontalSlider, SLOT(setValue(int)));
        QObject::connect(Green_Spbinbox, SIGNAL(valueChanged(int)), Green_horizontalSlider, SLOT(setValue(int)));
        QObject::connect(Blue_Spbinbox, SIGNAL(valueChanged(int)), Blue_horizontalSlider, SLOT(setValue(int)));
        QObject::connect(White_Spbinbox, SIGNAL(valueChanged(int)), White_horizontalSlider, SLOT(setValue(int)));
        QObject::connect(Animation_Speed_Spbinbox, SIGNAL(valueChanged(int)), Animation_Speed_horizontalSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Arduino Neopixel RGB Controller", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionSelect_Com_Port->setText(QApplication::translate("MainWindow", "Select Com Port", nullptr));
        Animation_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Animation</span></p></body></html>", nullptr));
        White_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">White</span></p></body></html>", nullptr));
        Off_pushButton->setText(QApplication::translate("MainWindow", "Turn Off", nullptr));
        Apply_pushButton->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        COMPort_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">COM Port</span></p></body></html>", nullptr));
        Animation_Speed_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Animation Speed</span></p></body></html>", nullptr));
        Blue_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">Blue</span></p></body></html>", nullptr));
        Red_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Red</span></p></body></html>", nullptr));
        Green_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#00ff00;\">Green</span></p></body></html>", nullptr));
        Animation_Direction_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Animation Direction</span></p></body></html>", nullptr));
        Animation_Direction_comboBox->setItemText(0, QApplication::translate("MainWindow", "Forward", nullptr));
        Animation_Direction_comboBox->setItemText(1, QApplication::translate("MainWindow", "Reverse", nullptr));

        Animation_comboBox->setItemText(0, QApplication::translate("MainWindow", "Static Color", nullptr));
        Animation_comboBox->setItemText(1, QApplication::translate("MainWindow", "Fade Color", nullptr));
        Animation_comboBox->setItemText(2, QApplication::translate("MainWindow", "Rainbow Cycle", nullptr));
        Animation_comboBox->setItemText(3, QApplication::translate("MainWindow", "Rainbow Chase", nullptr));
        Animation_comboBox->setItemText(4, QApplication::translate("MainWindow", "Theater Chase", nullptr));
        Animation_comboBox->setItemText(5, QApplication::translate("MainWindow", "Random Color Chase", nullptr));
        Animation_comboBox->setItemText(6, QApplication::translate("MainWindow", "Aurora Glow", nullptr));

        menuArduino_RGB_Controller->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
