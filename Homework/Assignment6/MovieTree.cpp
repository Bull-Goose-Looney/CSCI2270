#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
	root = NULL;
}

void destroyTree(MovieNode *crl) {
	if(crl) {
		destroyTree(crl->left);
		destroyTree(crl->right);
		delete crl;
		crl = NULL;
	}
}

MovieTree::~MovieTree() {
	destroyTree(root);
}


//------------PRINT---------------------
void printHelper(MovieNode *current) {
	if(current) {
		printHelper(current->left);
		cout <<  "Movie: " << current->title <<  " " << current->rating << endl;
		printHelper(current->right);
	}
}

void MovieTree::printMovieInventory() {

	if(root!=NULL) 
		printHelper(root);
	else {
		cout  <<  "Tree is Empty. Cannot print" <<  endl;
	}
	
}
//--------------------------------------

//-----------ADD NODE-------------------

MovieNode *addHelper(MovieNode *crawl, int r, string t, int y, float rate) {

	// If root is null make passed node root.
	if(crawl == NULL) {
		MovieNode *nMov = new MovieNode(r,t,y,rate);
		nMov->left = NULL;
		nMov->right = NULL;
		return nMov;
	}
	// If t comes after crawler in alphabet. move to next child on right.
	else if(t > crawl->title) 
		crawl->right = addHelper(crawl->right, r, t, y, rate);
	// If t comes before crawler, move to next child on left. 
	else if(t < crawl->title)
		crawl->left = addHelper(crawl->left, r, t, y, rate);

	return crawl;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  
  MovieNode *m = addHelper(root, ranking, title, year,rating);

  if(m->right == NULL && m->left == NULL)
  	root = m;

}
//----------------SEARCH-------------l-------------
void searchHelper(MovieNode *crawl, string title) {
	if(crawl == NULL) {
		cout << "Movie not found." << endl;
		return;
	}
	else {

		if(crawl->title == title) {
			cout << "Movie Info: "<< endl;
			cout << "==================" << endl;
			cout << "Ranking:"<< crawl->ranking <<endl;
			cout << "Title  :"<< crawl->title <<endl;
			cout << "Year   :"<< crawl->year <<endl;
			cout << "rating :"<< crawl->rating <<endl;
			return;
		}

		else if(title < crawl->title)
			searchHelper(crawl->left, title);
		else if(title > crawl->title)
			searchHelper(crawl->right, title);
	}

}
void MovieTree::findMovie(string title) {
  searchHelper(root, title);
}
//---------------------------------------------------

//-----------Find Movies w/ rating & year------------
void queryHelper(MovieNode *crawl, float r, int y) { //DLR Traverse
	if(crawl) {
		
		if(crawl->rating >= r && crawl->year >= y)
			cout << crawl->title << "(" << crawl->year << ") " << crawl->rating << endl;
		queryHelper(crawl->left,r,y);
		queryHelper(crawl->right,r,y);
	}
}
void MovieTree::queryMovies(float rating, int year) {
  if(root == NULL)
  	cout << "Tree is Empty. Cannot query Movies" << endl;
  else {
  	cout << "Movies that came out after " << year << " with rating at least "
  	<< rating << ":" << endl;
  	queryHelper(root, rating, year);
  }
}
//--------------------------------------------------

//-------------Calculate average ratings------------
int sumNodes(MovieNode *crl) {
	int count = 1;
	if(crl->left)
		count += sumNodes(crl->left);
	if(crl->right)
		count += sumNodes(crl->right);
	return count;
}
float averageHlpr(MovieNode *crl) {
	float sum = crl->rating;
	if(crl->left)
			sum += averageHlpr(crl->left);
	if(crl->right)
			sum += averageHlpr(crl->right);
	return sum;
}
void MovieTree::averageRating() {
	if(!root){
		cout << "Average rating:0.0" << endl;
		return;
	}
	else {
		float avg = averageHlpr(root) / sumNodes(root);
  	cout << "Average rating:" << setprecision(6) << avg << endl;
	}
}
//---------------------------------------------