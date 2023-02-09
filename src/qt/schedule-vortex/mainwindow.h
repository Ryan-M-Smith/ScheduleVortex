//
// FILENAME: mainwindow.h | Schedule Vortex
// DESCRIPTION: The app's main window and base functionality
// CREATED: 2023-02-03 @ 9:22 PM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qt-ui.hpp"
#include "tasklist.hpp"

class MainWindow: public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow* m_UI;

	TaskList* m_TaskList;
};

#endif // MAINWINDOW_H
