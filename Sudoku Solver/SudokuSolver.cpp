#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>

using namespace std;

//-- This C++ code is a simple console application that takes an input text file (Namely a Sudoku Puzzle) and solves it using a backtracking method. --//

//-- Method for padding 2-D Empty Vectors With Zeroes --//
void padZeroes(int width, int height, vector<vector<int>> & inputVect);

//-- Function that outputs a Sudoku Grid to the console --//
void printSudoku(vector<vector<int>> & outVect);

//-- Methods for checking if the given value "val" is present within the row, column or sector of the puzzle --//
bool isRowCompatible(vector<vector<int>> & sudokuPuzzle, int val, int row);
bool isColCompatible(vector<vector<int>> & sudokuPuzzle, int val, int col);
bool isSectorCompatible(vector<vector<int>> & sudokuPuzzle, int val, int row, int col);

//-- Checks if there are any Zeroes left in the Puzzle --//
bool nullCheck(vector<vector<int>> & sudokuPuzzle);

//-- Recursive method for solving the Sudoku Puzzle --//
bool solvePuzzle(vector<vector<int>> sudokuPuzzle);

int main()
{
	vector<vector<int>> sudokuPuzzle;
	padZeroes(9, 9, sudokuPuzzle);

	//-- Open an input file stream to fill the Sudoku puzzle with values --//
	ifstream inFile;
	string puzzleStr;
	string inputLines;

	inFile.open("InputPuzzle.txt");
	while (getline(inFile, inputLines))
	{
		puzzleStr += inputLines;
	}
	inFile.close();

	//-- Loop through the data string and update all the values --//
	for (int i = 0; i < puzzleStr.length(); i++)
	{
		//-- Convert the Decimal ASCII value to an integer --//
		sudokuPuzzle[ceil(i / 9)][i % 9] = int(puzzleStr[i]) - 48;
	}

	//-- Create a copy of the original Puzzle for preservation Purposes --//
	vector<vector<int>> savedPuzzle = sudokuPuzzle;

	
	cout << "This is a basic program that can be utilized to solve 9x9 Sudoku Puzzles. Input is Via .txt Files." << endl << endl;
	cout << "-- Below is the Original Grid --" << endl;
	//-- Display the puzzle --//
	printSudoku(sudokuPuzzle);

	cout << endl << endl;
	cout << "-- Below is the Solution Grid --" << endl;

	//-- Display the solution --//
	solvePuzzle(sudokuPuzzle);

	cin.ignore();
	return 0;
}



void padZeroes(int width, int height, vector<vector<int>> & inputVect)
{
	for (int i = 0; i < height; i++)
	{
		vector<int> emptyVect;
		inputVect.push_back(emptyVect);

		for (int j = 0; j < width; j++)
		{
			inputVect[i].push_back(0);
		}
	}
}

void printSudoku(vector<vector<int>> & outVect)
{
	for (int i = 0; i < outVect.size(); i++)
	{
		if (ceil(i / 3.0) == (i / 3.0))
		{
			cout << endl;
		}


		for (int j = 0; j < outVect[i].size(); j++)
		{

			if (ceil(j / 3.0) == (j / 3.0))
			{
				cout << " ";
			}
			cout << outVect[i][j] << " ";
		}

		cout << endl;
	}
}

bool isRowCompatible(vector<vector<int>> & sudokuPuzzle, int val, int row)
{
	for (int i = 0; i < 9; i++)
	{
		if (val == sudokuPuzzle[row][i])
		{
			return false;
		}
	}
	return true;
}

bool isColCompatible(vector<vector<int>> & sudokuPuzzle, int val, int col)
{
	for (int i = 0; i < 9; i++)
	{
		if (val == sudokuPuzzle[i][col])
		{
			return false;
		}
	}
	return true;
}

bool isSectorCompatible(vector<vector<int>> & sudokuPuzzle, int val, int row, int col)
{
	//-- Determine which 3x3 Sector the cell being tested is. --//
	row = floor(row / 3)*3;
	col = floor(col / 3)*3;

	//-- Check each value for a match. --//
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (val == sudokuPuzzle[i + row][j + col])
			{
				return false;
			}
		}
	}
	

	//-- If no equal value is found the value is compatible with the sector. --//
	return true;
}

bool nullCheck(vector<vector<int>> & sudokuPuzzle)
{
	//-- Loop through the whole Puzzle Searchin for a zero. --//
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudokuPuzzle[i][j] == 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool solvePuzzle(vector<vector<int>> sudokuPuzzle)
{
	//-- Begin solving using the backtracking method --//
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			//-- Check if the given cell is empty --//
			if (sudokuPuzzle[i][j] == 0)
			{
				//-- Assign a valid value and then recall the solve puzzle method --//
				for (int x = 1; x <= 9; x++)
				{
					//-- Check if the value is valid --//
					if (isSectorCompatible(sudokuPuzzle, x, i, j) && isRowCompatible(sudokuPuzzle, x, i) && isColCompatible(sudokuPuzzle, x, j))
					{
						sudokuPuzzle[i][j] = x;
						//printSudoku(sudokuPuzzle);
						//cin.ignore();


						//-- See if the puzzle is complete --//
						if (nullCheck(sudokuPuzzle))
						{
							printSudoku(sudokuPuzzle);
							return true;
						}

						else
						{
							solvePuzzle(sudokuPuzzle);
						}
					}
				}

				//-- Back track to the previous value after all nine possible Digits are tested. --//
				return false;
			}
		}
	}
}