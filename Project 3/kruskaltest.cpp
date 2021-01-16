//					ECE 250 PROJECT 3		kruskaltest.cpp
// 				  Author : ARJUN MEHTA
// 				 Date: 20 November 2020
//
// 	Represents a driver program for testing purposes

#include <iostream>
#include "graph.h"
#include "disjointset.h"

using namespace std;

int main() {

	// Declare required data variables

	int u;
	int v;
	double w;
	int m;
	string line;
	string command;
	string value;
	string valuestring;
	string val;
	graph g;

	while(cin.eof()!=true){					// Loop till the end of the input file

		getline(cin,line);
		command=line.substr(0,line.find(" "));

		// Create a graph with m nodes

		if(command=="n"){

			valuestring=line.substr(line.find(" ")+1);

			value=valuestring;
			val=value.substr(0,value.find(";"));
			m=stoi(val);

			try{
				g.create(m);

			} catch(const char* warning){
				std::cout<<warning<<std::endl;

			}

		}

		// Inserts an edge between nodes u and v with weight w (a double type)

		else if(command=="i"){

			valuestring=line.substr(line.find(" ")+1);

			value=valuestring;
			val=value.substr(0,value.find(";"));
			u=stoi(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			v=stoi(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			w=stod(val);

			try{
				g.insert(u,v,w);

			} catch(const char* warning){
				std::cout<<warning<<std::endl;

			}

		}

		// Deletes the edge between nodes u and v

		else if(command=="d"){

			valuestring=line.substr(line.find(" ")+1);

			value=valuestring;
			val=value.substr(0,value.find(";"));
			u=stoi(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			v=stoi(val);

			try{
				g.del(u, v);

			} catch(const char* warning){
				std::cout<<warning<<std::endl;

			}


		}

		// Returns the degree of vertex u

		else if(command=="degree"){

			valuestring=line.substr(line.find(" ")+1);

			value=valuestring;
			val=value.substr(0,value.find(";"));
			u=stoi(val);

			try{
				g.degree(u);

			} catch(const char* warning){
				std::cout<<warning<<std::endl;

			}


		}

		// Returns the total number of edges in the graph


		else if(command=="edge_count"){

			g.edge_count();

		}

		// Removes all the edges from the graph

		else if(command=="clear"){

			g.clear();

		}

		// Calculates the minimum spanning tree and its weight

		else if(command=="mst"){

			g.mst();

		}

		// Exit the program


		else if(command=="exit"){

			break;

		}


	}

	return 0;
}


