#include <iostream>
#include <string>
#include <cstdlib>
#include "TreeNode.h"
#include "DRT.h"
using namespace std;

TreeNode::TreeNode(string key, string data, TreeNode* l, TreeNode* r, TreeNode* p, Tree* T) {

	k = key; d = data; left = l; right = r; parent = p; t = T;
}

TreeNode::~TreeNode() { //destructor

	delete left;
	delete right;
}

DRT* TreeNode::add(string key, string data, string n, string p) {
	if (k == key) {
		d = data;
		string next;
		string prev;
		if (!right)
			next = n;
		else next = right->first()->getk();
		if (!left)
			prev = p;
		else prev = left->last()->getk();
		return new DRT(data, next, prev);
		/*d = data;
		return new DRT(data, n, p);*/
	}
	if (k < key) {
		if (right) {
			return right->add(key, data, n, k);
		}
		else {
			right = new TreeNode(key, data, NULL, NULL, NULL, t);
			return new DRT("", n, k);
		}

	}
	if (left) {
		return left->add(key, data, k, p);
	}
	else {
		left = new TreeNode(key, data, NULL, NULL, NULL, t);
		return new DRT("", k, p);
	}
		
	

}

DRT* TreeNode::searchnode(string key, string n, string p) {
	if (k == key) {
		string next, prev;
		if (!right) next = n;
		else next = right->first()->getk();
		if (!left) prev = p;
		else prev = left->last()->getk();
		return new DRT(d, next, prev);
	}
	if (k < key) {
		if (right) return right->searchnode(key, n, k); //k is now the psf
		return new DRT("", n, k);
	}
	if (left) return left->searchnode(key, k, p);
	return new DRT("", k, p);

}
TreeNode* TreeNode::first() {//left all the down
	if (left) {
		return left->first();
	}
	else {
		return this;
	}


}

TreeNode* TreeNode::last() { //right all the way down
	if (right) {
		return right->last();
	}
	else {
		return this;
	}

}

string TreeNode::getk() { return k; }
string TreeNode::getd() { return d; }
TreeNode* TreeNode::getright() { return right; }
TreeNode* TreeNode::getleft() { return left; }

//NOT DONE
string TreeNode::next() { return ""; }
string TreeNode::prev() { return ""; }

DRT* TreeNode::remove(string key, string n, string p) {
	if (this->k == key) {
		DRT* tempD = new DRT(this->getd(), n, p);
		this->remove();
		return tempD;
		
	}
	else {
		if (k < key) {
			if (right) {
				return right->remove(key, n, k);
				//k is now the psf
			}
			else {
				return new DRT("", n, k);
			}
		}
		if (left) return left->remove(key, n, p);
		return new DRT("", k, p);
	}
	//NOT DONE !
	//similar to search; keeps track of nsf and psf
	 //just works its down to the tree to find the node to remove
	 //then calls remove ()




}

void TreeNode::remove() {
	//the physical removal (decides whether it's 0, 1, or 2-child case and possibly copies key and data values and physically removes the deleted node

	// 0 child case
	if (!left && !right) {
		delete this;
	}
	//one child case
	else if (left != NULL && right == NULL || right != NULL && left == NULL) {
		//if node to be deleted is left child of parent
		if (parent->getleft() == this) {
			//set my single child as left node of my parent
			if (left) {
				left->setparent(parent);
				parent->setleft(left);

			}
			else {
				right->setparent(parent);
				parent->setleft(right);
			}
		}
	}
	//2 child case
	else if (left && right) {
		// go right once, then left all the way down to find next node
		//then copy all info from next node into "this" node (the one to be deleted)
		TreeNode* next = right->first();
		k = next->getk();
		d = next->getd();
		left = next->getleft();
		right = next->getright();
		next->remove();
	}

}

void TreeNode::setparent(TreeNode* p) { parent = p; }
void TreeNode::setleft(TreeNode* l) { left = l; }
void TreeNode::setright(TreeNode* r) { right = r; }