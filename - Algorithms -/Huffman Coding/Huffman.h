#include <nfd.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "strutils.h"

struct node
{
	string charVal;
	int numVal;
	node * left;
	node * right;
	node * father;
	bool topLayer;
};

struct character
{
	char val;
	int count;
};

struct binaryChar
{
	string bitString;
	char charVal;
};

ifstream textStream;
string inLines;
string inputText;


vector<character> charCountVect;
vector<binaryChar> decodeVector;
vector<node> mainTree;
node pinnacleNode;