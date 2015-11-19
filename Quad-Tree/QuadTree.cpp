#include "QuadTree.h";

void QuadTree::branchNode()
{
	//-- Allocate new QuadTree Objects --//
	childAlpha = new QuadTree;
	childBeta = new QuadTree;
	childDelta = new QuadTree;
	childGamma = new QuadTree;

	//-- Update the Identifications of the nodes --//
	childAlpha ->ID = ID + "1";
	childBeta -> ID = ID + "2";
	childDelta -> ID = ID + "3";
	childGamma -> ID = ID + "4";
}

Data QuadTree::findNode(string Identification)
{
	//-- Nulldata to return if not found --//
	Data nullData;
	nullData.someData = "No such node with ID " + Identification + " present.";

	//-- Is the root, return its data --//
	if(Identification == "R")
	{ return nodeData; }

	//-- Temporary pointer for parsing --//
	nodePtr myPtr;

	//-- First step/path determination --//
	if(Identification[1] == '1')
	{
		if(childAlpha != NULL) { myPtr = childAlpha; }
		else
		{ return nullData; }
	}
	else if(Identification[1] == '2')
	{
		if(childBeta != NULL) { myPtr = childBeta; }
		else
		{ return nullData; }
	}
	else if(Identification[1] == '3')
	{
		if(childDelta != NULL) { myPtr = childDelta; }
		else
		{ return nullData; }
	}
	else if(Identification[1] == '4')
	{
		if(childGamma != NULL) { myPtr = childGamma; }
		else
		{ return nullData; }
	}
	else
	{ return nullData; }

	//-- Parse till the given node is discovered --//
	for(int i = 2; i < Identification.length(); i++)
	{
		if(Identification[1] == '1')
		{
			if(myPtr -> childAlpha != NULL) { myPtr = childAlpha; }
			else
			{ return nullData; }
		}
		else if(Identification[1] == '2')
		{
			if(myPtr -> childBeta != NULL) { myPtr = childBeta; }
			else
			{ return nullData; }
		}
		else if(Identification[1] == '3')
		{
			if(myPtr -> childDelta != NULL) { myPtr = childDelta; }
			else
			{ return nullData; }
		}
		else if(Identification[1] == '4')
		{
			if(myPtr -> childGamma != NULL) { myPtr = childGamma; }
			else
			{ return nullData; }
		}

		else
		{ return nullData; }

	}

	//-- Parsed through tree, found the node with the given data. --//
	return myPtr -> nodeData;
}