//					ECE 250 PROJECT 3		graph.h
// 				  Author : ARJUN MEHTA
// 				 Date: 20 November 2020
//
// 	Represents the class graph with definition of its data variables
//	and member functions as well as constructor and destructor (if applicable)

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include "edgeinfo.h"
#include "disjointset.h"

using namespace std;

class graph{

public:

	// Declare required data variables

	vector<edgeinfo> edge;
	int size;
	int numberofedges=0;
	int	totalconnected=0;

	// Constructor

	graph(){
		size=0;
		numberofedges=0;
		totalconnected=0;
	}


	// Create a graph with m nodes

	void create(int m){
		if(m<=0){
			throw "invalid argument";
		}
		else{
			size=m;
			std::cout<<"success"<<std::endl;
		}
	}



	// Inserts an edge between nodes u and v with weight w (a double type)

	void insert(int u,int v,double w){

		int success=0;
		for(int i=0;i<numberofedges;i++){
			if(edge[i].u==u&&edge[i].v==v){
				edge[i].w=w;
				success++;
			}
		}
		if(v>=0&&v<size&&u>=0&&u<size&&w>0.0&&success==0){
			edgeinfo newelement;
			newelement.u=u;
			newelement.v=v;
			newelement.w=w;
			edge.push_back(newelement);
			numberofedges++;
			success++;
		}
		if(success==0){
			throw "invalid argument";
		}
		else {
			std::cout<<"success"<<std::endl;
		}

	}



	// Deletes the edge between nodes u and v

	void del(int u,int v){
		int counter=0;
		if(u>=0&&v>=0&&u<size&&v<size){

			for(int i=0;i<numberofedges;i++){
				if(edge[i].u==u&&edge[i].v==v){
					edge.erase(edge.begin()+i);
					counter++;
					numberofedges--;
				}
			}

			if(counter==0){
				std::cout<<"failure"<<std::endl;
			}
			else{
				std::cout<<"success"<<std::endl;
			}
		}
		else{
			throw "invalid argument";
		}

	}



	// Returns the degree of vertex u

	void degree(int u){

		if(u>=0&&u<size){
			int degreeofu=0;
			for(int i=0;i<numberofedges;i++){
				if(edge[i].u==u){
					degreeofu++;
				}
			}
			std::cout<<"degree of "<<u<<" is "<<degreeofu<<std::endl;
		}
		else {
			throw "invalid argument";
		}
	}



	// Returns the total number of edges in the graph

	void edge_count(){
		std::cout<<"edge count is "<<numberofedges<<std::endl;
	}



	// Removes all the edges from the graph

	void clear(){
		edge.clear();
		numberofedges=0;
		std::cout<<"success"<<std::endl;
	}



	// Calculates the minimum spanning tree and its weight

	void mst(){
		disjointset s;
		s.makeset(size);
		edgeinfo temp;
		int u, v;

		// Sort the edges in the graph

		for(int i=0;i<numberofedges;i++){
			for(int j=0;j<numberofedges;j++){
				if(edge[j].w>edge[i].w){
					temp=edge[i];
					edge[i]=edge[j];
					edge[j]=temp;
				}
			}
		}

		// Kruskal's algorithm to calculate minimum spanning tree

		double weight=0;

		for(int i=0;i<numberofedges;i++){

			u=edge[i].u;
			v=edge[i].v;
			if(s.findset(u)!=s.findset(v)){
				s.unionsets(u,v,totalconnected);
				weight=weight+edge[i].w;
			}
		}

		if(totalconnected==size){
			std::cout<<std::fixed<<std::setprecision(2)<<"mst "<<weight<<std::endl;
		}
		else {
			std::cout<<"not connected"<<std::endl;
		}

	}


};



#endif /* GRAPH_H_ */
