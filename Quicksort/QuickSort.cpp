#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void quickSort(vector<int> & unsortedVector);

int main()
{
	//-- This section is merely a demonstration of the algorithm, any data can be given to the vector as long as it is comparable. --//
	vector<int> mainVector;
	mainVector.push_back(3);
	mainVector.push_back(5);
	mainVector.push_back(1);
	mainVector.push_back(10);
	mainVector.push_back(1);

	quickSort(mainVector);
	for (int i = 0; i <= mainVector.size() - 1; i++)
	{
		cout << mainVector[i] << endl;
	}

	//-- Pause Terminal and end. --//
	cin.get();
	return 0;
}

void quickSort(vector<int> & unsortedVector)
{
	//-- Subvector - 1 and Subvector - 2 are the partitions --//
	vector<int> subVector_1;
	vector<int> subVector_2;

	vector<int> resultVector;

	for (int i = 0; i < unsortedVector.size() - 1; i++)
	{
		if (unsortedVector[i] <= unsortedVector[unsortedVector.size() - 1])
		{
			subVector_1.push_back(unsortedVector[i]);
		}

		else
		{
			subVector_2.push_back(unsortedVector[i]);
		}
	}


	//-- Recursively call the method depending on the size of the Subvectors --//

	if (subVector_1.size() > 1)
	{
		quickSort(subVector_1);
	}

	if (subVector_2.size() > 1)
	{
		quickSort(subVector_2);
	}

	for (int i = 0; i < subVector_1.size(); i++)
	{
		resultVector.push_back(subVector_1[i]);
	}

	resultVector.push_back(unsortedVector[unsortedVector.size() - 1]);

	for (int i = 0; i < subVector_2.size(); i++)
	{
		resultVector.push_back(subVector_2[i]);
	}

	unsortedVector = resultVector;
}