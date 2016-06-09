#include "Huffman.h"

int main()
{
	cout << "Please select and Input file." << endl;

	nfdchar_t *outPath = NULL;
	nfdresult_t result = NFD_OpenDialog("txt", NULL, &outPath);

	if (outPath != NULL && outPath != "")
	{
		//-- Push the contents of the text file to a string variable --//
		textStream.open(outPath);
		while (getline(textStream, inLines))
		{
			inputText += inLines + '\n';
		}


		//-- Loop throughout the entire text and get every character's count --//

		for (int i = 0; i < inputText.length(); i++)
		{
			bool present = false;

			//-- Parse through the Character Count Vector and search for a Match --//
			for (int j = 0; j < charCountVect.size(); j++)
			{
				if (charCountVect[j].val == inputText[i])
				{
					//-- If the character is present increment the character count --//
					present = true;
					charCountVect[j].count++;
				}
			}

			//-- If a new character is encountered then add it to the Character Count Vector --//
			if (!present)
			{
				character newChar;
				newChar.val = inputText[i];
				newChar.count = 1;

				charCountVect.push_back(newChar);
			}
		}

		//-- Inefficiently sort the contents of the Character Count Vector --//

		for (int i = 0; i < charCountVect.size(); i++)
		{
			for (int j = 0; j < charCountVect.size(); j++)
			{
				if (charCountVect[i].count < charCountVect[j].count)
				{
					swap(charCountVect[i], charCountVect[j]);
				}
			}
		}


		//-- Debugging section --//
		/*
		for (int i = 0; i < charCountVect.size(); i++)
		{
			cout << charCountVect[i].val << ": " << charCountVect[i].count << endl;
		}
		*/

		//-- Create the base of the tree --//

		for (int i = 0; i < charCountVect.size(); i++)
		{
			node newNode;
			newNode.charVal += charCountVect[i].val;
			newNode.numVal = charCountVect[i].count;
			newNode.left = NULL;
			newNode.right = NULL;
			newNode.topLayer = true;
			mainTree.push_back(newNode);
			pinnacleNode = newNode;
		}


		//-- Continue constructing the tree upon the base --//
		while (pinnacleNode.charVal.length() < charCountVect.size())
		{
			node minOne;
			node minTwo;

			minOne.numVal = INT_MAX;
			minTwo.numVal = INT_MAX;


			//-- Locate two arbitrary minimum nodes. --//
			for (int i = 0; i < mainTree.size(); i++)
			{
				if (mainTree[i].numVal < minOne.numVal)
				{
					if (mainTree[i].topLayer == true)
					{
						minOne = mainTree[i];
					}
				}
			}

			for (int i = 0; i < mainTree.size(); i++)
			{
				if (mainTree[i].numVal < minTwo.numVal)
				{
					if (mainTree[i].topLayer == true)
					{
						if (mainTree[i].charVal != minOne.charVal)
						{
							minTwo = mainTree[i];
						}
					}
				}
			}

			//-- After locating the two minima merge them to form a new node and adjust the Top Layer --//

			/* -- Debugging Section --
			cout << minOne.charVal << ": " << minOne.numVal;
			cout << minTwo.charVal << ": " << minTwo.numVal;
			cin.ignore();
			*/

			node * tempLeft = NULL;
			node * tempRight = NULL;

			for (int i = 0; i < mainTree.size(); i++)
			{
				if (mainTree[i].charVal == minOne.charVal)
				{
					mainTree[i].topLayer = false;
					tempRight = &(mainTree[i]);
				}

				if (mainTree[i].charVal == minTwo.charVal)
				{
					mainTree[i].topLayer = false;
					tempLeft = &(mainTree[i]);
				}
			}

			node newMerged;
			newMerged.charVal = "";
			newMerged.charVal += minTwo.charVal;
			newMerged.charVal += minOne.charVal;
			newMerged.topLayer = true;
			newMerged.left = tempLeft;
			newMerged.right = tempRight;
			newMerged.father = NULL;
			newMerged.numVal = minOne.numVal + minTwo.numVal;

			mainTree.push_back(newMerged);
			pinnacleNode = newMerged;


			//-- Adjust the Father Pointer --//
			for (int i = 0; i < mainTree.size(); i++)
			{
				if (mainTree[i].charVal == minOne.charVal)
				{
					mainTree[i].father = &(mainTree[mainTree.size() - 1]);
				}

				if (mainTree[i].charVal == minTwo.charVal)
				{
					mainTree[i].father = &(mainTree[mainTree.size() - 1]);
				}
			}
		}


		//-- Debugging section --//
		/*
		for (int i = 0; i < mainTree.size(); i++)
		{
			if (mainTree[i].topLayer == true)
			{
				cout << mainTree[i].charVal << endl;
			}
		}

		cout << pinnacleNode.charVal << endl;
		*/

		//-- Perform a Post order Depth First Search to get the Binary Character encodings --//

		while (decodeVector.size() < charCountVect.size())
		{
			for (int i = 0; i < mainTree.size(); i++)
			{

			}

		}
		

		cout << endl << "-- Original Text --" << endl << endl;
		cout << inputText << endl;
		cout << endl;

	}

	else
	{
		cout << "You did not select a valid file" << endl;
		cout << endl; 
	}

	cout << "--- Ending Program ---" << endl;
	cin.ignore();
	return 0;
}