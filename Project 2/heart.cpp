//*************************************
//Program Title: Project 2
//Project File: heart.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 10/5/2021
//Program Description: function definitions for the given heart.h header file
//*************************************

#include "heart.h"


Heart::Heart(int v) : RedCard(v) {
	{
		SetSuit('H'); // set suit to H
	}
}

string Heart::Description() const { // Outputs card characteristics - value, color, suit	
	{
		string a, b;
		a = RedCard::Description(); // setting string equal to description temporarily
		b = ", Suit = "; // to match given output
		b = b + GetSuit(); // getting string and putting suit with it
		a = a + b; // assigning to description string to return

		return a;
	}
}// Hint: use base class Description method to generate part of 
