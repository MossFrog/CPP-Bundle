#ifndef QUADTREE_H_
#define QUADTREE_H_
typedef struct QuadTree *nodePtr;
#include <iostream>
#include <string>

using namespace std;

//-- Struct for the data stored in the nodes --//
struct Data
{
	int someInteger;
	string someData;
	bool someBool;
};


class QuadTree
{
private:
	

public:
	Data nodeData;
	string ID;

	//-- Declare child Branches --//
	QuadTree * childAlpha;
	QuadTree * childBeta;
	QuadTree * childDelta;
	QuadTree * childGamma;

	//-- Constructor for the QuadTree --//
	QuadTree()
	{
		//-- R determines that this is the Root of the QuadTree --//
		ID = "R";

		//-- Set all the fringes to NULL --//
		childAlpha = NULL;
		childBeta = NULL;
		childDelta = NULL;
		childGamma = NULL;
	}


	//-- Member Functions --//

	//-- Creates new fringe nodes. --//
	void branchNode();

	//-- Finds the element in the tree with the given ID and returns its Data --//
	Data findNode(string ID);

};


#endif