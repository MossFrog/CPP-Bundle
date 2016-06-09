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
			newNode.father = NULL;
			newNode.topLayer = true;
			mainTree.push_back(newNode);
			pinnacleNode = newNode;
		}


		//-- Continue constructing the tree upon the base removing combined Nodes. --//
		while (charCountVect.size() > 1)
		{
			//-- Select Two Arbitrary Minima --//
			node minOne;
			node minTwo;
			int indexOne;
			int indexTwo;

			minOne.numVal = INT_MAX;
			minTwo.numVal = INT_MAX;

			//-- Remove minima one from the value array after discovery --//
			for (int i = 0; i < charCountVect.size(); i++)
			{
				if (charCountVect[i].count < minOne.numVal)
				{
					minOne.charVal = charCountVect[i].val;
					minOne.numVal = charCountVect[i].count;
					indexOne = i;
				}
			}

			charCountVect.erase(charCountVect.begin() + indexOne);

			//-- Do the same for minima two --//
			for (int i = 0; i < charCountVect.size(); i++)
			{
				if (charCountVect[i].count < minTwo.numVal)
				{
					minTwo.charVal = charCountVect[i].val;
					minTwo.numVal = charCountVect[i].count;
					indexTwo = i;
				}
			}

			charCountVect.erase(charCountVect.begin() + indexTwo);

			cout << minOne.charVal << " " << minOne.numVal << endl;
			cout << minTwo.charVal << " " << minTwo.numVal << endl;

			//-- Merge the two minima togeather and update both the tree and the vector. --//



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