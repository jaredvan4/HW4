#include <iostream>
#include <string>
#include <cstdlib>
#include "Tree.h"
#include "DRT.h"
#include "TreeNode.h"
using namespace std;

Tree::Tree() { root = NULL; }

Tree::~Tree() { delete root; }

void Tree::setroot(TreeNode* r) { root = r; }

DRT* Tree::add(string key, string data) { //very similar to sample code

	if (!root) {
		root = new TreeNode(key, data, NULL, NULL, NULL, this);
		return new DRT("", "", "");
	}
	else {
		return root->add(key, data, "", "");
	}
}

DRT* Tree::searchnode(string key) { //searches the tree for the given key
	//not sure what to do when root is key
	if (root->getk() == key) {
		return new DRT(root->getd(),"","");
	}
	else {
		//if key > root's , go right
		if (key > root->getk()) {
			return root->getright()->searchnode(key, root->getright()->getk(), root->getk());
		}
		//else go left
		else {
			return root->getleft()->searchnode(key, root->getleft()->getk(), root->getk());
		}
	}
}

string Tree::first() {
	//left all the way down 
	return root->getleft()->getk();
}

string Tree::last() { //last key in the tree (right all the way down)
	return root->getright()->getk();

}

DRT* Tree::remove(string key) { //removes an item from the list
	//UNFINISHED!
	search(key);

	return new DRT("", "", "");
}

DRT* Tree::search(string key) { //Database search method
	  //checks to see if we're searching on the empty string, if so builds a DRT with first() and last (), otherwise calls searchnode
	if (key.empty()) {
		return  new DRT(key, first(), last());
	}
	else {
		return searchnode(key);
	}

}


DRT* Tree::modify(string key, string data) { //Database modify method

	if (key == "") return new DRT("", first(), last());
	if (data == "") return remove(key);
	return add(key, data);
}