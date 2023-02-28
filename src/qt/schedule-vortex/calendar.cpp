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
	for (auto date: m_SignificantDates) {
		delete date;
	}
	m_SignificantDates.clear();
}

// Add an event to the calendar
void Calendar::AddEvent(int day, int month, int year, string eventName) {
	Date* eventDate = new Date(day, month, year, eventName);
	Date* calendarDate = GetDate(eventDate); // Any pre-existing date info on the given date

	//
	// If an event is being added to a date that already has events on it, the
	// new event can just be added to the correct Date object within the calendar.
	// New dates have to be added first, but the new event will be included with the
	// date.
	//
	if (!Contains(eventDate)) {
		m_SignificantDates.push_back(eventDate);
	}
	else if (calendarDate != nullptr) {
		calendarDate->AddEvent(eventName);
	}

	emit AddedEvent(Date::ToQDate(*eventDate)); // Notify the application that an event was added
}

// Access calendar dates using a generic date (month, day, and year)
Date* Calendar::GetDate(Date* date) {
	auto result = std::find_if(m_SignificantDates.begin(), m_SignificantDates.end(), [date](Date* currDate) -> bool {
		return *currDate == *date;
	});

	return (result != m_SignificantDates.end())? *result : nullptr;
}

// Determine if the calendar contains event data on a certain date
bool Calendar::Contains(Date* date) {
	auto result = std::find_if(m_SignificantDates.begin(), m_SignificantDates.end(), [date](Date* currDate) -> bool {
		return *currDate == *date;
	});

	return result != m_SignificantDates.end();
}