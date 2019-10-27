#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  
  root = NULL;
}

void deleteTreeHelper(TreeNode *t){
     if(t!=NULL)
     {
     	 LLMovieNode *crl = t->head;
     	 LLMovieNode *tmp = t->head;

         deleteTreeHelper(t->leftChild);
         if(t->head) {
         	while(crl) {
	         	crl = crl->next;
	         	delete tmp;
	         	tmp = crl;
	         }
         }
         deleteTreeHelper(t->rightChild);
         delete t;
     }
 }

MovieTree::~MovieTree() {
  deleteTreeHelper(root);
}

//####################-PRINT TREE-########################
void printHelper(TreeNode *current) {

	if(current) {
		LLMovieNode *crl = current->head;
		printHelper(current->leftChild);
		while(crl!=NULL) {
			if(crl == current->head)
				cout << "Movies starting with letter: " << current->titleChar << endl;
			cout << " >> " << crl->title << " " << crl->rating << endl;
			crl = crl->next;
		}
		printHelper(current->rightChild);
	}
}

void MovieTree::printMovieInventory() {
	if(root!=NULL)
		printHelper(root);
}
//#######################################################




//####################-ADD NODE-########################
LLMovieNode *addHelper(TreeNode *crl, int r, string t, int y, float rate) {
	char firstC = t[0];
	if(t[0] == crl->titleChar) {
		LLMovieNode *n = new LLMovieNode(r,t,y,rate);
		LLMovieNode *tmp = crl->head;
		LLMovieNode *prev = crl->head;
		if(crl->head == NULL) {
			crl->head = n;
			return n;
		}
		if(tmp->title > t) {
			n->next = tmp;
			crl->head = n;
			return n;
		}
		else {
			while(prev->next!=NULL) {
				tmp = tmp->next;
				if(t < tmp->title) {
					n->next = tmp;
					prev->next = n;
					return n;
				}
				prev = prev->next;	
			}
			if(prev->next==NULL) {
				prev->next = n;
				n->next = NULL;
			}
			return n;
		}
	}
	else if(t[0] < crl->titleChar) {
		if(crl->leftChild == NULL) {
			TreeNode *t = new TreeNode;
			t->titleChar = firstC;
			crl->leftChild = t;
			t->parent = crl;
		}
		addHelper(crl->leftChild,r,t,y,rate);
	}
	else if(t[0] > crl->titleChar) {
		if(crl->rightChild == NULL) {
			TreeNode *t = new TreeNode;
			t->titleChar = firstC;
			crl->rightChild = t;
			t->parent = crl;
		}
		addHelper(crl->rightChild,r,t,y,rate);
	}
	return NULL;
}

void MovieTree::addMovie(int ranking, string title, int year, float rating) {
	if(!root) {
		TreeNode *n = new TreeNode;
		LLMovieNode *m = new LLMovieNode(ranking, title, year, rating);
		n->titleChar = title[0];
		n->parent = NULL;
		n->head = m;
		root = n;
		return;
	}
	else
		LLMovieNode *m = addHelper(root, ranking, title, year, rating);
}

//######################################################


//##################-DELETE MOVIE-######################
TreeNode *getMinVal(TreeNode *curr) {
	if(curr->leftChild==NULL) {
		return curr;
	}
	return getMinVal(curr->leftChild);
}

TreeNode *deleteNode(TreeNode *t) {

  if(t == NULL)
  {
    return NULL;
  }
  else
  {
    if(t->leftChild == NULL && t->rightChild == NULL)
    {
      delete t;
      return NULL;
    }
    else if(t->leftChild== NULL)
    {
      TreeNode *tmp = t;
      t = t->rightChild;
      delete tmp;
    }
    else if(t->rightChild == NULL)
    {
      TreeNode *tmp = t;
      t = t->leftChild;
      delete tmp;
    }
    else
    {
      TreeNode *tmp = t;
      tmp = getMinVal(t->rightChild);
      t->titleChar = tmp->titleChar;
      t->head = tmp->head;
      deleteNode(tmp);
      return t;
    }
  }
return t;
}


TreeNode *deleteHelper(TreeNode *cur, string title) {
	if(!cur)
		return NULL;

	if(title[0]==cur->titleChar)
	{
		if(cur->head->next==NULL && cur->head->title==title) // DELETE TreeNode if deleting only movie
		{
			LLMovieNode *tmp = cur->head;
			cur->head = NULL;
			delete tmp;
			deleteNode(cur);
		}
		else // Delete LLNode from TreeNode
		{
			LLMovieNode *tmp = cur->head;
			LLMovieNode *nxt = cur->head;

			// if deleting old head
			if(cur->head->title==title) {
				tmp = nxt;
				nxt=nxt->next;
				cur->head=nxt;
				delete tmp;
			}
			// If deleting not the head.
			while(nxt!=NULL)
			{
				if(nxt->title==title)
				{
					tmp = nxt;
					nxt = nxt->next;
					delete tmp;
					return cur;
				}
				nxt=nxt->next;
			}
			return NULL;
		}
	}

	else if(title[0]<cur->titleChar)
		deleteHelper(cur->leftChild, title);
	else if(title[0]>cur->titleChar)
		deleteHelper(cur->rightChild, title);

}

void MovieTree::deleteMovie(string title) {
	if(!deleteHelper(root, title))
		cout << "Movie: " << title << " not found, cannot delete." << endl;
}





