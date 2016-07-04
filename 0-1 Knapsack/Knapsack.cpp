#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

//-- This simple program calculates the optimum loot for a given capacity backpack and spectrum of items --//
//-- Items can be added below programatically and the solution is scalable and dynamic --//

//-- Method for padding 2-D Empty Vectors With Zeroes --//
void padZeroes(int width, int height, vector<vector<int>> & inputVect);

//-- Function that outputs a 2-D integer Vector to the console --//
void printVector(vector<vector<int>> & outVect);

int main()
{
	//-- Structure for storing item information --//
	struct item
	{
		int volume;
		int value;
		string name;
	};

	//-- Vector for storing the resulting pack --//
	vector<item> resultVector;

	//-- Items can be added in this section --//
	item statue;
	statue.name = "Statue";
	statue.value = 4;
	statue.volume = 3;

	item copper;
	copper.name = "Copper Coin";
	copper.value = 1;
	copper.volume = 1;

	item keyboard;
	keyboard.name = "Vintage Keyboard";
	keyboard.value = 2;
	keyboard.volume = 2;

	item steel;
	steel.name = "Steel Bar";
	steel.value = 5;
	steel.volume = 5;

	vector<item> lootVector;
	lootVector.push_back(steel);
	lootVector.push_back(statue);
	lootVector.push_back(keyboard);
	lootVector.push_back(copper);
	
	//-- Backpack Capacity Can be altered here --//
	int packCapacity = 5;

	//-- Two Vectors are used to dynamically calculate the optimum result for the given items array --//
	vector<vector<int>> ValueArray;
	vector<vector<int>> KeepArray;

	//-- Pad both arrays with zeroes --//
	padZeroes(packCapacity, lootVector.size() + 1, ValueArray);
	padZeroes(packCapacity, lootVector.size() + 1, KeepArray);

	//-- Make sure the lootVector is sorted! --//
	//-- Currently the items are sorted prior , if not a sorting algorithm is required. --//
	

	//-- Skip the first rows of the Vectors --//
	//-- Beging dynamically constructing the Solutions --//
	for (int i = 1; i < ValueArray.size(); i++)
	{
		for (int j = 0; j < ValueArray[0].size(); j++)
		{

			//-- Begin by checking if the current item fits inside the knapsack --//
			if (lootVector[i - 1].volume <= j + 1)
			{
				//-- Checkval is the value which will be compared to the previous solution at the same volume --//
				int checkVal = lootVector[i - 1].value;

				//-- If it fits check if there is any remaining space --//
				if ((j + 1) - (lootVector[i - 1].volume) > 0)
				{
					//-- Claculate if there is any additional value that can be added to the knapsack --//
					//-- Look at the above row at the remaining volume's index --//
					int remainingVolume = (j + 1) - (lootVector[i - 1].volume);
					checkVal += ValueArray[i - 1][remainingVolume - 1];
				}

				//-- Compare Checkval and the previous value --//
				if (checkVal > ValueArray[i - 1][j])
				{
					KeepArray[i][j] = 1;
					ValueArray[i][j] = checkVal;
				}

				else
				{
					ValueArray[i][j] = ValueArray[i-1][j];
				}
			}

			else
			{
				//-- The keep vector is not updated --//
			}
		}
	}


	//-- Uncomment this Section to see the Solution Vectors --//
	
	/*
	printVector(KeepArray);
	cout << endl;
	printVector(ValueArray);
	cin.ignore();
	*/

	//-- Analyze the Solution Vector to obtain the Optimum Combination --//
	int currentItem = lootVector.size();
	int temporaryCapacity = packCapacity;

	while (currentItem > 0)
	{
		if (KeepArray[currentItem][temporaryCapacity - 1] == 1)
		{
			//-- Uncomment this section to see the decision making process --//
			//cout << "Keeping item: " << lootVector[currentItem - 1].name << endl;

			//-- Store the result in the result Vector --//
			resultVector.push_back(lootVector[currentItem - 1]);

			//-- Decrease the remaining capacity --//
			temporaryCapacity = temporaryCapacity - lootVector[currentItem].volume;
		}

		//-- Check the next item --//
		currentItem--;
	}
	

	//-- Standard output jargon --//
	cout << "This is a simple C++ implementation of the 0/1 Knapsack problem." << endl << endl;
	cout << "The items to be tested are..." << endl << endl;

	for (int i = 0; i < lootVector.size(); i++)
	{
		cout << "Item - " << i << ": " << lootVector[i].name << endl;
		cout << "Value: " << lootVector[i].value << endl;
		cout << "Volume: " << lootVector[i].volume << endl;
		cout << endl;
	}


	//-- Make the user wait a bit because why not --//
	cout << "-- The Knapsack Capacity is " << packCapacity << " Units --" << endl;
	cout << "Please wait while the program calculates a result";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	cout << endl << endl;

	cout << "Items to be kept are:";

	//-- Output the result --//
	for (int i = 0; i < resultVector.size(); i++)
	{
		cout << endl;
		cout << "Item - " << i << ": " << resultVector[i].name << endl;
		cout << "Value: " << resultVector[i].value << endl;
		cout << "Volume: " << resultVector[i].volume << endl;
	}


	//-- Pause the console --//
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