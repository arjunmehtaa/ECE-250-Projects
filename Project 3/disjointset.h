//					ECE 250 PROJECT 3		disjointset.h
// 				  Author : ARJUN MEHTA
// 				 Date: 20 November 2020
//
// 	Represents the class disjoint set with definition of its data variables
//	and member functions as well as constructor and destructor (if applicable)

#ifndef DISJOINTSET_H_
#define DISJOINTSET_H_

#include <iostream>
#include <vector>
#include "edgeinfo.h"
#include "graph.h"
#include "nodelist.h"

using namespace std;

class disjointset{

public:


	// Declare required data variables

	nodelist *set;
	int size;

	// Constructor

	disjointset(){
		size=0;
		set=nullptr;
	}

	// Member functions

	// Makes the disjoint set

	void makeset(int m){

		size=m;
		set=new nodelist[m];

		for(int i=0;i<m;i++){

			nodelist *creatednode=new nodelist();
			set[i].head=creatednode;
			set[i].tail=creatednode;
			set[i].head->value=i;
			set[i].head->value=i;
			set[i].value=i;
		}

	}


	// Finds the parent / index of the the vertex u

	int findset(int u){

		int parent;

		nodelist* temp=set[u].head;
		while(temp->head!=nullptr){
				temp=temp->head;
		}

		parent=temp->value;

		return parent;
	}


	// Unions the two sets containing vertex u and v

	void unionsets(int u, int v,int &totalconnected){

		int a=findset(u);
		int b=findset(v);

		if(set[a].connectedelements<set[b].connectedelements){
			nodelist* temp=set[a].head;
			while(temp->head!=nullptr){
				temp=temp->head;
			}
			set[b].tail=temp;
			temp->head=set[b].head;


			set[b].connectedelements=set[b].connectedelements+set[a].connectedelements;
			set[a].connectedelements=set[b].connectedelements;
			totalconnected=set[b].connectedelements;

		}


		else if(set[b].connectedelements<=set[a].connectedelements){
			nodelist* temp=set[b].head;
			while(temp->head!=nullptr){
				temp=temp->head;
			}
			set[a].tail=temp;
			temp->head=set[a].head;

			set[a].connectedelements=set[a].connectedelements+set[b].connectedelements;
			set[b].connectedelements=set[a].connectedelements;
			totalconnected=set[a].connectedelements;
		}


	}


	// Destructor

	~disjointset(){
		for(int i=0;i<size;i++){
			delete set[i].head;
			set[i].head=nullptr;
		}
		delete [] set;
		set=nullptr;
	}


};



#endif /* DISJOINTSET_H_ */
