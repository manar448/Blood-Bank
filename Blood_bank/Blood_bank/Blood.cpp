#include "blood.h"
#include <iostream>
#include<fstream>
#include<iomanip>
#include <cstdlib>
#include<stdlib.h>
#include<string>
using namespace std;

Node_Blood::Node_Blood()
{
	Blood blood;
	blood.type = "0";
	blood.Expiry_date = "0";
	blood.Received_date = "0";
	next = NULL;
}

Bloodlink::Bloodlink()
{
	head = tail = NULL;
}

void Bloodlink::get_blood_data()
{   
	ifstream in_Fl("blood.txt", ios::binary);
	if (in_Fl.fail())
	{
		cout << "The File was not opened successfully check that the file eixst\n";
		exit(1);
	}
	//TODO: loop over the blood bags and put it into linked list.
	while (true)
	{ 
		Node_Blood* temp = new Node_Blood();
		in_Fl >> temp->blood.type;
		in_Fl >> temp->blood.Received_date;
		in_Fl >> temp->blood.Expiry_date;
		if (in_Fl.fail()) 
		{
			delete temp;
			break;
		}
		if (head == NULL)
		{
			head = temp;
		}
		else {
			tail->next = temp;
		}
		tail = temp;
	}
	in_Fl.close();
}

int Bloodlink::Quantity(string bloodType)
{
	int quantity = 0;   
	Node_Blood* temp = new Node_Blood();   
	temp = head;                         
	//TODO: loop over the blood bags and check for blood type and count it.
	while (temp != NULL)
	{
		if (temp->blood.type == bloodType)
		{
			quantity += 1;
		}
		temp = temp->next;
	}
	return quantity;
}



