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
