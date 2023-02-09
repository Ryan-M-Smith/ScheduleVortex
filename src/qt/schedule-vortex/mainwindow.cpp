//
// FILENAME: mainwindow.cpp | Schedule Vortex
// DESCRIPTION: The source file for mainwindow.h
// CREATED: 2023-02-03 @ 9:22 PM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	m_UI(new Ui::MainWindow)
{
	m_UI->setupUi(this);

	m_TaskList = new TaskList(m_UI->taskList);
	
	for (int i = 0; i < 5; i++) {
		m_TaskList->AddTask("Task " + std::to_string(i));
	}
}

MainWindow::~MainWindow() {
	delete m_UI;
	delete m_TaskList;
}

