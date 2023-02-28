//
// FILENAME: date.h | Schedule Vortex
// DESCRIPTION: Store information about a specific date
// CREATED: 2023-02-09 @ 11:20 AM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include <QDate>

using std::string;

class Date {
public:
	Date(int month, int day, int year);
	Date(int month, int day, int year, string eventName);

	static Date* FromQDate(const QDate& date);
	static QDate ToQDate(const Date& date);

	bool operator==(const Date& date) const;

	void AddEvent(const string& eventName);
	void RemoveEvent(int index);

	constexpr std::tuple<int, int, int> GetDate() const;
	std::vector<string> GetEvents() const;

private:
	int m_Month, m_Day, m_Year;
	std::vector<string> m_Events {};
};

#endif // DATE_HPP