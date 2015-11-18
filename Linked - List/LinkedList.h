#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
typedef struct Node *NodePtr;

#include <iostream>
#include <string>

using namespace std;

//-- Struct for the data stored in the nodes --//
struct Data
{
	int intX;
	int intY;
	string someData;
};


class Node
{
public:
	//-- Constructor for the node --//
	Node(){};

	//-- Identification for the node --//
	int ID;

	//-- Data to store for each node here --//
	Data nodeData;

	//-- Pointer to next and prev node --//
	NodePtr next;
	NodePtr prev;

};

class LinkedList
{
private:
	//-- Create the dummy head Node --//
	NodePtr dummyHead;

public:
	//-- Default constructor --//
	LinkedList()
	{
		//-- DummyHead has no data and points to NULL --//
		dummyHead = new Node();
		dummyHead->ID = 0;
		dummyHead->next = NULL;
		dummyHead->prev = NULL;
	}



	//-- Append the Linked List adding a node to the end --//
	void Append(Data nodeInfo);

	//-- Delete all nodes except the dummy header --//
	void Clear();

	//-- Delete the node with the given ID --//
	void Delete(int ID); 

	//-- Retrieve Data from a node with the given ID --//
	Data getData(int ID);

	//-- Set the data of a given node with "ID" --//
	void setData(int ID);

	//-- Returns the length of the linked list excluding the dummy --//
	int returnSize();
};


#endif