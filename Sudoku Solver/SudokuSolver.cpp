#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>

using namespace std;

//-- This simple program calculates the edit distance between two input strings. --//

//-- Method for padding 2-D Empty Vectors With Zeroes --//
void padZeroes(int width, int height, vector<vector<int>> & inputVect);

//-- Function that outputs a Sudoku Grid to the console --//
void printSudoku(vector<vector<int>> & outVect);


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


	//-- Display the puzzle --//
	printSudoku(sudokuPuzzle);
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