#include "RGB_Neopixel_Desktop_GUI.h"
#include <iostream>

//hi

RGB_Neopixel_Desktop_GUI::RGB_Neopixel_Desktop_GUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Setup the combo boxes with animations and directions supported by the arduino
	ui.Animation_comboBox->setItemText(0, "Static Color");
	ui.Animation_comboBox->setItemText(1, "Fade Color");
	ui.Animation_comboBox->setItemText(2, "Rainbow Cycle");
	ui.Animation_comboBox->setItemText(3, "Rainbow Chase");
	ui.Animation_comboBox->setItemText(4, "Theater Chase");
	ui.Animation_comboBox->setItemText(5, "Random Color Chase");
	ui.Animation_comboBox->setItemText(6, "Aurora Glow");

	ui.Animation_Direction_comboBox->setItemText(0, "Forward");
	ui.Animation_Direction_comboBox->setItemText(1, "Reverse");
	ui.Animation_Direction_comboBox->setDisabled(true);

	//Set up the QT connections
	connect(ui.Red_horizontalSlider, SIGNAL(valueChanged(int)), ui.Red_Spbinbox, SLOT(setValue(int)));
	connect(ui.Green_horizontalSlider, SIGNAL(valueChanged(int)), ui.Green_Spbinbox, SLOT(setValue(int)));
	connect(ui.Blue_horizontalSlider, SIGNAL(valueChanged(int)), ui.Blue_Spbinbox, SLOT(setValue(int)));
	connect(ui.White_horizontalSlider, SIGNAL(valueChanged(int)), ui.White_Spbinbox, SLOT(setValue(int)));
	connect(ui.Animation_Speed_horizontalSlider, SIGNAL(valueChanged(int)), ui.Animation_Speed_Spbinbox, SLOT(setValue(int)));
	connect(ui.Red_Spbinbox, SIGNAL(valueChanged(int)), ui.Red_horizontalSlider, SLOT(setValue(int)));
	connect(ui.Green_Spbinbox, SIGNAL(valueChanged(int)), ui.Green_horizontalSlider, SLOT(setValue(int)));
	connect(ui.Blue_Spbinbox, SIGNAL(valueChanged(int)), ui.Blue_horizontalSlider, SLOT(setValue(int)));
	connect(ui.White_Spbinbox, SIGNAL(valueChanged(int)), ui.White_horizontalSlider, SLOT(setValue(int)));
	connect(ui.Animation_Speed_Spbinbox, SIGNAL(valueChanged(int)), ui.Animation_Speed_horizontalSlider, SLOT(setValue(int)));
	connect(ui.Animation_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(Animation_combobox_currentIndexChanged(int)));
	connect(ui.Apply_pushButton, SIGNAL(released()), this, SLOT(Apply_pushButton_clicked()));
	connect(ui.Off_pushButton, SIGNAL(released()), this, SLOT(Off_pushButton_clicked()));
	connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(quit()));
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(about()));
	connect(ui.COMPort_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectComPort(int)));

	//Set up Arduino connection
	arduino = new QSerialPort;
	arduino_available = false;

	foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
		if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
			if (serialPortInfo.vendorIdentifier() == vendorID) {
				if (serialPortInfo.productIdentifier() == productID) {
					port_name = serialPortInfo.portName();
					arduino_available = true;
				}
			}
		}
	}

	RGB_Neopixel_Desktop_GUI::OpenSerialPort(port_name);

	//Populate the com port combobox with available ports on the PC
	foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
		ui.COMPort_comboBox->addItem(serialPortInfo.portName());
	}

	//If we only have one port available, disable the combobox
	if (ui.COMPort_comboBox->count() == 1)
		ui.COMPort_comboBox->setDisabled(true);
}

RGB_Neopixel_Desktop_GUI::~RGB_Neopixel_Desktop_GUI()
{
	//delete ui;
}

void RGB_Neopixel_Desktop_GUI::OpenSerialPort(QString portName)
{
	if (arduino_available)
	{
		arduino->setPortName(portName);
		arduino->open(QSerialPort::WriteOnly);
		arduino->setBaudRate(QSerialPort::Baud57600);
		arduino->setDataBits(QSerialPort::Data8);
		arduino->setParity(QSerialPort::NoParity);
		arduino->setStopBits(QSerialPort::OneStop);
		arduino->setFlowControl(QSerialPort::NoFlowControl);
	}
	else
		QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
}

void RGB_Neopixel_Desktop_GUI::Animation_combobox_currentIndexChanged(int selection)
{
	switch (selection)
	{
	case 0:
	{
		ui.Animation_Direction_comboBox->setDisabled(true);

		ui.Red_Spbinbox->setEnabled(true);
		ui.Green_Spbinbox->setEnabled(true);
		ui.Blue_Spbinbox->setEnabled(true);
		ui.White_Spbinbox->setEnabled(true);
		ui.Red_horizontalSlider->setEnabled(true);
		ui.Green_horizontalSlider->setEnabled(true);
		ui.Blue_horizontalSlider->setEnabled(true);
		ui.White_horizontalSlider->setEnabled(true);

		//MainWindow::pushButton_clicked();

		break;
	}
	case 1:
	{
		ui.Animation_Direction_comboBox->setDisabled(true);
		ui.Red_Spbinbox->setDisabled(true);
		ui.Green_Spbinbox->setDisabled(true);
		ui.Blue_Spbinbox->setDisabled(true);
		ui.White_Spbinbox->setDisabled(true);
		ui.Red_horizontalSlider->setDisabled(true);
		ui.Green_horizontalSlider->setDisabled(true);
		ui.Blue_horizontalSlider->setDisabled(true);
		ui.White_horizontalSlider->setDisabled(true);

		ui.Red_Spbinbox->setValue(0);
		ui.Green_Spbinbox->setValue(0);
		ui.Blue_Spbinbox->setValue(0);
		ui.White_Spbinbox->setValue(0);

		break;
	}
	case 2:
	{
		ui.Animation_Direction_comboBox->setDisabled(true);
		ui.Red_Spbinbox->setDisabled(true);
		ui.Green_Spbinbox->setDisabled(true);
		ui.Blue_Spbinbox->setDisabled(true);
		ui.White_Spbinbox->setDisabled(true);
		ui.Red_horizontalSlider->setDisabled(true);
		ui.Green_horizontalSlider->setDisabled(true);
		ui.Blue_horizontalSlider->setDisabled(true);
		ui.White_horizontalSlider->setDisabled(true);

		ui.Red_Spbinbox->setValue(0);
		ui.Green_Spbinbox->setValue(0);
		ui.Blue_Spbinbox->setValue(0);
		ui.White_Spbinbox->setValue(0);

		break;
	}
	case 3:
	{
		ui.Animation_Direction_comboBox->setEnabled(true);

		ui.Red_Spbinbox->setDisabled(true);
		ui.Green_Spbinbox->setDisabled(true);
		ui.Blue_Spbinbox->setDisabled(true);
		ui.White_Spbinbox->setDisabled(true);
		ui.Red_horizontalSlider->setDisabled(true);
		ui.Green_horizontalSlider->setDisabled(true);
		ui.Blue_horizontalSlider->setDisabled(true);
		ui.White_horizontalSlider->setDisabled(true);

		ui.Red_Spbinbox->setValue(0);
		ui.Green_Spbinbox->setValue(0);
		ui.Blue_Spbinbox->setValue(0);
		ui.White_Spbinbox->setValue(0);

		break;
	}
	case 4:
	{
		ui.Animation_Direction_comboBox->setEnabled(true);
		ui.Red_Spbinbox->setEnabled(true);
		ui.Green_Spbinbox->setEnabled(true);
		ui.Blue_Spbinbox->setEnabled(true);
		ui.White_Spbinbox->setEnabled(true);
		ui.Red_horizontalSlider->setEnabled(true);
		ui.Green_horizontalSlider->setEnabled(true);
		ui.Blue_horizontalSlider->setEnabled(true);
		ui.White_horizontalSlider->setEnabled(true);

		break;
	}
	case 5:
	{
		ui.Red_Spbinbox->setDisabled(true);
		ui.Green_Spbinbox->setDisabled(true);
		ui.Blue_Spbinbox->setDisabled(true);
		ui.White_Spbinbox->setDisabled(true);
		ui.Red_horizontalSlider->setDisabled(true);
		ui.Green_horizontalSlider->setDisabled(true);
		ui.Blue_horizontalSlider->setDisabled(true);
		ui.White_horizontalSlider->setDisabled(true);

		ui.Red_Spbinbox->setValue(0);
		ui.Green_Spbinbox->setValue(0);
		ui.Blue_Spbinbox->setValue(0);
		ui.White_Spbinbox->setValue(0);

		ui.Animation_Direction_comboBox->setEnabled(true);

		break;
	}
	case 6:
	{
		ui.Animation_Direction_comboBox->setDisabled(true);
		ui.Red_Spbinbox->setDisabled(true);
		ui.Green_Spbinbox->setDisabled(true);
		ui.Blue_Spbinbox->setDisabled(true);
		ui.White_Spbinbox->setDisabled(true);
		ui.Red_horizontalSlider->setDisabled(true);
		ui.Green_horizontalSlider->setDisabled(true);
		ui.Blue_horizontalSlider->setDisabled(true);
		ui.White_horizontalSlider->setDisabled(true);

		ui.Red_Spbinbox->setValue(0);
		ui.Green_Spbinbox->setValue(0);
		ui.Blue_Spbinbox->setValue(0);
		ui.White_Spbinbox->setValue(0);

		break;
	}
	}

}

void RGB_Neopixel_Desktop_GUI::Apply_pushButton_clicked()
{
	int selectedAnimation = ui.Animation_comboBox->currentIndex();
	int red = ui.Red_Spbinbox->value();
	int green = ui.Green_Spbinbox->value();
	int blue = ui.Blue_Spbinbox->value();
	int white = ui.White_Spbinbox->value();
	int selectedAnimationSpeed = ui.Animation_Speed_Spbinbox->value();
	int selectedAnimationDirection = ui.Animation_Direction_comboBox->currentIndex();
	QString arduinoCommand = RGB_Neopixel_Desktop_GUI::CreateArduinoCommand(selectedAnimation, red, green, blue, white, selectedAnimationSpeed, selectedAnimationDirection);

	RGB_Neopixel_Desktop_GUI::SendCommandToArduino(arduinoCommand);
}

void RGB_Neopixel_Desktop_GUI::TurnOffNeoPixel()
{
	ui.Animation_comboBox->setCurrentIndex(0);
	ui.Red_Spbinbox->setValue(0);
	ui.Green_Spbinbox->setValue(0);
	ui.Blue_Spbinbox->setValue(0);
	ui.White_Spbinbox->setValue(0);

	int selectedAnimation = ui.Animation_comboBox->currentIndex();
	int red = ui.Red_Spbinbox->value();
	int green = ui.Green_Spbinbox->value();
	int blue = ui.Blue_Spbinbox->value();
	int white = ui.White_Spbinbox->value();
	int selectedAnimationSpeed = ui.Animation_Speed_Spbinbox->value();
	int selectedAnimationDirection = ui.Animation_Direction_comboBox->currentIndex();
	QString arduinoCommand = RGB_Neopixel_Desktop_GUI::CreateArduinoCommand(selectedAnimation, red, green, blue, white, selectedAnimationSpeed, selectedAnimationDirection);

	RGB_Neopixel_Desktop_GUI::SendCommandToArduino(arduinoCommand);
}

void RGB_Neopixel_Desktop_GUI::Off_pushButton_clicked()
{
	RGB_Neopixel_Desktop_GUI::TurnOffNeoPixel();
}

QString RGB_Neopixel_Desktop_GUI::CreateArduinoCommand(int selAnimation, int redVal, int greenVal, int blueVal, int whiteVal, int selAnimationSpeed, int selDirection)
{
	QString tempArduinoCommand;

	//Build the arduino command.
	//Example Data Steam: A7G0B0R255S50D0T
	//A = Animation
	//R = Red
	//G = Green
	//B = Blue
	//w = White
	//S = Delay speed
	//D = Animation Direction
	//T = End of Input
	tempArduinoCommand.append('A');
	tempArduinoCommand.append(QString::number(selAnimation));
	tempArduinoCommand.append('R');
	tempArduinoCommand.append(QString::number(redVal));
	tempArduinoCommand.append('G');
	tempArduinoCommand.append(QString::number(greenVal));
	tempArduinoCommand.append('B');
	tempArduinoCommand.append(QString::number(blueVal));
	//arduinoCommand.append('W');
	//arduinoCommand.append(QString::number(whiteVal));
	tempArduinoCommand.append('S');
	tempArduinoCommand.append(QString::number(selAnimationSpeed));
	tempArduinoCommand.append('D');
	tempArduinoCommand.append(QString::number(selDirection));
	tempArduinoCommand.append('T');

	return tempArduinoCommand;
}

void RGB_Neopixel_Desktop_GUI::SendCommandToArduino(QString command)
{
	qDebug() << "command: " << command;
	if (arduino->isWritable())
	{
		arduino->write(command.toStdString().c_str());
	}
	else
	{
		qDebug() << "Unable to send command " << command << " to the arduino.";
		QMessageBox::warning(this, "Communication Error", "Unable to send the command to the arduino");
	}
}

void RGB_Neopixel_Desktop_GUI::quit()
{
	//MainWindow::TurnOffNeoPixel();
	qDebug() << "Closing arduino port" << endl;
	arduino->close();
	if (arduino->isOpen())
		qDebug() << "Failed to close the arduino port" << endl;
	else
		qDebug() << "Arduino port closed successfully" << endl;
	QApplication::quit();
}

void RGB_Neopixel_Desktop_GUI::about()
{
	QMessageBox msgBox;
	QString strTemp = "Created by Joseph Kapp. To be used with Arduino Neopixel code also written by Joseph Kapp.\n This is a windows based GUI that is used to control the RGB functions of an addressable NeoPixel LED strip controlled by an Arduino Microprocessor.\n Version: ";
	strTemp.append(QString::number(version));
	msgBox.setText(strTemp);
	msgBox.setWindowTitle("About");

	msgBox.exec();
}

void RGB_Neopixel_Desktop_GUI::selectComPort(int index)
{
	arduino->close();
	if (arduino->isOpen())
		qDebug() << "Failed to close the arduino port" << endl;
	else
		qDebug() << "Arduino port closed successfully" << endl;

	RGB_Neopixel_Desktop_GUI::OpenSerialPort(ui.COMPort_comboBox->currentText());
}
