//					ECE 250 PROJECT 1		chainaddressing.h
// 				  Author : ARJUN MEHTA
// 				 Date: 28 September 2020
//
// 	Defines functions to insert, search, delete and print entries
//	Implements chain addressing of hash tables


#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include<cstdlib>

#include "hash.h"											// include the class hash
#include "node.h"											// include the class node

using namespace std;

class chainaddressing{

private:


	int index;												// index of the hash object in vector hash table
	int size;												// size of vector



public:

	chainaddressing() {
		index=0;
		size=0;
	}

	vector <node*> hashvector;								// vector of nodes


	void create(int m) {									// defines size of the hash table

		for(int i=0;i<m;i++)
		{
			node* o=new node();
			hashvector.push_back(o);
		}
		size=m;
		std::cout<<"success"<<std::endl;

	}

	void insert(long int k, string caller){					// inserts the key k and the associated caller

		index = k%size;
		node* temp=hashvector[index];
		int success=0;
		int already=0;

		while(temp->next!=nullptr&&temp->next->data.phonenumber<k){

			temp=temp->next;

		}

		if(temp->next!=nullptr) {
		if(temp->next->data.phonenumber==k){
			already++;
		}
		}


		if(already==0){

		node *o = new node();
		o->data.phonenumber=k;
		o->data.callername=caller;
		o->next=temp->next;
		temp->next=o;


		success++;

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
		index = k%size;

		node* temp=hashvector[index];

		while(temp->next!=nullptr){
				temp=temp->next;
				if (temp->data.phonenumber==k){
					flag++;
					std::cout<<"found "<<temp->data.callername<<" in "<<index<<std::endl;
					break;
				}

		}

		if(flag==0){
			std::cout<<"not found"<<std::endl;
		}

	}

	void del(long int k){										// deletes the key k from the table

		index = k%size;
		int flag=0;

		node* temp=hashvector[index];

		while(temp->next!=nullptr){

				if (temp->next->data.phonenumber==k){

					node *o = temp->next;
					temp->next=temp->next->next;
					delete o;
					std::cout<<"success"<<std::endl;
					flag++;
					break;
				}
				temp=temp->next;

		}
		if(flag==0){
			std::cout<<"failure"<<std::endl;
		}

	}

	void print(int i){											// prints  the chain  of keys that starts at position i

		node* temp=hashvector[i];
		int printed=0;

		while(temp->next!=nullptr){
			std::cout<<temp->next->data.phonenumber<<" ";
			temp=temp->next;
			printed++;
		}
		if(printed!=0){
		std::cout<<std::endl;
		}
	}

};
