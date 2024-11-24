#pragma once
#include <iostream>
#include <ctime>
using std::ostream;

class Date {
private:
	std::time_t currentTime;
	std::tm localTime;

public:
	Date() {
		currentTime = std::time(nullptr);
		localtime_s(&localTime, &currentTime); //non standard -> not portable version of std::localtime function
	}

	//explicitly defaulting all special member functions (except move because we didn't teach that)
	Date(const Date& other) = default;
	Date& operator=(const Date& rhs) = default;
	~Date() = default;

	int getYear() const {
		return localTime.tm_year + 1900;
	}

	int getMonth() const {
		return localTime.tm_mon + 1;
	}

	int getDay() const {
		return localTime.tm_mday;
	}

	int getHour() const {
		return localTime.tm_hour;
	}

	int getMinute() const {
		return localTime.tm_min;
	}

	int getSecond() const {
		return localTime.tm_sec;
	}

	friend ostream& operator<<(ostream& out, const Date& date)
	{
		out << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
		return out << " " << date.getHour() << ":" << date.getMinute() << ":" << date.getSecond();
	}
};
