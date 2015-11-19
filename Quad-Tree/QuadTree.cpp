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