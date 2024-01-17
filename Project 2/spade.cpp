//*************************************
//Program Title: Project 2
//Project File: spade.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 10/5/2021
//Program Description: function definitions for the given spade.h header file
//*************************************

#include "spade.h"


Spade::Spade(int v) : BlackCard(v) {    // Creates a black spade card with value v
	{
		SetSuit('S'); // set suit to S
	}
}

string Spade::Description() const {  // Outputs card characteristics - value, color, suit	
	{
		string a, b;
		a = BlackCard::Description(); // setting string equal to description temporarily
		b = ", Suit = "; // to match given output
		b = b + GetSuit(); // getting string and putting suit with it
		a = a + b; // assigning to description string to return
	
		return a;
	}
}
// Hint: use base class Description method to generate part of 

