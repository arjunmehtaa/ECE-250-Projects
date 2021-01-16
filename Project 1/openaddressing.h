//					ECE 250 PROJECT 1		openaddressing.h
// 				  Author : ARJUN MEHTA
// 				 Date: 28 September 2020
//
// 	Represents the class hash; provides options to insert, search, delete and print entries

#include <iostream>
#include <vector>
#include "hash.h"											// include the class hash

using namespace std;

class openaddressing{

private:

	vector<Hash> hashtable;									// vector of objects of class Hash
	int index;												// index of the Hash object in vector hash table
	int size;												// size of vector

public:

	openaddressing() {
		index=0;
		size=0;

	}

	void create(int m) {									// defines size of the hash table

		hashtable.resize(m);
		size=m;
		std::cout<<"success"<<std::endl;

	}

	void insert(long int k, string caller){					// inserts the key k and the associated caller

		index = k%size;
		int success=0;

		for(int i=0;i<size;i++){

			if(hashtable[index].phonenumber==0){

					hashtable[index].phonenumber=k;
					hashtable[index].callername=caller;
					success++;
					break;

				}

			else {
					index=((k%size)+i*((k/size)%size))%size;
				}
		}

		if(success==1){
			std::cout<<"success"<<std::endl;
		}

		else{
			std::cout<<"failure"<<std::endl;
		}

	}

	void search(long int k){									// searches for the key k in the table

		int flag=0;
		for(int i=0;i<size;i++) {
			if(hashtable[i].phonenumber==k){
				std::cout<<"found "<<hashtable[i].callername<<" in "<<i<<std::endl;
				flag++;
				break;
			}
		}
		if(flag==0) {
			std::cout<<"not found"<<std::endl;
		}

	}

	void del(long int k){										// deletes the key k from the table

		int flag=0;
		for(int i=0;i<size;i++) {
			if(hashtable[i].phonenumber==k){
				hashtable.erase(hashtable.begin()+i);
				std::cout<<"success"<<std::endl;
				flag++;
				break;
			}
		}
		if(flag==0){
			std::cout<<"failure"<<std::endl;
		}

	}



};
