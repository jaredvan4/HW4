// contains all the function def for all included in TreeNode.h
//Jared VanEnkevort
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
//adds a node to the tree and return a DRT
DRT* TreeNode::add(string key, string data, string n, string p) {
	if (k == key) {
		DRT* temp = new DRT(d, n, p);
		d = data;
		string next;
		string prev;
		if (!right)
			next = n;
		else next = right->first()->getk();
		if (!left)
			prev = p;
		else prev = left->last()->getk();
		return temp;
		//return new DRT(data, next, prev);

		/*d = data;
		return new DRT(data, n, p);*/
	}
	if (k < key) {
		if (right) {
			return right->add(key, data, n, k);
		}
		else {
			right = new TreeNode(key, data, NULL, NULL, this, t);
			return new DRT("", n, k);
		}

	}
	if (left) {
		return left->add(key, data, k, p);
	}
	else {
		left = new TreeNode(key, data, NULL, NULL, this, t);
		return new DRT("", k, p);
	}
		
	

}
//checks if this is the the item being searched for, else decides which node to call add on next
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

//decides if this is the key to remove, else decides which node  will have remove called next
DRT* TreeNode::remove(string key, string n, string p) {
	if (this->k == key) {
		if (!parent) {
			//if root
			DRT* tempD = new DRT(this->getd(), n, p);
			this->removeRoot();
			return tempD;
		}
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

void TreeNode::removeRoot() {
	//the physical removal (decides whether it's 0, 1, or 2-child case and possibly copies key and data values and physically removes the deleted node

	// 0 child case
	if (!left && !right) {
		t->setroot(nullptr);
	}
	//one child case
	else if (left != NULL && right == NULL || right != NULL && left == NULL) {
		if (left) {
			left->setparent(nullptr);
			t->setroot(left);
		}
		else {
			right->setparent(nullptr);
			t->setroot(right);
		}
	}
	//2 child case
	else if (left && right) {
		// go right once, then left all the way down to find next node
		//then copy all info from next node into "this" node (the one to be deleted)
		TreeNode* next = right->first();
		k = next->getk();
		d = next->getd();
		next->remove();
	}
}

void TreeNode::remove() {
	//the physical removal (decides whether it's 0, 1, or 2-child case and possibly copies key and data values and physically removes the deleted node

	// 0 child case
	if (!left && !right) {
		if (parent->getleft() == this) {
			parent->setleft(nullptr);
		}
		else if (parent->getright() == this) {
			parent->setright(nullptr);
		}
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
		else {
			//if  node to be delted is right child
			if (left) {
				left->setparent(parent);
				parent->setright(left);

			}
			else {
				right->setparent(parent);
				parent->setright(right);
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
		/*left = next->getleft();
		right = next->getright();*/
		next->remove();
	}

}
//sets different fields of this node
void TreeNode::setparent(TreeNode* p) { parent = p; }
void TreeNode::setleft(TreeNode* l) { left = l; }
void TreeNode::setright(TreeNode* r) { right = r; }