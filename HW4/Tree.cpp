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
	if (root) {
		return root->searchnode(key, "", "");
	}else{
		return new DRT("","","");
	}
	
}

string Tree::first() {
	//left all the way down
	return root->first()->getk();
}

string Tree::last() { //last key in the tree (right all the way down)
	return root->last()->getk();

}

DRT* Tree::remove(string key) { //removes an item from the list
	return root->remove(key,"","");

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