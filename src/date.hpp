//
// FILENAME: date.h | Schedule Vortex
// DESCRIPTION: Store information about a specific date
// CREATED: 2023-02-09 @ 11:20 AM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <vector>
#include <tuple>

using std::string;

class Date {
public:
	Date(int month, int day, int year);
	Date(int month, int day, int year, string eventName);

	void AddEvent(string eventName);
	void RemoveEvent(string eventName);

	std::tuple<int, int, int> GetDate();

private:
	int m_Month, m_Day, m_Year;
	std::vector<string> m_Events;
};

#endif // DATE_HPP