#pragma once
#include <string>
#include<list>
#include<iostream>
#include "User.h"
#include "blood.h"
using namespace std;
//TODO : class doner which holds data of doner.
class Donor :public User 
{
public:
	bool take_medi, ha_disease;
	string Date_of_last_donation;
};
//TODO : class node which holds object of doner.
class Node_Donor :public Donor
{
public:
	Donor doner;
	Node_Donor* next;
	Node_Donor();
};
//TODO : linked list of doner .
class donorlink :public Donor 
{
public:
	Node_Donor* head;
	Node_Donor* tail;
public:
	donorlink();
	//TODO: Get all doners
	void get_donor_data();
	//TODO : Updates the  doner data.
	void updateData();
	//TODO :Delete the doner account.
	void  deleteAccount();
	//TODO : Send Donation request & Make Donation if the request is confirmed.
	void Donation_request();
};