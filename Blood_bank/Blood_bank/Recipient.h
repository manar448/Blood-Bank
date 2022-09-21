#pragma once
#include "User.h"
#include<iostream>
#include<string.h>
#include "Blood.h"
using namespace std;
//TODO : class recipient which holds data of recipient.
class Recipient :public User
{
public:
	string hospital;
	string doctorOfCase;
};
//TODO : class node which holds object of recipient.
class Node_Recipient :public User
{
public:
	Recipient recipient;
	Node_Recipient* next;
	Node_Recipient();
};
//TODO : linked list of recipient .
class recipientlink :public Recipient {
public:
	Node_Recipient* head;
	Node_Recipient* tail;
public:
	recipientlink();
	//TODO : Read all recipient data from the recipient file into recipient linked list.
	void get_Recipient_data();
	//TODO : Updates the recipient data.
	void updateData();
	//TODO :Delete the recipient account.
	void  deleteAccount();
	//TODO : Display all data of  blood.
	void display_All_Blood_Data();
	//TODO: Search for the availability of blood type & display his quantity.
	bool bloodType_availabilitySearch(string blood_type);
	//TODO : Send recipient request & confirme the request.
	void recipient_Request(string);
};

