#ifndef _TREE_
#define _TREE_

#include <iostream>
#include <string>
#include <cstdlib>
#include "TreeNode.h"
#include "DRT.h"
#include "Database.h"
using namespace std;

class DRT;
class TreeNode;
class Database;
class Tree : public Database {
private:
	TreeNode* root;
public:
	Tree(); //constructor
	~Tree(); //destructor
	DRT* add(string key, string data); //very similar to sample code
	void setroot(TreeNode* r); //get method
	DRT* searchnode(string key); //searches the tree for the given key
	string first(); //first key in the tree (left all the way down)
	string last(); //last key in the tree (right all the way down)
	DRT* remove(string key); //removes an item from the list
	DRT* search(string key); //Database search method
	  //checks to see if we're searching on the empty string, if so builds a DRT with first() and last (), otherwise calls searchnode
	DRT* modify(string key, string data); //Database modify method
};

#endif