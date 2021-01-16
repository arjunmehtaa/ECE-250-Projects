//					ECE 250 PROJECT 1		node.h
// 				  Author : ARJUN MEHTA
// 				 Date: 28 September 2020
//
// 	Represents the class node, which represents a node in a linked list


#include "hash.h"					// includes class hash

class node {

public:

	Hash data;						// data in every node is an object of class hash
	node *next;						// pointer to next node

	node(){
		next=nullptr;				// constructor, next is equal to a null pointer
	}

	~node() {
		delete next;
	}

};
