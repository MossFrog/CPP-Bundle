#include "Huffman.h"

int main()
{
	//mainTree.resize(1000000);
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

		textStream.close();

		//-- Loop throughout the entire text and get every character's count --//

		for (int i = 0; i < inputText.length(); i++)
		{
			bool present = false;

			//-- Parse through the Character Count Vector and search for a Match --//
			for (int j = 0; j < charCountVect.size(); j++)
			{
				if (charCountVect[j].val[0] == inputText[i])
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


		expectedCount = charCountVect.size();


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
			newNode.left = "";
			newNode.right = "";
			newNode.father = "";
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

			int tindexOne;
			int tindexTwo;

			//-- Retrieve minOne and minTwo's indeces in the main tree Vector --//
			for (int i = 0; i < mainTree.size(); i++)
			{
				if (mainTree[i].charVal == minOne.charVal)
				{
					tindexOne = i;
				}

				else if (mainTree[i].charVal == minTwo.charVal)
				{
					tindexTwo = i;
				}
			}

			//-- Debugging Section --//
			/*
			cout << minOne.charVal << " " << minOne.numVal << endl;
			cout << minTwo.charVal << " " << minTwo.numVal << endl;
			cin.ignore();
			*/

			//-- Merge the two minima togeather and update both the tree and the Vector. --//

			node combinedNode;
			combinedNode.charVal = minTwo.charVal + minOne.charVal;
			combinedNode.numVal = minOne.numVal + minTwo.numVal;
			combinedNode.father = "";
			combinedNode.left = mainTree[tindexTwo].charVal;
			combinedNode.right = mainTree[tindexOne].charVal;
			combinedNode.topLayer = true;
			pinnacleNode = combinedNode;

			//-- Push the combined node to the tree and the character count Vector --//
			mainTree.push_back(combinedNode);

			character tempChar;
			tempChar.val = combinedNode.charVal;
			tempChar.count = combinedNode.numVal;
			charCountVect.push_back(tempChar);


			//-- Update the father values --//

			mainTree[tindexOne].father = combinedNode.charVal;
			mainTree[tindexTwo].father = combinedNode.charVal;

		}

		
		//-- Debugging Section --//
		/*
		cout << mainTree[0].charVal << endl;
		cout << mainTree[0].father << endl;
		cin.ignore();*/

		//-- Update all the values in the decode vector according to the mainTree --//

		for (int i = 0; i < mainTree.size(); i++)
		{
			//-- If the value is an end branch --//
			if (mainTree[i].charVal.length() == 1)
			{
				node tempNode;
				tempNode = mainTree[i];
				int fatherIndex;
				while (tempNode.father != "")
				{
					//-- Locate the father --//
					for (int j = 0; j < mainTree.size(); j++)
					{
						if (tempNode.father == mainTree[j].charVal)
						{
							fatherIndex = j;

							if (tempNode.charVal == mainTree[j].left)
							{
								mainTree[i].bitVal = "0" + mainTree[i].bitVal;
							}

							else
							{
								mainTree[i].bitVal = "1" + mainTree[i].bitVal;
							}
						}
					}

					//-- Update tempnode --//
					tempNode = mainTree[fatherIndex];
				}
			}
		}

		string keyStr = "";
		
		for (int i = 0; i < mainTree.size(); i++)
		{
			//-- If the value is an end branch --//
			if (mainTree[i].charVal.length() == 1)
			{
				//-- Uncomment this section to see each character's encoding --//
				//cout << mainTree[i].charVal << " " << mainTree[i].bitVal << endl;

				keyStr = keyStr + mainTree[i].charVal + ": " + mainTree[i].bitVal + '\n';
			}
		}
		

		//-- Encode the whole text and also save the key to another folder --//

		string encodedOutput = "";

		for (int i = 0; i < inputText.length(); i++)
		{
			int decodeIndex = 0;
			//-- Find the encoded character representation --//
			while ((inputText[i] != mainTree[decodeIndex].charVal[0]) || (mainTree[decodeIndex].bitVal.length() == 0))
			{
				decodeIndex++;
			}

			//-- Uncomment this section to see step by step encoding process --//
			/*
			cin.ignore();
			cout << inputText[i] << ": " << mainTree[decodeIndex].bitVal << endl;
			*/

			encodedOutput += mainTree[decodeIndex].bitVal;
		}


		//-- Output both texts --//
		cout << endl << "-- Original Text --" << endl << endl;
		cout << inputText << endl;
		cout << endl;

		cin.ignore();

		cout << endl << "-- Encoded Text --" << endl << endl;
		cout << encodedOutput << endl;
		cout << endl;

		//-- Dump the key and the text to an output file --//
		outputStream.open("EncodedOutput.txt");
		outputStream << encodedOutput;
		outputStream.close();

		outputStream.open("Key.txt");
		outputStream << keyStr;
		outputStream.close();
		

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