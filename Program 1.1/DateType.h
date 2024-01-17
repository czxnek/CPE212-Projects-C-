/*
DateType.h file
*/

class DateType
{
public:
	void Initialize(int newMonth, int newDay, int newYear);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
private:
	int year;
	int month;
	int day;
};
