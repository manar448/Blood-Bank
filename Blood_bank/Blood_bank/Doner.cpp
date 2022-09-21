#include "User.h"
#include "Blood.h"
#include "Recipient.h"
#include "Doner.h"
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include<string.h>
#include "main.h"
using namespace std;

Node_Donor::Node_Donor()
{
	Donor doner;
	doner.ID = doner.Age = 0;
	doner.Name = doner.Mail = doner.Password = doner.Date_of_last_donation= "0";
	doner.Gender = '0';
	doner.take_medi = doner.ha_disease = false;
	next = NULL;
}

donorlink::donorlink()
{
	head = tail = NULL;
}

void donorlink::get_donor_data()
{
	ifstream in_Fl("doner.txt", ios::binary);
	if (in_Fl.fail())
	{
		cout << "The File was not opened successfully check that the file eixst\n";
		exit(1);
	}
	while (true) 
	{
		Node_Donor* temp = new Node_Donor();
		in_Fl >> temp->doner.ID;
		in_Fl >> temp->doner.Age;
		in_Fl >> temp->doner.Name;
		in_Fl >> temp->doner.Mail;
		in_Fl >> temp->doner.Password;
		in_Fl >> temp->doner.Date_of_last_donation;
		in_Fl >> temp->doner.Blood_type;
		in_Fl >> temp->doner.Gender;
		in_Fl >> temp->doner.take_medi;
		in_Fl >> temp->doner.ha_disease;
		if (in_Fl.fail()) 
		{
			delete temp;
			break;
		}
		if (head == NULL) {
			head = temp;
		}
		else 
		{
			tail->next = temp;
		}
		tail = temp;
	}
	in_Fl.close();
}

void donorlink::updateData()
{
	//get_donor_data();   //TODO : call donor getdata function to load data from file
	Node_Donor* temp = new Node_Donor();
	temp = head;
	ofstream o_Fl("temp.txt");
	//TODO : check wether the id & password extisting or not and if so make the donor enter the new data.
	while (temp != NULL)
	{
		//TODO : Take user id & password for login operation.
		if (temp->doner.ID == loggedin_User.ID && temp->doner.Password == loggedin_User.Password)
		{
			int new_age;
			string new_mail, new_pasword;
			bool new_diseas, new_medicine;
			cout << "   => Enter new age : ";
			cin >> new_age;
			cout << "   => Enter new mail please : ";
			cin >> new_mail;
			cout << "   => Enter new password please : ";
			cin >> new_pasword;
			cout << "   => press 1 if you inured any disease : ";
			cin >> new_diseas;
			cout << "   => press 1 if you are take any medicine : ";
			cin >> new_medicine;
			//TODO : store updating data of the doner into node.
			temp->doner.Age = new_age;
			temp->doner.Mail = new_mail;
			temp->doner.Password = new_pasword;
			temp->doner.ha_disease = new_diseas;
			temp->doner.take_medi = new_medicine;
			loggedin_User = temp->doner;
			cout << "\t\t\t*\tData updated successfully   *." << endl;
		}
		//TODO : store the new data in a the donor file.
		
			o_Fl << temp->doner.ID << endl;
			o_Fl << temp->doner.Age << endl;
			o_Fl << temp->doner.Name << endl;
			o_Fl << temp->doner.Mail << endl;
			o_Fl << temp->doner.Password << endl;
			o_Fl << temp->doner.Date_of_last_donation << endl;
			o_Fl << temp->doner.Blood_type << endl;
			o_Fl << temp->doner.Gender << endl;
			o_Fl << temp->doner.take_medi << endl;
			o_Fl << temp->doner.ha_disease << endl;
			temp = temp->next;
	}
	o_Fl.close();
	remove("doner.txt");
	(rename("temp.txt", "doner.txt") == 0) ? cout << "\t\t\t*\tDone   *." << endl : cout << "\t\t\t\tError in rename of files   **." << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}

void donorlink::deleteAccount()
{
	//get_donor_data();          //TODO : call donor getdata function to load data from file.
	Node_Donor* temp = new Node_Donor();
	temp = head;
	ofstream o_Fl("temp.txt");
	//TODO : check wether the id , passoword of the donor already existedif so delete the account .
	while (temp != NULL)
	{
		if (loggedin_User.ID == temp->doner.ID && loggedin_User.Password == temp->doner.Password)
		{
			Node_Donor* del = new Node_Donor();
			del = temp;
			temp = temp->next;
			del = NULL;
			cout << "\t\t\t*\tAccount deleted successfully   *." << endl;
		}
		//TODO : add the data from the node to the file after change.
		if (temp != NULL)
		{
			o_Fl << temp->doner.ID << endl;
			o_Fl << temp->doner.Age << endl;
			o_Fl << temp->doner.Name << endl;
			o_Fl << temp->doner.Mail << endl;
			o_Fl << temp->doner.Password << endl;
			o_Fl << temp->doner.Date_of_last_donation << endl;
			o_Fl << temp->doner.Blood_type << endl;
			o_Fl << temp->doner.Gender << endl;
			o_Fl << temp->doner.take_medi << endl;
			o_Fl << temp->doner.ha_disease << endl;
			temp = temp->next;
		}
	}
	o_Fl.close();
	remove("doner.txt");
	(rename("temp.txt", "doner.txt") == 0) ? cout << "\t\t\t*\tDone   *." << endl : cout << "\t\t\t\tError in rename of files   **." << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}

void donorlink::Donation_request()
{
	User user;
	if (user.check_Doner_Requeset_Validate_level_1() == true && user.check_Doner_Requeset_Validate_level_2() ==true)
	{
		user.insert(loggedin_User.Blood_type);
		user.updateLastDateOfDonation();
		cout << "Donation Operation has Done" << endl;
	}
	else
	{
		cout << "Donor Is Not Suitable For Blood Donation" << endl;
	}
}


