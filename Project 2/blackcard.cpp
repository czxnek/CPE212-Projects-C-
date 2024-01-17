//*************************************
//Program Title: Project 2
//Project File: blackcard.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 10/5/2021
//Program Description: function definitions for the given blackcard.h heaader file
//*************************************

#include "blackcard.h"


BlackCard::BlackCard(int v) : Card(v) {
	{
		SetColor("black"); // set color to black
	}
}


string BlackCard::Description() const {
	{
		string a, b;
		a = Card::Description(); // setting string equal to description temporarily
		b = ", Color = "; // getting string and putting color with it
		b = b + GetColor(); // getting string and putting color with it
		a = a + b; // assigning to description string to return
		
		return a;
		
	}
}

