//
// FILENAME: calendar.cpp | Schedule Vortex
// DESCRIPTION: The source file for calendar.hpp
// CREATED: 2023-02-07 @ 12:00 PM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#include "calendar.hpp"

Calendar::Calendar(QCalendarWidget* calendar):
	m_Calendar(calendar)
{}

Calendar::~Calendar() {
	delete m_Calendar;

	for (auto date: m_SignificantDates) {
		delete date;
	}
	m_SignificantDates.clear();
}

void Calendar::AddEvent(int day, int month, int year, string eventName) {
	Date* eventDate = new Date(day, month, year, eventName);
	m_SignificantDates.push_back(eventDate);

	for (auto date: m_SignificantDates) {
		qDebug() << date->m_Events.front();
	}
}