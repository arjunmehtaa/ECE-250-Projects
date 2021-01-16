//					ECE 250 PROJECT 1		hash.h
// 				  Author : ARJUN MEHTA
// 				 Date: 28 September 2020
//
// 	Represents the class hash that stores phone number and the name of the caller

#ifndef HASH_H_
#define HASH_H_

#include <iostream>

using namespace std;

class Hash {

public:
	long int phonenumber;			// Phone number of the caller
	string callername;				// Name of the caller

	Hash() {
		phonenumber=0;
	}

};

#endif /* HASH_H_ */
