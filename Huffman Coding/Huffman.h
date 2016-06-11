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
	string bitVal;
	string left;
	string right;
	string father;
	bool topLayer;

};

struct character
{
	string val;
	int count;
};

ifstream textStream;
ofstream outputStream;
string inLines;
string inputText;

int expectedCount;

vector<character> charCountVect;
vector<node> mainTree;
node pinnacleNode;