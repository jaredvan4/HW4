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
    return root->add(key, data, "", "");
}

DRT* Tree::searchnode(string key) { //searches the tree for the given key


}

string Tree::first() {

}

string Tree::last() { //last key in the tree (right all the way down)


}

DRT* Tree::remove(string key) { //removes an item from the list


}

DRT* Tree::search(string key) { //Database search method
      //checks to see if we're searching on the empty string, if so builds a DRT with first() and last (), otherwise calls searchnode


}


DRT* Tree::modify(string key, string data) { //Database modify method

    if (key == "") return new DRT("", first(), last());
    if (data == "") return remove(key);
    return add(key, data);
}