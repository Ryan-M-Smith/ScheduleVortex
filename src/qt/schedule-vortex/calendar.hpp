//
// FILENAME: calendar.hpp | Schedule Vortex
// DESCRIPTION: The calendar view
// CREATED: 2023-02-07 @ 12:00 PM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#include <QCalendarWidget>

class Calendar {
public:
	Calendar(QCalendarWidget* calendar);
	~Calendar();

private:
	QCalendarWidget* m_Calendar;
};