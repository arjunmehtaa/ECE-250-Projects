//					ECE 250 PROJECT 1		openhttest.cpp
// 				  Author : ARJUN MEHTA
// 				 Date: 28 September 2020
// 	Driver Program for Chain Addressing of hash table

#include <iostream>							// Include required header files
#include <vector>
#include "hash.h"
#include "openaddressing.h"

using namespace std;

int main() {

	openaddressing table;

	string line;							// Declare required variables
	string command;
	int m;
	long int k;
	string caller;

	while(cin.eof()!=true){					// Loop till the end of the input file

		getline(cin,line);
		command=line.substr(0,1);

		if(command=="n"){					// Running the create commands
			m=stoi(line.substr(2));
			table.create(m);
		}

		else if(command=="i"){				// Running the insert commands
			k=stol(line.substr(2,11));
			caller=line.substr(13);
			table.insert(k, caller);
		}

		else if(command=="s"){
			k=stol(line.substr(2,11));		// Running the search commands
			table.search(k);
		}

		else if(command=="d"){				// Running the delete commands
			k=stol(line.substr(2,11));
			table.del(k);
		}

	}

	return 0;

}
