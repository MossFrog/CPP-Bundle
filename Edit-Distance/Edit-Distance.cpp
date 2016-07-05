#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

//-- This simple program calculates the edit distance between two input strings. --//

//-- Method for padding 2-D Empty Vectors With Zeroes --//
void padZeroes(int width, int height, vector<vector<int>> & inputVect);

//-- Function that outputs a 2-D integer Vector to the console --//
void printVector(vector<vector<int>> & outVect);


int main()
{

	//-- Declarations Section --//
	string iStringOne;
	string iStringTwo;

	//-- Main solution 2-D vector --//
	vector<vector<int>> solutionVector;


	//--------------------------//

	cout << endl;
	cout << "This simple console based program calculates the edit distance between two input strings." << endl;
	cout << endl;

	//-- Retrieve the two input strings from the user --//
	cout << "Please enter string one: ";
	cin >> iStringOne;

	cout << "Please enter string two: ";
	cin >> iStringTwo;


	//-- Pad the solution vector with an appropriate number of zeroes --//
	padZeroes(iStringOne.length() + 1, iStringTwo.length() + 1, solutionVector);

	//-- Begin constructing the solution --//

	//-- Fill in the first line and column with the necessary values --//
	for (int i = 0; i < solutionVector[0].size(); i++)
	{
		solutionVector[0][i] = i;
	}

	for (int i = 0; i < solutionVector.size(); i++)
	{
		solutionVector[i][0] = i;
	}


	//-- Conbstruct the rest of the values derived from the first row and column --//

	for (int i = 1; i < solutionVector.size(); i++)
	{
		for (int j = 1; j < solutionVector[0].size(); j++)
		{
			//-- Check the adjacent values top determine the minimum --//
			int minVal = INT_MAX;

			minVal = min(solutionVector[i - 1][j], minVal);
			minVal = min(solutionVector[i][j - 1], minVal);
			minVal = min(solutionVector[i - 1][j - 1], minVal);

			//-- Determine if the said characters are the same --//
			if (iStringOne[j - 1] == iStringTwo[i - 1])
			{
				//-- Retrieve the previous diagonal Value --//
				minVal = solutionVector[i - 1][j - 1];
			}
			
			else
			{
				minVal += 1;
			}

			//-- Write the value of the minVal to the solution Vector --//

			solutionVector[i][j] = minVal;
		}
	}



	cout << endl << "The Solution vector is..." << endl;
	cout << endl;
	printVector(solutionVector);

	cout << endl << "The Edit Distance is : " << solutionVector[solutionVector.size() - 1][solutionVector[0].size() - 1];

	//-- Pause the console until further input --//
	cout << endl << "Press any key to exit the program...";
	cin.get();
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

void printVector(vector<vector<int>> & outVect)
{
	for (int i = 0; i < outVect.size(); i++)
	{
		for (int j = 0; j < outVect[i].size(); j++)
		{
			cout << outVect[i][j] << " ";
		}

		cout << endl;
	}
}