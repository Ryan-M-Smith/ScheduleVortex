//
// FILENAME: calendar.hpp | Schedule Vortex
// DESCRIPTION: The calendar view
// CREATED: 2023-02-07 @ 12:00 PM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <vector>
#include <string>
#include <algorithm>

#include <QObject>
#include <QCalendarWidget>
#include <QTextCharFormat>
#include <QDate>

#include "date.hpp"

using std::string;

class Calendar : public QObject {
	Q_OBJECT

public:
	Calendar(QCalendarWidget* calendar);
	~Calendar();

	void AddEvent(int day, int month, int year, string eventName);
	Date* GetDate(Date* date);
	bool Contains(Date* date);

signals:
	void AddedEvent(const QDate& date);

private:
	QCalendarWidget* m_Calendar;
	std::vector<Date*> m_SignificantDates;
};

#endif // CALENDAR_HPP