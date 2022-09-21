#pragma once
#include<iostream>
#include<string>
using namespace std;
//TODO : class blood which holds data of blood.
class Blood
{
public :
	string type;
	string Received_date;
	string Expiry_date;
};
//TODO : class node which holds object of blood.
class Node_Blood {
public:
	Blood blood;
	Node_Blood* next;
	Node_Blood();
};
//TODO : linked list of blood .
class Bloodlink 
{
public:
	Node_Blood* head;
	Node_Blood* tail;
	Bloodlink();
	//TODO : Read all Blood data from the blood file into blood linked list.
	void get_blood_data();
	//TODO : Count the quantity of spacific blood type.
	int  Quantity(string);
};
