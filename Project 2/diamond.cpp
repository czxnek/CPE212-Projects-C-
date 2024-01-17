//*************************************
//Program Title: Project 2
//Project File: diamond.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 10/5/2021
//Program Description: function definitions for the given diamond.h header file
//*************************************

#include "diamond.h"


Diamond::Diamond(int v) : RedCard(v) {  // Creates a red diamond card with value v
	{
		SetSuit('D'); // set suit to D
	}
}
string Diamond::Description() const {  // Outputs card characteristics - value, color, suit	
	{
		string a, b;
		a = RedCard::Description(); // setting string equal to description temporarily
		b = ", Suit = "; // to match given output
		b = b + GetSuit(); // getting string and putting suit with it
		a = a + b; // assigning to description string to return
	
		return a;
	}
}// Hint: use base class Description method to generate part of 
