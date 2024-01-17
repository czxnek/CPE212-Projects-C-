// ****************************************
// Program Title: Project 1
// Project File: Project01.cpp
// Name:Caleb Keller
// Course Section: CPE-212-01
// Due Date: 09/22/2021
// Program Description:Image Manipulation Program
// ****************************************

#include<iostream>
#include<fstream>
#include<string>

using namespace std;



void LoadImage(const string imagefile, int image[MAXROWS][MAXCOLS])
{
	
	ifstream input; // declaring ifstream variable for use inside function

	input.open(imagefile.c_str()); // opening file
	
	input.ignore(150, '\n'); // ignoring first line
	input.ignore(150, '\n'); // ignoring second line


	for (int row = 0; row < MAXROWS; row++) // for loop to grab binary values 
	{

		for (int col = 0; col < MAXCOLS; col++)
		{
			input >> image[row][col]; // read in data from file
		}
	}

	input.close();
	// close file!!!!!
	
}  // End LoadImage()

/***********************************************************************/

void FlipHorizontal(int image[MAXROWS][MAXCOLS])

{

	for (int row = 0; row < MAXROWS; row++)
	{
		for (int col = 0; col < MAXCOLS - row - 1; col++) // 10  - n - 1 
		{
			int NEWmatrix = image[row][col]; // assign a new matrix to edit
			image[row][col] = image[row][9 - col]; // assigning
			image[row][9 - col] = NEWmatrix; // finished
		}
	}	
	
} // End FlipHorizontal()

/***********************************************************************/

void FlipVertical(int image[MAXROWS][MAXCOLS])

{

	for (int row = 0; row < MAXROWS; row++)
	{
		for (int col = 0; col < MAXCOLS - row; col++)
		{
			int NEWmatrix = image[row][col];  // assign a new matrix to edit
			image[row][col] = image[9 - row][col]; // assigning
			image[9 - row][col] = NEWmatrix; // finished
		}
	}
	
} // End FlipVertical()

/***********************************************************************/

void Transpose(int image[MAXROWS][MAXCOLS])

{
	
	for (int row = 0; row < MAXROWS; row++)
	{
		for(int col = 0; col < MAXCOLS; col++)
		{
			int NEWmatrix = image[row][col];  // assign a new matrix to edit
			image[row][col] = image[col][row]; // assigning
			image[col][row] = NEWmatrix; // finished
		}
		
	}
	
} // End Transpose()

/***********************************************************************/

void RotateCW(int image[MAXROWS][MAXCOLS])

{

	for (int row = 0; row < MAXROWS / 2; row++)
	{
		for (int col = 0; col < MAXCOLS - row - 1; col++)
		{
			int NEWmatrix = image[row][col];  // assign a new matrix to edit
			image[row][col] = image[MAXCOLS - 1 - col][row];
			image[MAXCOLS - 1 - col][row] = image[MAXROWS - 1 - row][MAXCOLS - 1 - col]; // assigning
			image[MAXROWS - 1 - row][MAXCOLS - 1 - col] = image[col][MAXROWS - 1 - row]; // assigning
			image[col][MAXROWS - 1 - row] = NEWmatrix; // finished
		}
	}

} // End RotateCW()

/***********************************************************************/

void RotateCCW(int image[MAXROWS][MAXCOLS])

{

	for (int row = 0; row < MAXROWS / 2; row++)
	{
		for (int col = 0; col < MAXCOLS - row - 1; col++)
		{
			int NEWmatrix = image[row][col];  // assign a new matrix to edit
			image[row][col] = image[col][MAXROWS - 1 - row];
			image[col][MAXROWS - 1 - row] = image[MAXROWS - 1 - row][MAXCOLS - 1 - col]; // assigning
			image[MAXROWS - 1 - row][MAXCOLS - 1 - col] = image[MAXCOLS - col - 1][row]; // assigning
			image[MAXCOLS - col - 1][row] = NEWmatrix; // finished
		}
	}
	
} // End RotateCCW()

/***********************************************************************/


