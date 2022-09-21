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

Node_Recipient::Node_Recipient()
{
	Recipient recipient;
	recipient.ID = recipient.Age = 0;
	recipient.Name = recipient.Mail = recipient.Password ="0";
	recipient.Gender = '0';
	recipient.hospital = recipient.doctorOfCase = "";
	next = NULL;
}

recipientlink::recipientlink()
{
	head = tail = NULL;
}

void recipientlink::get_Recipient_data()
{
	ifstream in_Fl("recipient.txt", ios::binary);
	if (in_Fl.fail())
	{
		cout << "The File was not opened successfully check that the file eixst\n";
		exit(1);
	}
	while (true) {
		Node_Recipient* temp = new Node_Recipient();
		in_Fl >> temp->recipient.ID;
		in_Fl >> temp->recipient.Age;
		in_Fl >> temp->recipient.Name;
		in_Fl >> temp->recipient.Mail;
		in_Fl >> temp->recipient.Password;
		in_Fl >> temp->recipient.Blood_type;
		in_Fl >> temp->recipient.Gender;
		in_Fl >> temp->recipient.hospital;
		in_Fl >> temp->recipient.doctorOfCase;
		if (in_Fl.fail()) {
			delete temp;
			break;
		}
		if (head == NULL) {
			head = temp;
		}
		else {
			tail->next = temp;
		}
		tail = temp;
	}
	in_Fl.close();
}

void recipientlink::updateData()
{
	//get_Recipient_data();      //TODO : call reciptient getdata function to load data from file
	Node_Recipient* temp2 = new Node_Recipient();
	temp2 = head;
	ofstream o_Fl_2("temp.txt");
	//TODO : check wether id & password of the recipietent exist .
	while (temp2 != NULL)
	{
		//TODO : Take user id & password for login operation.
		if (temp2->recipient.ID == loggedin_User.ID && temp2->recipient.Password == loggedin_User.Password)
		{
			int new_age;
			string new_mail, new_password, new_hospital, new_doctor;
			cout << "   => Enter new age please : ";
			cin >> new_age;
			cout << "   => Enter new mail please : ";
			cin >> new_mail;
			cout << "   => Enter new password please : ";
			cin >> new_password;
			cout << "   => Enter new doctor please : ";
			cin >> new_doctor;
			cout << "   =>  Enter new hospital please: ";
			cin >> new_hospital;
			//TODO : store the new data in a node.
			temp2->recipient.Age = new_age;
			temp2->recipient.Mail = new_mail;
			temp2->recipient.Password = new_password;
			temp2->recipient.doctorOfCase = new_doctor;
			temp2->recipient.hospital = new_hospital;
			loggedin_User = temp2->recipient;
			cout << "\t\t\t*\tAccount updated successfully   *." << endl;
		}
		//TODO : store the new data in a the reciptient file.
			o_Fl_2 << temp2->recipient.ID << endl;
			o_Fl_2 << temp2->recipient.Age << endl;
			o_Fl_2 << temp2->recipient.Name << endl;
			o_Fl_2 << temp2->recipient.Mail << endl;
			o_Fl_2 << temp2->recipient.Password << endl;
			o_Fl_2 << temp2->recipient.Blood_type << endl;
			o_Fl_2 << temp2->recipient.Gender << endl;
			o_Fl_2 << temp2->recipient.doctorOfCase << endl;
			o_Fl_2 << temp2->recipient.hospital << endl;
			temp2 = temp2->next;
	}
	o_Fl_2.close();
	remove("recipient.txt");
	(rename("temp.txt", "recipient.txt") == 0) ? cout << "\t\t\t*\tDone   *." << endl : cout << "\t\t\t\tError in rename of files   **." << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}

void recipientlink::deleteAccount()
{
	//get_Recipient_data();       //TODO : call reciptient getdata function to load data from file.
	Node_Recipient* temp = new Node_Recipient();
	temp = head;
	ofstream o_Fl("temp.txt");
	//TODO : check wether the id , passoword of the reciptient already existedif so delete the account .
	while (temp != NULL)
	{
		if (loggedin_User.ID == temp->recipient.ID && loggedin_User.Password == temp->recipient.Password)
		{
			Node_Recipient* del = new Node_Recipient();
			del = temp;
			temp = temp->next;
			del = NULL;
			cout << "\t\t\t*\tAccount deleted successfully   *." << endl;
		}
		//TODO : add the data from the node to the file after change.
		if (temp != NULL)
		{
			o_Fl << temp->recipient.ID << endl;
			o_Fl << temp->recipient.Age << endl;
			o_Fl << temp->recipient.Name << endl;
			o_Fl << temp->recipient.Mail << endl;
			o_Fl << temp->recipient.Password << endl;
			o_Fl << temp->recipient.Blood_type << endl;
			o_Fl << temp->recipient.Gender << endl;
			o_Fl << temp->recipient.hospital << endl;
			o_Fl << temp->recipient.doctorOfCase << endl;
			temp = temp->next;
		}
	}
	o_Fl.close();
	remove("recipient.txt");
	(rename("temp.txt", "recipient.txt") == 0) ? cout << "\t\t\t*\tDone   *." << endl : cout << "\t\t\t\tError in rename of files   **." << endl;
}

bool recipientlink::bloodType_availabilitySearch(string blood_type) 
{
	//TODO: get all doners
	Bloodlink donars;
	//donars.get_blood_data();
	Node_Blood *current = new Node_Blood();
	current = donars.head;
	//TODO: loop over the doners and check for blood type
	while (current != NULL) 
	{
		if (current->blood.type == blood_type) 
		{
			cout << "the requested blood type is found " << endl;
			cout << " his Quantity is :" <<donars.Quantity(blood_type)<<endl;
			return true;
		}
		current = current->next;
	}
	cout << "the requested blood type wasn't found" << endl;;
	return false;

}

void recipientlink::display_All_Blood_Data()
{
	Bloodlink bloodlink;
	//bloodlink.get_blood_data();
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(70) << "Display all blood data" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << setw(30) << "The Blood type :" << setw(15) << "A+" << setw(10) << "||" << setw(30) << " The Blood Quantity :" << setw(15) << bloodlink.Quantity("A+") << setw(30) << "\n\n";
	Node_Blood* temp = new Node_Blood();
	temp = bloodlink.head;
	while (temp != NULL) 
	{
		if (temp->blood.type == "A+")
		{
			cout << setw(30) << "The Received date :" << setw(15) << temp->blood.Received_date << setw(10) << "||" << setw(30) << " The Expiry date name :" << setw(15) << temp->blood.Expiry_date << setw(30) << "  \n";
		}
		temp = temp->next;
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << setw(30) << "The Blood type :" << setw(15) << "A-" << setw(10) << "||" << setw(30) << " The Blood Quantity :" << setw(15) << bloodlink.Quantity("A-") << setw(30) << "\n\n";
	temp = bloodlink.head;
	while (temp != NULL) 
	{
		if (temp->blood.type == "A-")
		{
			cout << setw(30) << "The Received date :" << setw(15) << temp->blood.Received_date << setw(10) << "||" << setw(30) << " The Expiry date name :" << setw(15) << temp->blood.Expiry_date << setw(30) << "  \n";
		}
		temp = temp->next;
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << setw(30) << "The Blood type :" << setw(15) << "B+" << setw(10) << "||" << setw(30) << " The Blood Quantity :" << setw(15) << bloodlink.Quantity("B+") << setw(30) << "\n\n";
	temp = bloodlink.head;
	while (temp != NULL) 
	{
		if (temp->blood.type == "B+")
		{
			cout << setw(30) << "The Received date :" << setw(15) << temp->blood.Received_date << setw(10) << "||" << setw(30) << " The Expiry date name :" << setw(15) << temp->blood.Expiry_date << setw(30) << "  \n";
		}
		temp = temp->next;
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << setw(30) << "The Blood type :" << setw(15) << "B-" << setw(10) << "||" << setw(30) << " The Blood Quantity :" << setw(15) << bloodlink.Quantity("B-") << setw(30) << "\n\n";
	temp = bloodlink.head;
	while (temp != NULL) 
	{
		if (temp->blood.type == "B-")
		{
			cout << setw(30) << "The Received date :" << setw(15) << temp->blood.Received_date << setw(10) << "||" << setw(30) << " The Expiry date name :" << setw(15) << temp->blood.Expiry_date << setw(30) << "  \n";
		}
		temp = temp->next;
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << setw(30) << "The Blood type :" << setw(15) << "AB+" << setw(10) << "||" << setw(30) << " The Blood Quantity :" << setw(15) << bloodlink.Quantity("AB+") << setw(30) << "\n\n";
	temp = bloodlink.head;
	while (temp != NULL) {
		if (temp->blood.type == "AB+")
		{
			cout << setw(30) << "The Received date :" << setw(15) << temp->blood.Received_date << setw(10) << "||" << setw(30) << " The Expiry date name :" << setw(15) << temp->blood.Expiry_date << setw(30) << "  \n";
		}
		temp = temp->next;
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << setw(30) << "The Blood type :" << setw(15) << "AB-" << setw(10) << "||" << setw(30) << " The Blood Quantity :" << setw(15) << bloodlink.Quantity("AB-") << setw(30) << "\n\n";
	temp = bloodlink.head;
	while (temp != NULL) 
	{
		if (temp->blood.type == "AB-")
		{
			cout << setw(30) << "The Received date :" << setw(15) << temp->blood.Received_date << setw(10) << "||" << setw(30) << " The Expiry date name :" << setw(15) << temp->blood.Expiry_date << setw(30) << "  \n";
		}
		temp = temp->next;
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << setw(30) << "The Blood type :" << setw(15) << "O+" << setw(10) << "||" << setw(30) << " The Blood Quantity :" << setw(15) << bloodlink.Quantity("O+") << setw(30) << "\n\n";
	temp = bloodlink.head;
	while (temp != NULL) {
		if (temp->blood.type == "O+")
		{
			cout << setw(30) << "The Received date :" << setw(15) << temp->blood.Received_date << setw(10) << "||" << setw(30) << " The Expiry date name :" << setw(15) << temp->blood.Expiry_date << setw(30) << "  \n";
		}
		temp = temp->next;
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << setw(30) << "The Blood type :" << setw(15) << "O-" << setw(10) << "||" << setw(30) << " The Blood Quantity :" << setw(15) << bloodlink.Quantity("O-") << setw(30) << "\n\n";
	temp = bloodlink.head;
	while (temp != NULL) {
		if (temp->blood.type == "O-")
		{
			cout << setw(30) << "The Received date :" << setw(15) << temp->blood.Received_date << setw(10) << "||" << setw(30) << " The Expiry date name :" << setw(15) << temp->blood.Expiry_date << setw(30) << "  \n";
		}
		temp = temp->next;
	}
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
}

void recipientlink::recipient_Request(string blood_type)
{
	Bloodlink blood;
	//TODO: get all doners
	//blood.get_blood_data();
	//TODO: check that the required blood Type is availabe.
	if (bloodType_availabilitySearch(blood_type) == true)
	{
		int quantity;
	    cout << "Enter the requred quantity of blood :";
	    cin >> quantity;
		cout << endl;
		User user;
		//TODO: check if the required blood quantity is availabe.
		if (quantity < blood.Quantity(blood_type))
		{
			user.delete_blood(blood_type, quantity);
			cout << "You Request is accepted ." << endl;
		}
		else if (quantity == blood.Quantity(blood_type))
		{
			user.delete_blood(blood_type);
			cout << "You Request is accepted ." << endl;
		}
		else
		{
			int choice;
			cout << endl;
			cout << "this quantity is not available the available quantity is" << blood.Quantity(blood_type) << endl;
			cout << "if you what to take this quantity press 1 "<< endl;
			cout << "if you what to cancel the request press 2 " << endl;
			cin >> choice;
			if (choice == 1)
			{
				user.delete_blood(blood_type);
			}
			else
			{
				cout << "It's okay ." << endl;
			}
		}
	}
	//TODO: Inform the recipient that (his/her) Request is failed.
	else
	{
		cout << "Your blood type is not available !" << endl;
	}
}


