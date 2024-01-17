//*************************** timetest.cpp *****************************
// Original provided by Prof. D. Coe
// Purpose: Test driver of class to represent Time ADT
//******************************************************************
#include <iostream>
using namespace std;
#include "time.h"



// ------------------------------------------------------------------------------
int main()
{
    Time	time1(5, 30, 0);
    Time	time2;
    int     loopCount;
	using	std::cout;
	using	std::endl;

    cout << "time1: ";
    time1.Write();
    cout << "  time2: ";
    time2.Write();
    cout << endl;
    if (time1.Equal(time2))
        cout << "Times are equal" << endl;
    else
        cout << "Times are NOT equal" << endl;

    time2 = time1;
    cout << "time1: ";
    time1.Write();
    cout << "  time2: ";
    time2.Write();
    cout << endl;

    if (time1.Equal(time2))
        cout << "Times are equal" << endl;
    else
        cout << "Times are NOT equal" << endl;

    time2.Increment();
    cout << "New time2: ";
    time2.Write();
    cout << endl;

    if (time1.LessThan(time2))
        cout << "time1 is less than time2" << endl;
    else
        cout << "time1 is NOT less than time2" << endl;

    if (time2.LessThan(time1))
        cout << "time2 is less than time1" << endl;
    else
        cout << "time2 is NOT less than time1" << endl;

    time1.Set(23, 59, 55);
    cout << "Incrementing time1 from 23:59:55:" << endl;
    for(loopCount = 1; loopCount <= 10; loopCount++)
    {
        time1.Write();
        cout << ' ';
        time1.Increment();
    }
    cout << endl;
    return 0;
}
// ------------------------------------------------------------------------------


