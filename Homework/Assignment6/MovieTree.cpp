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

void MovieTree::printMovieInventory() {

	if(root!=NULL)
	{
		MovieNode *crl = root;
		cout ​ << ​ "Movie: "​ << m->title << ​ " "​ << m->rating << ​ endl​;
	}
	else
		cout ​ << ​ "Tree is Empty. Cannot print"​ << ​ endl​;
	
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  
  MovieNode *m = MovieNode(ranking, title, year, rating);

  if(root==NULL) {
  	root = m;
  	m->right = NULL;
  	m->left = NULL;
  	return
  }
  
  if(m->title[0] < root->title[0]) {
  	m->left =
  }




}

void MovieTree::findMovie(string title) {
  
  // Search tree till matching title is found
}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
}

void MovieTree::averageRating() {
  //write your code
}
