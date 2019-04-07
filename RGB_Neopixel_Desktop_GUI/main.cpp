#include "RGB_Neopixel_Desktop_GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RGB_Neopixel_Desktop_GUI w;
	w.show();
	return a.exec();
}
