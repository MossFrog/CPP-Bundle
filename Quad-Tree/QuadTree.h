#ifndef QUADTREE_H_
#define QUADTREE_H_
typedef struct quadTree *treePtr;
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
	
	//-- Declare child Branches --//
	quadTree * childAlpha;
	quadTree * childBeta;
	quadTree * childDelta;
	quadTree * childGamma;

	//-- Constructor for the QuadTree --//
	QuadTree()
	{
		//-- Set all the fringes to NULL --//
		childAlpha = NULL;
		childBeta = NULL;
		childDelta = NULL;
		childGamma = NULL;
	}


	//-- Member Functions --//

	//-- Creates new fringe nodes. --//
	void branchNode();

	//-- Finds the element in the tree --//
	void findNode();

};


#endif