//
// FILENAME: main.cpp | Schedule Vortex
// DESCRIPTION: The main function
// CREATED: 2023-02-03 @ 9:22 PM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	
	MainWindow window;
	window.show();
	
	return app.exec();
}
