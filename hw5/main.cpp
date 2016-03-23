#include "multiwin.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Multiwin multiWindow;

	multiWindow.show();

	return app.exec();
}