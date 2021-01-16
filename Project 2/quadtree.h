//					ECE 250 PROJECT 2		quadtree.h
// 				  Author : ARJUN MEHTA
// 				 Date: 29 October 2020
//
// 	Represents the class quadtree with definition of its data variables
//	and member functions as well as constructor and destructor

#ifndef QUADTREE_H_
#define QUADTREE_H_

#include <iostream>
#include "cityinfo.h"

using namespace std;

class quadtree{

private:


public:

	cityinfo *root;
	int count;

	quadtree(){
		root=nullptr;
		count=0;
	}

	~quadtree(){
		clear();

	}

	bool insert(cityinfo *info);
	cityinfo* search(double px,double py);
	int q_max(double x,double y,string d,string attr);
	int q_min(double x,double y,string d,string attr);
	int q_total(double x,double y,string d,string attr);
	void print();
	void clear();
	void size();

};





#endif /* QUADTREE_H_ */
