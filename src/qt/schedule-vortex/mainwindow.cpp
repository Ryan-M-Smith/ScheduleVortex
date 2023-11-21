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

	m_TaskList = new ListWrapper(m_UI->taskList);
	m_EventList = new ListWrapper(m_UI->eventList);

	// Allow the user to add an event to the calendar
	connect(m_UI->btn_addEvent, &QPushButton::released, this, [&] {
		bool ok;
		QString result;
		std::tie(result, ok) = InputDialog("Dialog", "Enter an event name");

		if (ok && !result.isEmpty()) {
			// Add the event to the calendar on the selected date 
			QDate eventDate = m_UI->calendar->selectedDate();
			m_Calendar->AddEvent(
				eventDate.month(), eventDate.day(),
				eventDate.year(), result.toStdString()
			);

			DisplayEvents(eventDate); // Temporary, until I write the connection
		}
	});

	// Allow the user to add tasks
	connect(m_UI->btn_addTask, &QPushButton::released, this, [&] {
		bool ok;
		QString result = QInputDialog::getText(this, "Dialog", "Enter a new task", QLineEdit::Normal, "", &ok);

		if (ok && !result.isEmpty()) {
			m_TaskList->AddItem(result.toStdString()); // Add the task to the task list
		}
	});

	// Allow the user to mark tasks as completed
	connect(m_UI->btn_completeTask, &QPushButton::released, this, [&] {
		if (int currentRow = m_UI->taskList->currentRow(); currentRow != -1) {
			m_TaskList->DeleteItem(currentRow);
		}
	});

	// When an event is added to the calendar, highlight that date
	connect(m_Calendar, &Calendar::AddedEvent, this, [&](const QDate& date) {
		auto format = QTextCharFormat();
		format.setBackground(QBrush(QColor(255, 0, 0, 50))); // Set the background to a transparent red
		m_UI->calendar->setDateTextFormat(date, format); // Apply the background to the calendar widget
	});

	// Display the events for a cetain day when that calendar date is clicked
	connect(m_UI->calendar, &QCalendarWidget::clicked, this, &MainWindow::DisplayEvents);
}

MainWindow::~MainWindow() {
	delete m_Calendar;
	delete m_TaskList;
	delete m_EventList;
	delete m_UI;
}

// Display an input dialog for the user to enter data
std::pair<QString, bool> MainWindow::InputDialog(const QString& title, const QString& prompt) {
	bool ok;
	QString result = QInputDialog::getText(this, title, prompt, QLineEdit::Normal, "", &ok);
	return std::make_pair(result, ok);
}

// Display the events for a given date in the event list
void MainWindow::DisplayEvents(const QDate& date) {
	Date* calDate = Date::FromQDate(date);
	m_EventList->Clear();
	
	// Get information from the calendar on the date selected. If
	// information is available, populate the event list. Otherwise,
	// it will remain empty.
	if (Date* date = m_Calendar->GetDate(calDate)) {
		for (auto event: date->GetEvents()) {
			m_EventList->AddItem(event); // Display data from the list on the screen
		}
	}
}
