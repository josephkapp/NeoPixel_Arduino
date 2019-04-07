#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QtWidgets>
#include <QSerialPortInfo>
#include <QDebug>
#include "ui_RGB_Neopixel_Desktop_GUI.h"

namespace Ui {
class RGB_Neopixel_Desktop_GUI;
}

class RGB_Neopixel_Desktop_GUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit RGB_Neopixel_Desktop_GUI(QWidget *parent = nullptr);
    ~RGB_Neopixel_Desktop_GUI();
    void SendCommandToArduino(QString command);
    QString CreateArduinoCommand(int selAnimation, int redVal, int greenVal, int blueVal, int whiteVal, int selAnimationSpeed, int selDirection);
    void TurnOffNeoPixel();
    void OpenSerialPort(QString portName);

public slots:
    void Animation_combobox_currentIndexChanged(int selection);
    void Apply_pushButton_clicked();
    void Off_pushButton_clicked();
    void quit();
    void about();
    void selectComPort(int index);

private:
    Ui::RGB_Neopixel_Desktop_GUIClass ui;
    QSerialPort *arduino;
    bool arduino_available;
    static const uint16_t vendorID = 4292;
    static const int productID = 60000;
    QString port_name;
    float version = 1.0;
};

#endif // MAINWINDOW_H
