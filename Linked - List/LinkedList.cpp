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

void LinkedList::Clear()
{
	//-- Temporary pointer for parsing --//
	NodePtr tempPtr = dummyHead;

	//-- Parse to the end of the list --//
	while(tempPtr -> next != NULL)
	{
		tempPtr = tempPtr->next;
	}

	//-- Work our way back deleting all the nodes one by one --//
	while(tempPtr -> prev != NULL)
	{
		tempPtr = tempPtr -> prev;
		delete tempPtr -> next;
	}
}

int LinkedList::returnSize()
{
	//-- Temporary pointer for parsing --//
	NodePtr tempPtr = dummyHead;

	//-- Counter for storing node count --//
	int count = 0;

	//-- Parse to the end of the list --//
	while(tempPtr -> next != NULL)
	{
		tempPtr = tempPtr->next;
		count++;
	}

	return count;
}

