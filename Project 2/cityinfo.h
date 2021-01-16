//					ECE 250 PROJECT 2		cityinfo.h
// 				  Author : ARJUN MEHTA
// 				 Date: 29 October 2020
//
// 	Represents the class cityinfo with definition of its data variables
//	and member functions as well as constructor and destructor

#ifndef CITYINFO_H_
#define CITYINFO_H_

#include <iostream>

using namespace std;

class cityinfo {

private:

public:

	double x;
	double y;
	string city_name;
	int population;
	double cost_of_living;
	double net_salary;
	cityinfo *NE;
	cityinfo *NW;
	cityinfo *SE;
	cityinfo *SW;

	int printcounter;

	cityinfo(double px,double py,string pname,int pp,double pcost,double pnet){

		x=px;
		y=py;
		city_name=pname;
		population=pp;
		cost_of_living=pcost;
		net_salary=pnet;
		NE=nullptr;
		NW=nullptr;
		SE=nullptr;
		SW=nullptr;
		printcounter=0;

	}

	cityinfo(){
		x=0;
		y=0;
		population=0;
		cost_of_living=0;
		net_salary=0;
		NE=nullptr;
		NW=nullptr;
		SE=nullptr;
		SW=nullptr;
		printcounter=0;
	}

	~cityinfo(){
	}

	friend class quadtree;

	bool insert(cityinfo *info,cityinfo *root);
	cityinfo* search(double px,double py,cityinfo *root);
	void q_max(cityinfo *info,double &max,string attr);
	void q_min(cityinfo *info,double &min,string attr);
	void q_total(cityinfo *info,double &min,string attr);
	void print(cityinfo *root,int count);
	void clear(cityinfo *&root,int &count);


};



#endif /* CITYINFO_H_ */
