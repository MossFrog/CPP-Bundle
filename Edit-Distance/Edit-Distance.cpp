#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
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


	cout << endl;
	printVector(solutionVector);

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