//
// FILENAME: mainwindow.h | Schedule Vortex
// DESCRIPTION: The app's main window and base functionality
// CREATED: 2023-02-03 @ 9:22 PM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <string>
#include <utility>

#include <QMainWindow>
#include <QInputDialog>
#include <QString>
#include <QLineEdit>
#include <QDate>
#include <QTextCharFormat>

#include "qt-ui.hpp"
#include "listwrapper.hpp"
#include "calendar.hpp"
#include "date.hpp"

class MainWindow: public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private:
	std::pair<QString, bool> InputDialog(const QString& title, const QString& prompt);

	Ui::MainWindow* m_UI;
	Calendar* m_Calendar;

	ListWrapper *m_TaskList, *m_EventList;

private slots:
	void DisplayEvents(const QDate& date);
};

#endif // MAINWINDOW_H
