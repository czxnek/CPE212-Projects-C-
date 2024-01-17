/*
Program 1.1
CPE 212-01
Caleb Keller
*/

#include <iostream>
#include "DateType.h"

void DateType::Initialize(int newMonth, int newDay, int newYear)
{
	year = newYear;
	month = newMonth;
	day = newDay;
}

int DateType::GetMonth() const
{
	return month;
}

int DateType::GetYear() const
{
	return year;
}

int DateType::GetDay() const
{
	return day;
}

int main()
{
	DateType today;
	DateType anotherDay;

	today.Initialize(9, 24, 2003);
	anotherDay.Initialize(9, 25, 2003);

	std::cout << "Today is " << today.GetMonth() << "/" << today.GetDay() << "/" << today.GetYear() << std::endl;
	std::cout << "Another date is " << anotherDay.GetMonth() << "/" << anotherDay.GetDay() << "/" << anotherDay.GetYear() << std::endl;
	return 0;
}