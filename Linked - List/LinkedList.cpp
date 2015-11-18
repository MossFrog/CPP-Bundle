#include "LinkedList.h";

void LinkedList::Append(Data nodeInfo)
{
	NodePtr newNode = new Node();
	newNode->next = NULL;
	newNode->nodeData = nodeInfo;

	//-- Create a temporary pointer --//

	NodePtr tempPtr = dummyHead;
	
	//-- Parse to the end of the linked list --//
	while(tempPtr -> next != NULL)
	{
		tempPtr = tempPtr->next;
	}

	//-- set the newNode's prev to the temporary pointer and the last element's next to the new node --//
	newNode -> prev = tempPtr;
	tempPtr -> next = newNode;

	//-- Update the ID of the new node --//
	newNode -> ID = newNode -> prev -> ID + 1;
}

Data LinkedList::getData(int ID)
{
	//-- Create a temporary pointer --//

	NodePtr tempPtr = dummyHead;

	//-- Parse through the list until the desired ID is found, then return --//
	while(tempPtr -> next != NULL)
	{
		if(tempPtr -> next -> ID == ID)
		{
			return tempPtr -> next -> nodeData; 
		}
		tempPtr = tempPtr->next;
	}

	cout << "The ID " << ID << " Is not present." << endl;
	return dummyHead->nodeData;
}