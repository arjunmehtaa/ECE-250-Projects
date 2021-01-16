//					ECE 250 PROJECT 3		edgeinfo.h
// 				  Author : ARJUN MEHTA
// 				 Date: 20 November 2020
//
// 	Represents the class edgeinfo with definition of its data variables
//	and member functions as well as constructor and destructor (if applicable)

#ifndef EDGEINFO_H_
#define EDGEINFO_H_

#include <iostream>
#include <vector>

using namespace std;

class edgeinfo{

public:

	// Declare required data variables

	int u;
	int v;
	double w;

	// Constructor

	edgeinfo(){
		u=0;
		v=0;
		w=0;
	}

};



#endif /* EDGEINFO_H_ */
