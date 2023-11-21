//
// FILENAME: date.cpp | Schedule Vortex
// DESCRIPTION: The source file for date.hpp
// CREATED: 2023-02-09 @ 11:27 AM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#include "date.hpp"

Date::Date(int month, int day, int year):
	m_Month(month),
	m_Day(day),
	m_Year(year)
{}

Date::Date(int month, int day, int year, string eventName):
	Date(month, day, year)
{
	m_Events.push_back(eventName);
}

// Convert a QDate object to a Date object
Date* Date::FromQDate(const QDate& date) {
	return new Date(date.month(), date.day(), date.year());
}

QDate Date::ToQDate(const Date& date) {
	auto&& [month, day, year] = date.GetDate();
	return QDate(year, month, day);
}

// Allow comparing dates with the == operator
bool Date::operator==(const Date& date) const {
	auto &&[month, day, year] = date.GetDate(); // Get the info of the other date

	// Two dates will be considered equal if they have the same
	// month, day, and year
	return (
		this->m_Month == month &&
		this->m_Day	  == day   &&
		this->m_Year  == year
	);
}

void Date::AddEvent(const string& eventName) {
	m_Events.push_back(eventName);
}

void Date::RemoveEvent(int index) {
	m_Events.erase(m_Events.begin() + index);
}

constexpr std::tuple<int, int, int> Date::GetDate() const {
	return std::make_tuple(m_Month, m_Day, m_Year);
}

std::vector<string> Date::GetEvents() const {
	return m_Events;
}
