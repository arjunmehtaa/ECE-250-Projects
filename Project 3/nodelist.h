//					ECE 250 PROJECT 3		nodelist.h
// 				  Author : ARJUN MEHTA
// 				 Date: 20 November 2020
//
// 	Represents the class nodelist with definition of its data variables
//	and member functions as well as constructor and destructor (if applicable)

#ifndef NODELIST_H_
#define NODELIST_H_


class nodelist{

public:

	// Declare required data variables

	nodelist *head;
	nodelist *tail;
	int value;
	int connectedelements=1;

	// Constructor

	nodelist(){
		head=nullptr;
		tail=nullptr;
		value=0;
		connectedelements=1;
	}

	// Destructor

	~nodelist(){

	}

};



#endif /* NODELIST_H_ */
