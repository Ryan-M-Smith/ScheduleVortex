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
	m_UI(new Ui::MainWindow),
	m_Calendar(new Calendar(m_UI->calendar))
{
	m_UI->setupUi(this);

	m_TaskList = new TaskList(m_UI->taskList);
	
	for (int i = 0; i < 5; i++) {
		m_TaskList->AddTask("Task " + std::to_string(i));
	}

	// Allow the user to add an event when the button is pressed
	connect(m_UI->btn_addEvent, &QToolButton::released, this, [&] {
		bool ok;
		QString result = QInputDialog::getText(this, "Dialog", "Enter an event name", QLineEdit::Normal, "", &ok);

		if (ok && !result.isEmpty()) {
			// Add the event to the calendar on the selected date 
			QDate eventDate = this->m_UI->calendar->selectedDate();
			m_Calendar->AddEvent(
				eventDate.day(), eventDate.month(),
				eventDate.year(), result.toStdString()
			);
		}
	});
}

MainWindow::~MainWindow() {
	delete m_UI;
	delete m_TaskList;
}

