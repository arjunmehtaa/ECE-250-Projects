//					ECE 250 PROJECT 2		quadtree.cpp
// 				  Author : ARJUN MEHTA
// 				 Date: 29 October 2020
//
// 	Represents source file where all functions for both classes,
// 	cityinfo and quadtree are defined

#include <iostream>
#include <iomanip>
#include "cityinfo.h"
#include "quadtree.h"

using namespace std;

bool cityinfo::insert(cityinfo *info,cityinfo *root){


	if(info->x==root->x&&info->y==root->y) {
	return false;
	}

	else {

		if(info->x>=root->x&&info->y>root->y) {
			if(root->NE==nullptr) {
				root->NE=info;
				return true;

			}
			else if(NE!=nullptr){
				NE->insert(info,root->NE);
			}
		}


		else if(info->x<root->x&&info->y>=root->y) {
			if(root->NW==nullptr) {
				root->NW=info;
				return true;
			}
			else if(root->NW!=nullptr){
				NW->insert(info,root->NW);
			}
		}


		else if(info->x<=root->x&&info->y<root->y) {
			if(root->SW==nullptr) {
				root->SW=info;
				return true;
			}
			else if(SW!=nullptr){
				SW->insert(info,root->SW);
			}
		}


		else if(info->x>root->x&&info->y<=root->y) {
			if(root->SE==nullptr) {
				root->SE=info;
				return true;
			}
			else if(SE!=nullptr){
				SE->insert(info,root->SE);
			}

		}

	}

}


bool quadtree::insert(cityinfo *info){

	if(count==0){

		root=info;
		count++;
		std::cout<<"success"<<std::endl;
		return true;

	}

	else {

		if(root->insert(info, root)==true){
			count++;
			std::cout<<"success"<<std::endl;
			return true;
		}

		else {
			std::cout<<"failure"<<std::endl;
			return false;
		}

	}

}

cityinfo* cityinfo::search(double a,double b,cityinfo *root){

	cityinfo* success=0;

	if(root==nullptr){
		return 0;
	}

	if(root->x==a&&root->y==b){
		success=root;
		return success;
	}
	else {
		if(a>=root->x&&b>root->y){
			if(NE!=nullptr){
				success=NE->search(a,b,root->NE);
			}
			else{
				return 0;
			}
		}

		else if(a>=root->x&&b>root->y){
			if(NW!=nullptr){
				success=NW->search(a,b,root->NW);
			}
			else{
				return 0;
			}
		}

		else if(a<=root->x&&b<root->y){
			if(SW!=nullptr) {
				success=SW->search(a,b,root->SW);
			}
			else {
				return 0;
			}
		}

		else if(a>root->x&&b<=root->y){
			if(SE!=nullptr){
				success=SE->search(a,b,root->SE);
			}
			else {
				return 0;
			}
		}

	}

	return success;

}

cityinfo* quadtree::search(double px,double py){

	cityinfo* success=0;
	if(count==0){
		return 0;
	}

	else{
		if(root->search(px,py,root)!=0){
			success=root->search(px,py,root);
		}
	}

	return success;
}



void cityinfo::print(cityinfo *root,int count){
	if(root!=nullptr){
		print(root->NE,count);
		print(root->NW,count);

		if(printcounter==count-1){
			std::cout<<root->city_name<<std::endl;
			printcounter=0;
		}
		else{
			std::cout<<root->city_name<<" ";
			printcounter++;
		}

		print(root->SW,count);
		print(root->SE,count);
	}

}

void quadtree::print(){

	if(root!=nullptr){
		root->print(root,count);
	}
}

void cityinfo::clear(cityinfo *&root,int &count){
	if(root!=nullptr&&count>=1){
		clear(root->NE,count);
		clear(root->NW,count);
		clear(root->SW,count);
		clear(root->SE,count);
		delete root;
		root=nullptr;
		count--;
	}
}

void quadtree::clear(){
	root->clear(root,count);
	root=nullptr;
}

void quadtree::size(){
	std::cout<<"tree size "<<count<<std::endl;
}

void cityinfo::q_max(cityinfo *root,double &max,string attr){

	if(root!=nullptr){
		q_max(root->NE,max,attr);
		q_max(root->NW,max,attr);

		if(attr=="p"&&root->population>max){
			max=root->population;
		}
		else if(attr=="r"&&root->cost_of_living>max){
			max=root->cost_of_living;
		}
		else if(attr=="s"&&root->net_salary>max){
			max=root->net_salary;
		}

		q_max(root->SW,max,attr);
		q_max(root->SE,max,attr);
	}

}

int quadtree::q_max(double x,double y,string d,string attr){

	double max;
	if(root==nullptr){
		std::cout<<"failure"<<std::endl;
		return 0;
	}

	else if(search(x,y)==0){
		std::cout<<"failure"<<std::endl;
		return 0;
	}

	else if(search(x,y)!=0){

		cityinfo *found=search(x,y);


		if(attr=="p"&&d=="NE"&&found->NE!=nullptr){
			max=found->NE->population;
		}
		else if(attr=="p"&&d=="NW"&&found->NW!=nullptr){
			max=found->NW->population;
		}
		else if(attr=="p"&&d=="SW"&&found->SW!=nullptr){
			max=found->SW->population;
		}
		else if(attr=="p"&&d=="SE"&&found->SE!=nullptr){
			max=found->SE->population;
		}

		else if(attr=="r"&&d=="NE"&&found->NE!=nullptr){
			max=found->NE->cost_of_living;
		}
		else if(attr=="r"&&d=="NW"&&found->NW!=nullptr){
			max=found->NW->cost_of_living;
		}
		else if(attr=="r"&&d=="SW"&&found->SW!=nullptr){
			max=found->SW->cost_of_living;
		}
		else if(attr=="r"&&d=="SE"&&found->SE!=nullptr){
			max=found->SE->cost_of_living;
		}

		else if(attr=="s"&&d=="NE"&&found->NE!=nullptr){
			max=found->NE->net_salary;
		}
		else if(attr=="s"&&d=="NW"&&found->NW!=nullptr){
			max=found->NW->net_salary;
		}
		else if(attr=="s"&&d=="SW"&&found->SW!=nullptr){
			max=found->SW->net_salary;
		}
		else if(attr=="s"&&d=="SE"&&found->SE!=nullptr){
			max=found->SE->net_salary;
		}

		if(d=="NE"){
			if(found->NE!=nullptr){
				root->q_max(found->NE, max, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

		else if(d=="NW"){
			if(found->NW!=nullptr){
				root->q_max(found->NW, max, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

		else if(d=="SW"){
			if(found->SW!=nullptr){
				root->q_max(found->SW, max, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

		else if(d=="SE"){
			if(found->SE!=nullptr){
				root->q_max(found->SE, max, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

	}
	if(attr=="p"){
		std::cout<<std::fixed<<std::setprecision(0)<<"max "<<max<<std::endl;
	}
	else {
		std::cout<<std::fixed<<std::setprecision(2)<<"max "<<max<<std::endl;
	}

	return 1;
}

void cityinfo::q_min(cityinfo *root,double &min,string attr){

	if(root!=nullptr){
		q_min(root->NE,min,attr);
		q_min(root->NW,min,attr);

		if(attr=="p"&&root->population<min){
			min=root->population;
		}
		else if(attr=="r"&&root->cost_of_living<min){
			min=root->cost_of_living;
		}
		else if(attr=="s"&&root->net_salary<min){
			min=root->net_salary;
		}

		q_min(root->SW,min,attr);
		q_min(root->SE,min,attr);
	}

}

int quadtree::q_min(double x,double y,string d,string attr){

	double min;
	if(root==nullptr){
		std::cout<<"failure"<<std::endl;
		return 0;
	}

	else if(search(x,y)==0){
		std::cout<<"failure"<<std::endl;
		return 0;
	}

	else if(search(x,y)!=0){

		cityinfo *found=search(x,y);


		if(attr=="p"&&d=="NE"&&found->NE!=nullptr){
			min=found->NE->population;
		}
		else if(attr=="p"&&d=="NW"&&found->NW!=nullptr){
			min=found->NW->population;
		}
		else if(attr=="p"&&d=="SW"&&found->SW!=nullptr){
			min=found->SW->population;
		}
		else if(attr=="p"&&d=="SE"&&found->SE!=nullptr){
			min=found->SE->population;
		}

		else if(attr=="r"&&d=="NE"&&found->NE!=nullptr){
			min=found->NE->cost_of_living;
		}
		else if(attr=="r"&&d=="NW"&&found->NW!=nullptr){
			min=found->NW->cost_of_living;
		}
		else if(attr=="r"&&d=="SW"&&found->SW!=nullptr){
			min=found->SW->cost_of_living;
		}
		else if(attr=="r"&&d=="SE"&&found->SE!=nullptr){
			min=found->SE->cost_of_living;
		}

		else if(attr=="s"&&d=="NE"&&found->NE!=nullptr){
			min=found->NE->net_salary;
		}
		else if(attr=="s"&&d=="NW"&&found->NW!=nullptr){
			min=found->NW->net_salary;
		}
		else if(attr=="s"&&d=="SW"&&found->SW!=nullptr){
			min=found->SW->net_salary;
		}
		else if(attr=="s"&&d=="SE"&&found->SE!=nullptr){
			min=found->SE->net_salary;
		}

		if(d=="NE"){
			if(found->NE!=nullptr){
				root->q_min(found->NE, min, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

		else if(d=="NW"){
			if(found->NW!=nullptr){
				root->q_min(found->NW, min, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

		else if(d=="SW"){
			if(found->SW!=nullptr){
				root->q_min(found->SW, min, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

		else if(d=="SE"){
			if(found->SE!=nullptr){
				root->q_min(found->SE, min, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

	}
	if(attr=="p"){
		std::cout<<std::fixed<<std::setprecision(0)<<"min "<<min<<std::endl;
	}
	else {
		std::cout<<std::fixed<<std::setprecision(2)<<"min "<<min<<std::endl;
	}

	return 1;
}


void cityinfo::q_total(cityinfo *root,double &total,string attr){

	if(root!=nullptr){
		q_total(root->NE,total,attr);
		q_total(root->NW,total,attr);

		if(attr=="p"){
			total=total+root->population;
		}
		else if(attr=="r"){
			total=total+root->cost_of_living;
		}
		else if(attr=="s"){
			total=total+root->net_salary;
		}

		q_total(root->SW,total,attr);
		q_total(root->SE,total,attr);
	}

}

int quadtree::q_total(double x,double y,string d,string attr){

	double total=0;
	if(root==nullptr){
		std::cout<<"failure"<<std::endl;
		return 0;
	}

	else if(search(x,y)==0){
		std::cout<<"failure"<<std::endl;
		return 0;
	}

	else if(search(x,y)!=0){

		cityinfo *found=search(x,y);

		if(d=="NE"){
			if(found->NE!=nullptr){
				root->q_total(found->NE, total, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

		else if(d=="NW"){
			if(found->NW!=nullptr){
				root->q_total(found->NW, total, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

		else if(d=="SW"){
			if(found->SW!=nullptr){
				root->q_total(found->SW, total, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

		else if(d=="SE"){
			if(found->SE!=nullptr){
				root->q_total(found->SE, total, attr);
			}
			else {
				std::cout<<"failure"<<std::endl;
				return 0;
			}
		}

	}
	if(attr=="p"){
		std::cout<<std::fixed<<std::setprecision(0)<<"total "<<total<<std::endl;
	}
	else {
		std::cout<<std::fixed<<std::setprecision(2)<<"total "<<total<<std::endl;
	}


	return 1;
}
