#include "Stack.h"

//-- Default Constructor --//
Stack::Stack()
{
	mainStorage = *(new vector<dataCell>);
}

void Stack::push(dataCell newItem)
{
	mainStorage.push_back(newItem);
}

dataCell Stack::pop()
{
	dataCell tempCell = mainStorage[mainStorage.size()-1];
	mainStorage.pop_back();
	return tempCell;
}

int Stack::size()
{
	return mainStorage.size();
}

void Stack::clear()
{
	while(!mainStorage.empty())
	{ mainStorage.pop_back(); }
}

//-- Dump all the contents of the Stack --//
void Stack::dumpRaw()
{
	for(int i = 0; i < mainStorage.size(); i++)
	{ cout << "String Data: " + mainStorage[i].strData << endl << "Integer Data: " << mainStorage[i].intData << endl; }
}