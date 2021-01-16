//					ECE 250 PROJECT 2		qttest.cpp
// 				  Author : ARJUN MEHTA
// 				 Date: 29 October 2020
//
// 	Represents a driver program for testing purposes

#include <iostream>
#include "cityinfo.h"
#include "quadtree.h"

using namespace std;

int main(){

	quadtree tree;						// Declare required variables
	string command;
	string line;
	string valuestring;
	string value;
	string val;
	string city_name;
	double x;
	double y;
	int population;
	double cost_of_living;
	double net_salary;
	string d;
	string attr;

	while(cin.eof()!=true){					// Loop till the end of the input file

		getline(cin,line);
		command=line.substr(0,line.find(" "));

		if(command=="i"){
			valuestring=line.substr(line.find(" ")+1);

			value=valuestring;
			val=value.substr(0,value.find(";"));
			city_name=val;

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			x=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			y=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			population=stoi(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			cost_of_living=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			net_salary=stod(val);

			cityinfo *info=new cityinfo(x,y,city_name,population,cost_of_living,net_salary);
			if(tree.insert(info)==false){
				delete info;
			}
		}

		else if(command=="s"){
			valuestring=line.substr(line.find(" ")+1);

			value=valuestring;
			val=value.substr(0,value.find(";"));
			x=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			y=stod(val);

			if(tree.search(x,y)!=0){
				std::cout<<"found "<<tree.search(x,y)->city_name<<std::endl;
			}
			else{
				std::cout<<"not found"<<std::endl;
			}
		}

		else if(command=="print"){
			tree.print();
		}

		else if(command=="size"){
			tree.size();
		}

		else if(command=="clear"){
			tree.clear();
			std::cout<<"success"<<std::endl;
		}

		else if(command=="q_max"){
			valuestring=line.substr(line.find(" ")+1);

			value=valuestring;
			val=value.substr(0,value.find(";"));
			x=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			y=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			d=val;

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			attr=val;

			tree.q_max(x,y,d,attr);
		}

		else if(command=="q_min"){
			valuestring=line.substr(line.find(" ")+1);

			value=valuestring;
			val=value.substr(0,value.find(";"));
			x=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			y=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			d=val;

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			attr=val;

			tree.q_min(x,y,d,attr);
		}

		else if(command=="q_total"){
			valuestring=line.substr(line.find(" ")+1);

			value=valuestring;
			val=value.substr(0,value.find(";"));
			x=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			y=stod(val);

			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			d=val;


			value=value.substr(value.find(";")+1);
			val=value.substr(0,value.find(";"));
			attr=val;

			tree.q_total(x,y,d,attr);
		}

		else if(command=="exit"){
			break;
		}

	}
	return 0;
}
