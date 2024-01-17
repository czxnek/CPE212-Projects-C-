//*************************************
//Program Title: Project 2
//Project File: redcard.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 10/5/2021
//Program Description: function definitions for the given redcard.h header file
//*************************************

#include "redcard.h"


RedCard::RedCard(int v) : Card(v) {
	{
		SetColor("red"); // set color to red
	}
}


string RedCard::Description() const {
	{
	
		string a, b;
		a = Card::Description(); // setting string equal to description temporarily
		b = ", Color = "; // to match given output
		b = b + GetColor(); // getting string and putting color with it
		a = a + b; // assigning to description string to return
		
		return a;
		
	}
}
