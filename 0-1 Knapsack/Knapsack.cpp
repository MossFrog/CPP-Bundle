#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

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
	lootVector.push_back(statue);
	lootVector.push_back(copper);
	lootVector.push_back(keyboard);
	lootVector.push_back(steel);

	//-- Backpack Capacity Can be altered here --//
	int packCapacity = 5;

	//-- Two Vectors are used to dynamically calculate the optimum result for the given items array --//
	vector<vector<int>> ValueArray;
	vector<vector<int>> KeepArray;

	//-- Pad both arrays with zeroes --//
	padZeroes(packCapacity, lootVector.size() + 1, ValueArray);
	padZeroes(packCapacity, lootVector.size() + 1, KeepArray);
	

	cin.ignore();

	cout << "This is a simple C++ implementation of the 0/1 Knapsack problem." << endl << endl;
	cout << "The items to be tested are..." << endl << endl;

	for (int i = 0; i < lootVector.size(); i++)
	{
		cout << "Item - " << i << ": " << lootVector[i].name << endl;
		cout << "Value: " << lootVector[i].value << endl;
		cout << "Volume: " << lootVector[i].volume << endl;
		cout << endl;
	}

	cout << "-- The Knapsack Capacity is " << packCapacity << " Units --" << endl;
	cout << "Please wait while the program calculates a result..." << endl;



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