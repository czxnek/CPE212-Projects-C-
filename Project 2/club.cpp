//*************************************
//Program Title: Project 2
//Project File: club.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 10/5/2021
//Program Description: function definitions for the given club.h header file
//*************************************

#include "club.h"


Club::Club(int v) : BlackCard(v) {
	{
		SetSuit('C'); // set suit to C
	}
}
string Club::Description() const {  
	{
		string a, b;
		a = BlackCard::Description(); // setting string equal to description temporarily
		b = ", Suit = "; // to match given output
		b = b + GetSuit(); // getting string and putting suit with it
		a = a + b; // assigning to description string to return
	
		return a;
	}
}
