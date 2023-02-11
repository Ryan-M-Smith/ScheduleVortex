//
// FILENAME: calendar.hpp | Schedule Vortex
// DESCRIPTION: The calendar view
// CREATED: 2023-02-07 @ 12:00 PM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#include <vector>
#include <string>

#include <QCalendarWidget>

#include "date.hpp"

using std::string;

class Calendar {
public:
	Calendar(QCalendarWidget* calendar);
	~Calendar();

	void AddEvent(int day, int month, int year, string eventName);

private:
	QCalendarWidget* m_Calendar;

	std::vector<Date*> m_SignificantDates;

};