#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  //write your code
	ranking = 0;
	title = "";
	year = 0;
	rating = 0.0;

}

MovieTree::~MovieTree() {

}

//------------PRINT---------------------
void printHelper(MovieNode *current) {
	if(current) {
		printHelper(current->left);
		cout << ​ "Movie: "​ << current->title << ​ " "​ << current->rating << ​ endl​;
		printHelper(current->right);
	}
}

void MovieTree::printMovieInventory() {

	if(root!=NULL) 
		printHelper(root);
	else
		cout ​ << ​ "Tree is Empty. Cannot print"​ << ​ endl​;
	
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
//--------------------------------------
bool searchHelper(MovieNode *crawl, string title) {
	if(crawl == NULL)
		return false;
	if(crawl->title == title) {
		cout << "Movie Info: "<< endl;
		cout << "==================" << endl;
		cout << "Ranking :"​<< crawl->ranking <<​ endl;
		cout << "Title :"<< crawl->title <<​ endl;
		cout << "Year :"​<< crawl->year <<​ endl;
		cout << "rating :"​<< crawl->rating <<​ endl;
		return true;
	}
	else if(title < crawl->title)
		searchHelper(crawl->left, title);
	else if(title < crawl->title)
		searchHelper(crawl->right, title);
}

void MovieTree::findMovie(string title) {
  
  if(searchHelper(root, title)==false)
  	cout <<"Movie not found."<< endl;

}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
}

void MovieTree::averageRating() {
  //write your code
}
