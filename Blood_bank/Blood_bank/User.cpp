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
int id;
string pass;
time_t t = time(0);

User::User()
{
	ID = 0;
	Age = 0;
	Name =Mail=Password=Blood_type= "";
	Gender ='m';
}

bool User::registration(int user_choice)
{
	bool registration_flag = true;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t***\tRegistration Form\t***" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	int choise = user_choice;        //TODO : classify user as doner ,recipient or admin.
	int user_id, user_age;
	string user_name, user_mail, user_password, user_bloodType;
	char user_gender;
	//TODO : Put a random id for user.
	srand(t);
	user_id = 1000 + rand() % 10000;
	//TODO : Ask user about (his/her) basic data.
	cout << "   => Enter your age :";
	cin >> user_age;
	cout << "   => Enter your name :";
	cin >> user_name;
	cout << "   => Enter your mail :";
	cin >> user_mail;
	cout << "   => Enter your password for your account :";
	cin >> user_password;
	cout << "   => Enter your Blood type Upper Case:";
	cin >> user_bloodType;
	cout << "   => Enter your Gender :";
	cin >> user_gender;

	//TODO : Treat  user as a doner.
	if (choise == 1)
	{
		//TODO : Ask doner about (his/her) needed data.
		string user_date_of_last_donation;
		bool user_disease;
		cout << "   => Enter date or your last donation (dd/mm/yyyy):" << endl;
		cout << "   => If it the first time write (ND):";
		cin >> user_date_of_last_donation;
		cout << "   If you suffers from any disease  press 1  if no press 0 :" << endl;
		cout << "  [blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis] :";
		cin >> user_disease;
		cout << endl;

		//TODO : store registration data of the doner into node.
		Node_Donor* temp = new Node_Donor();
		temp->doner.ID = user_id;
		temp->doner.Age = user_age;
		temp->doner.Name = user_name;
		temp->doner.Mail = user_mail;
		temp->doner.Password = user_password;
		temp->doner.Date_of_last_donation = user_date_of_last_donation;
		temp->doner.Blood_type = user_bloodType;
		temp->doner.Gender = user_gender;
		temp->doner.ha_disease = user_disease;
		temp->doner.take_medi = user_disease;

		loggedin_User = temp->doner;    //TODO : Make obj to hold registed doner data  along the programe.

		ofstream out_Fl;
		out_Fl.open("doner.txt", ios::app);
		//TODO : Check if the doner file is opened successfully or not.
		if (out_Fl.fail())
		{
			cout << "The File was not opened successfully check that the file exist\n";
			exit(1);
		}
		//TODO : Check if the doner  is safe then add her data and (his/her) data is acceptable.
		else 
		{
			if (temp->doner.ha_disease == false && temp->doner.take_medi == false && (validation(user_id, user_password, user_mail, choise) == true))
			{
				out_Fl << temp->doner.ID << "\n" << temp->doner.Age << "\n" << temp->doner.Name << "\n" << temp->doner.Mail << "\n" << temp->doner.Password << "\n";
				out_Fl << temp->doner.Date_of_last_donation << "\n" << temp->doner.Blood_type << "\n" << temp->doner.Gender << "\n" << temp->doner.take_medi << "\n" << temp->doner.ha_disease;
				out_Fl << endl;
				out_Fl.close();
				registration_flag = true;
				cout << "\t\t\t*\tRegistration successfully   *." << endl;
				cout << "\t\t\t***\tyour Id :   " << loggedin_User.ID << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
			}
			//TODO : Change registration_flag if the doner  is not safe or (his/her) data is unacceptable.
			else
			{
				registration_flag = false;
			}
		}
		//TODO : inform the doner that (his/her) registration is failed.
		if (registration_flag == false)
		{
			cout << "Soury You Can't Register Cause You Infected Or Your ID Exist Befor." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}
	//TODO : Treat  user as a recipient.
	else if (choise == 2)
	{
		//TODO : Ask doner about (his/her) needed data.
		string user_hospital, user_doctor;
		cout << "   => Enter  hospital  (place where you are available) :";
		cin >> user_hospital;
		cout << "   => Enter name of your doctor : ";
		cin >> user_doctor;
		cout << endl;

		//TODO : store registration data of the recipient into node.
		Node_Recipient* temp = new Node_Recipient();
		temp->recipient.ID = user_id;
		temp->recipient.Age = user_age;
		temp->recipient.Name = user_name;
		temp->recipient.Mail = user_mail;
		temp->recipient.Password = user_password;
		temp->recipient.Blood_type = user_bloodType;
		temp->recipient.Gender = user_gender;
		temp->recipient.hospital = user_hospital;
		temp->recipient.doctorOfCase = user_doctor;

		loggedin_User = temp->recipient;           //TODO : Make obj to hold registed recipient data  along the programe.

		ofstream out_Fl;
		out_Fl.open("recipient.txt", ios::app);
		//TODO : Check if the recipient file is opened successfully or not.
		if (out_Fl.fail())
		{
			cout << "The File was not opened successfully check that the file eixst\n";
			exit(1);
		}
		//TODO : Check if the recipient  (his/her) data is acceptable and add them into file.
		else 
		{
			if (validation(user_id, user_password, user_mail, choise) == true)
			{
				out_Fl << temp->recipient.ID << "\n" << temp->recipient.Age << "\n" << temp->recipient.Name << "\n" << temp->recipient.Mail << "\n" << temp->recipient.Password << "\n";
				out_Fl << temp->recipient.Blood_type << "\n" << temp->recipient.Gender << "\n" << temp->recipient.doctorOfCase << "\n" << temp->recipient.hospital;
				out_Fl << endl;
				out_Fl.close();
				registration_flag = true;
				cout << "\t\t\t*\tRegistration successfully   *." << endl;
				cout << "\t\t\t***\tyour Id :   " << loggedin_User.ID << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
			}
			//TODO : Change registration_flag if the recipient  is not safe or (his/her) data is unacceptable.
			else
			{
				registration_flag = false;
			}
		}
		//TODO : inform the recipient that (his/her) registration is failed.
		if (registration_flag == false)
		{
			cout << "Soury You Can't Register Cause You Infected Or Your ID Exist Befor." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}

	return registration_flag;
}

bool User::validation(int valid_id, string valid_pass, string valid_mail, int user_choice)
{
	bool validation_falg = true;
	int ch = user_choice;       //TODO : varible to classify user as doner or recipient.
	//TODO : treat user as doner .
	if (ch == 1)
	{
		donorlink b;
		//b.get_donor_data(); //TODO : calling the donor getdata function the load date.
		Node_Donor* temp = b.head;
		//TODO : check wether the donor have account or not.
		while (temp != NULL) 
		{
			if (temp->doner.ID == valid_id || temp->doner.Password == valid_pass || temp->doner.Mail == valid_mail)
			{
				cout << "ID , Password and Mail Already Exist Try Something Else.";
				validation_falg = false;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	//TODO : treat user as recipient .
	else if (ch == 2)
	{
		recipientlink r;
		//r.get_Recipient_data();      //TODO : calling the recipient getdata function the load date.
		Node_Recipient* temp = new Node_Recipient();
		temp = r.head;
		//TODO : check wether the recipient have account or not.
		while (temp != NULL) 
		{
			if (temp->recipient.ID == valid_id || temp->recipient.Password == valid_pass || temp->recipient.Mail == valid_mail)
			{
				cout << "ID , Password or Mail Already Exist Try Something Else.";
				validation_falg = false;
				break;
			}
			temp = temp->next;
		}

	}
	return validation_falg;
}

bool User::login(int user_choice)
{
	bool login_flag = true;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t***\tlogin Form\t***" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	int choise = user_choice;   //TODO : varible to classify user as doner , recipient or admin.

	//TODO : Take user id & password for login operation.
	cout << "   => Enter your id please : ";
	cin >> id;
	cout << "   => Enter your password please : ";
	cin >> pass;
	cout << endl;

	//TODO : treat user as doner .
	if (choise == 1)
	{
		donorlink d;
		d.get_donor_data();
		Node_Donor* temp = new Node_Donor();
		temp = d.head;
		//TODO: loop over the doners and check for id and password.
		while (temp != NULL)
		{
			//TODO : Check if the doner id and password are correct.
			if (temp->doner.ID == id && temp->doner.Password == pass)
			{
				cout << "\t\t\t*\tLogin successfully   *." << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				loggedin_User = temp->doner;  //TODO : object to hold loggedin doner data through the program.
				login_flag = true;
				break;
			}
			//TODO : Change login_flag if the doner  data is not found.
			else
			{
				login_flag = false;
			}
			temp = temp->next;
		}
		//TODO : inform the doner that (his/her) login is failed.
		if (login_flag == false)
		{
			cout << "\t\t\tCan't find your account try again." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}
	//TODO : treat user as recipient.
	else if (choise == 2)
	{
		recipientlink r;
		r.get_Recipient_data();
		Node_Recipient* temp = new Node_Recipient();
		temp = r.head;
		//TODO: loop over the recipient and check for id and password.
		while (temp != NULL)
		{
			//TODO : Check if the recipient  id and password are correct.
			if (temp->recipient.ID == id && temp->recipient.Password == pass) {
				cout << "\t\t\t*\tLogin successfully   *." << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				loggedin_User = temp->recipient;  //TODO : object to hold loggedin recipient data through the program.
				login_flag = true;
				break;
			}
			//TODO : Change login_flag if the recipient  data is not found.
			else
			{
				login_flag = false;
			}
			temp = temp->next;
		}
		//TODO : inform the recipient that (his/her) registration is failed.
		if (login_flag == false)
		{
			cout << "\t\t\tCan't find your account try again." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}
	//TODO : treat user as admin.
	else if (choise == 3)
	{
		//TODO : Check if the admin  id and password are correct.
		if (id == 202017854 && pass == "Manar2468")
		{
			cout << "\t\t\t*\tLogin successfully   *." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
			login_flag = true;
		}
		//TODO : Change login_flag if the admin data is not found.
		else
		{
			login_flag = false;
		}
		//TODO : inform the admin that (his/her) login is failed.
		if (login_flag == false)
		{
			cout << "\t\t\tCan't find your account try again." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}

	return login_flag;
}

void User::updateData(int userChoice)
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t***\tUpdate Form\t***" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	int choise = userChoice;   //TODO : varible to classify user as doner or recipient.

	//TODO : Take user id & password for update operation.
	if (choise != 3)
	{
		cout << "   => Enter your id please : ";
		cin >> id;
		cout << "   => Enter your password please : ";
		cin >> pass;
		cout << endl;
	}
	//TODO : treat user as doner .
	if (choise == 1)
	{
		donorlink d;
		d.get_donor_data();   //TODO : call donor getdata function to load data from file
		Node_Donor* temp = new Node_Donor();
		temp = d.head;
		ofstream o_Fl("temp.txt");
		//TODO : check wether the id & password extisting or not and if so make the donor enter the new data.
		while (temp != NULL)
		{
			if (id == temp->doner.ID && pass == temp->doner.Password)
			{
				string new_mail, new_pasword, new_donation_date;
				int new_age;
				bool new_diseas, new_medicine;
				cout << "   => Enter new age please : ";
				cin >> new_age;
				cout << "   => Enter new mail please : ";
				cin >> new_mail;
				cout << "   => Enter new password please : ";
				cin >> new_pasword;
				cout << "   => press 1 if you inured any disease : ";
				cin >> new_diseas;
				cout << "   => press 1 if you are take any medicine : ";
				cin >> new_medicine;
				cout << "   => Enter last update of donation date: ";
				cin >> new_donation_date;
				//TODO : store updating data of the doner into node.
				temp->doner.Age = new_age;
				temp->doner.Mail = new_mail;
				temp->doner.Password = new_pasword;
				temp->doner.ha_disease = new_diseas;
				temp->doner.take_medi = new_medicine;
				temp->doner.Date_of_last_donation = new_donation_date;
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
	//TODO : treat user as reciptient .
	else if (choise == 2)
	{
		recipientlink recipient;
		//recipient.get_Recipient_data();      //TODO : call reciptient getdata function to load data from file
		Node_Recipient* temp2 = new Node_Recipient();
		temp2 = recipient.head;
		ofstream o_Fl_2("temp.txt");
		//TODO : check wether id & password of the recipietent exist .
		while (temp2 != NULL)
		{
			if (id == temp2->recipient.ID && pass == temp2->recipient.Password)
			{
				int new_age;
				string new_mail, new_password, new_hospital, new_doctor;
				cout << "   => Enter new age please : ";
				cin >> new_age;
				cout << "   => Enter new password please : ";
				cin >> new_password;
				cout << "   =>  Enter new hospital please: ";
				cin >> new_hospital;
				cout << "   => Enter new doctor please : ";
				cin >> new_doctor;
				//TODO : store the new data in a node.
				temp2->recipient.Age = new_age;
				temp2->recipient.Mail = new_mail;
				temp2->recipient.Password = new_password;
				temp2->recipient.hospital = new_hospital;
				temp2->recipient.doctorOfCase = new_doctor;
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
	//TODO : Update Data of blood.
	else if (choise == 3)
	{
		string bloodType, reciveDate, expiryDate;
		cout << "  =>Enter Blood type :";
		cin >> bloodType;
		cout << "  =>Enter Receive date :";
		cin >> reciveDate;
		cout << "  =>Enter Expire date :";
		cin >> expiryDate;
		cout<<endl;
		Bloodlink blood;
		//blood.get_blood_data();      //TODO : call blood getdata function to load data from file
		Node_Blood* temp = new Node_Blood();
		temp = blood.head;
		ofstream o_Fl_2("temp.txt");
		//TODO : check wether bloodType , reciveDate and expiryDate of the blood bag is exist .
		while (temp != NULL)
		{
			if (bloodType == temp->blood.type && reciveDate == temp->blood.Received_date && expiryDate == temp->blood.Expiry_date)
			{
				string  updated_recive_date, updated_expiry_date;
				cout << "  =>Enter updated Receive date :";
				cin >> updated_recive_date;
				cout << "  =>Enter updated Expire date :";
				cin >> updated_expiry_date;
				//TODO : store the new data in a node
				temp->blood.Received_date = updated_recive_date;
				temp->blood.Expiry_date = updated_expiry_date;
				cout << "\t\t\t*\Blood bad has been updated successfully   *." << endl;
			}
			//TODO : store the new data in a the blood file.
				o_Fl_2 << temp->blood.type << endl;
				o_Fl_2 << temp->blood.Received_date << endl;
				o_Fl_2 << temp->blood.Expiry_date << endl;
				temp = temp->next;
		}
		o_Fl_2.close();
		remove("blood.txt");
		(rename("temp.txt", "blood.txt") == 0) ? cout << "\t\t\t*\tDone   *." << endl : cout << "\t\t\t\tError in rename of files   **." << endl;
		cout << "-------------------------------------------------------------------------------" << endl << endl;
	}
} 

void User::deleteData(int chose)
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t***\tDelete Form\t***" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	int choose = chose;               //TODO : varible to classify user as doner or recipient .

	//TODO : Take user id & password for login operation.
	if (choose != 3 )
	{
		cout << "   => Enter user id please : ";
		cin >> id;
		cout << "   => Enter user password please : ";
		cin >> pass;
		cout << endl;
	}
	//TODO : Delete the doner account.
	if (choose == 1)
	{
		donorlink d;
		//d.get_donor_data();          //TODO : call donor getdata function to load data from file.
		Node_Donor* temp = new Node_Donor();
		temp = d.head;
		ofstream o_Fl("temp.txt");
		//TODO : check wether the id , passoword of the donor already existedif so delete the account .
		while (temp != NULL)
		{
			if (id == temp->doner.ID && pass == temp->doner.Password)
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
	//TODO : Delete the reciptient account.
	else if (choose == 2)
	{
		recipientlink r;
		//r.get_Recipient_data();       //TODO : call reciptient getdata function to load data from file.
		Node_Recipient* temp = new Node_Recipient();
		temp = r.head;
		ofstream o_Fl("temp.txt");
		//TODO : check wether the id , passoword of the reciptient already existedif so delete the account .
		while (temp != NULL)
		{
			if (id == temp->recipient.ID && pass == temp->recipient.Password)
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
		cout << "-------------------------------------------------------------------------------" << endl << endl;
	}
	//TODO : Delete a blood bag.
	else if (choose == 3)
	{
		string bloodType, reciveDate, expiryDate;
		cout << "  =>Enter Blood type :";
		cin >> bloodType;
		cout << "  =>Enter Receive date :";
		cin >> reciveDate;
		cout << "  =>Enter Expire date :";
		cin >> expiryDate;
		cout <<endl;
		Bloodlink blood;
		//blood.get_blood_data();      //TODO : call blood getdata function to load data from file
		Node_Blood* temp = new Node_Blood();
		temp = blood.head;
		ofstream o_Fl_2("temp.txt");
		//TODO : check wether id & password of the recipietent exist .
		while (temp != NULL)
		{
			if (bloodType == temp->blood.type && reciveDate == temp->blood.Received_date && expiryDate == temp->blood.Expiry_date)
			{
				Node_Blood* del = new Node_Blood();
				del = temp;
				temp = temp->next;
				del = NULL;
				cout << "\t\t\t*\Blood bag has been updated successfully   *." << endl;
			}
			//TODO : store the new data in a the reciptient file.
			if (temp != NULL)
			{
				o_Fl_2 << temp->blood.type << endl;
				o_Fl_2 << temp->blood.Received_date << endl;
				o_Fl_2 << temp->blood.Expiry_date << endl;
				temp = temp->next;
			}
		}
		o_Fl_2.close();
		remove("blood.txt");
		(rename("temp.txt", "blood.txt") == 0) ? cout << "\t\t\t*\tDone   *." << endl : cout << "\t\t\t\tError in rename of files   **." << endl;
		cout << "-------------------------------------------------------------------------------" << endl << endl;
	}
}

void User::display(int chose)
{
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << setw(50) << "***\tDisplay Form\t ***" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	int choice = chose; //TODO : varible to classify user as doner or recipient .

	//TODO : Take user id & password for login operation.
	if (choice != 3)
	{
		cout << "   => Enter user id please : ";
		cin >> id;
		cout << "   => Enter user password please : ";
		cin >> pass;
		cout << endl;
	}
	//TODO : Display the doner data.
	if (choice==1)
	{
		donorlink doner;
		//doner.get_donor_data();
		Node_Donor* temp = new Node_Donor();
			temp = doner.head;
			cout << "--------------------------------------------------------------------------------"<< endl;
			cout << setw(50) << "\"Donor Data\""<<endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			//TODO: loop over the doners .
			while (temp != NULL) 
			{
				//TODO : Check if the doner data is correct.
				if (id == temp->doner.ID && pass == temp->doner.Password)
				{
					cout << setw(20) << "ID :"       << setw(10) << temp->doner.ID << setw(10) << endl
						 << setw(20) << "Age :"      << setw(10)<< temp->doner.Age << setw(10) << endl
						 << setw(20) << "Name :"     << setw(10) << temp->doner.Name << setw(10) << endl
						 << setw(20) << "Mail :"     << setw(10) << temp->doner.Mail << setw(10) << endl
						 << setw(20) << "Password :" << setw(10) << temp->doner.Password<< setw(10) <<endl
						 << setw(20) << "Last Donation  :" << setw(10) << temp->doner.Date_of_last_donation << setw(10) << endl
						 << setw(20) << "BLood Type :" << setw(10) << temp->doner.Blood_type << setw(10) << endl
						 << setw(20) << "Take Medicine :"<< setw(10) << temp->doner.take_medi << setw(10) << endl
						 << setw(20) << "Has Disease :" << setw(10) << temp->doner.ha_disease << setw(10) << endl;
					cout << "-----------------------------------------------------------------------" << endl;
					break;
				}
				temp = temp->next;
			}
	}
	//TODO : Display the recipient data.
	else if(choice==2)
	{
		recipientlink recipient;
		//recipient.get_Recipient_data();
		Node_Recipient* temp = new Node_Recipient();
			temp = recipient.head;
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << setw(50) << "\" Reciptient Data\"" <<endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			//TODO: loop over the recipients.
			while (temp != NULL) 
			{
				//TODO : Check if the doner data is correct.
				if (id == temp->recipient.ID && pass == temp->recipient.Password)
				{
					cout << setw(20) << "ID :" << setw(10) << temp->recipient.ID << setw(10) << endl
						<< setw(20) << "Age :" << setw(10) << temp->recipient.Age << setw(10) << endl
						<< setw(20) << "Name :" << setw(10) << temp->recipient.Name << setw(10) << endl
						<< setw(20) << "Mail :" << setw(10) << temp->recipient.Mail << setw(10) << endl
						<< setw(20) << "Password :" << setw(10) << temp->recipient.Password << setw(10) << endl
						<< setw(20) << "Doctor :" << setw(10) << temp->recipient.doctorOfCase << setw(10) << endl
						<< setw(20) << "BLood Type :" << setw(10) << temp->recipient.Blood_type << setw(10) << endl
                        << setw(20) << "Hospital :" << setw(10) <<  temp->recipient.hospital << setw(10) << endl;
					cout << "--------------------------------------------------------------------------" << endl;
				}
				temp = temp->next;
			}
	}
	//TODO : Display the blood data.
	else if (choice == 3)
	{
		recipientlink data;
		data.display_All_Blood_Data();
	}
} 

string User::rececivedDate()
{
	const int MAXLEN = 80;
	char ToDay[MAXLEN];
#pragma warning( disable : 4996 )
	strftime(ToDay, MAXLEN, "%d/%m/%Y", localtime(&t));   //TODO : Calculate the currten day.
	string receciveDay = (string)ToDay;                   //TODO : Convert rececive day into string.
	return receciveDay;
}

string User::expireDate()
{
	string expire_day;
	string rececive_day = rececivedDate();
	int day, month, year;
	day = stoi(rececive_day.substr(0, 2));
	month = stoi(rececive_day.substr(3, 6));
	year = stoi(rececive_day.substr(6, 9));
	if ((day + 15) > 30)
	{
		if ((month + 1) >= 1 && (month + 1) <= 9)
		{
			int temp = day - 15;
			if (temp >= 1 && temp <= 9)
				expire_day = "0" + to_string(day - 15) + "/0" + to_string(month + 1) + "/" + to_string(year);
			else
				expire_day = to_string(day - 15) + "/0" + to_string(month + 1) + "/" + to_string(year);
		}
		else
		{
			int temp = day - 15;
			if (temp >= 1 && temp <= 9)
				expire_day = "0" + to_string(day - 15) + "/" + to_string(month + 1) + "/" + to_string(year);
			else
				expire_day = to_string(day - 15) + "/" + to_string(month + 1) + "/" + to_string(year);
		}
	}
	else
	{
		if ((month) >= 1 && (month) <= 9)
		{
			expire_day = to_string(day + 15) + "/0" + to_string(month) + "/" + to_string(year);
		}
		else
		{
			expire_day = to_string(day + 15) + "/" + to_string(month) + "/" + to_string(year);
		}
	}
	return expire_day;
}

void User::insert(string bloodType)
{
	Node_Blood* temp = new Node_Blood();
	temp->blood.type = bloodType;
	temp->blood.Received_date = rececivedDate();
	temp->blood.Expiry_date = expireDate();

	ofstream o_Fl;
	o_Fl.open("blood.txt", ios::app);
	//TODO : Check if the doner file is opened successfully or not.
	if (o_Fl.fail())
	{
		cout << "The File was not opened successfully check that the file exist\n";
		exit(1);
	}
	//TODO : store a new blood bag in the blood file
	else
	{
		o_Fl << temp->blood.type << endl;
		o_Fl << temp->blood.Received_date << endl;
		o_Fl << temp->blood.Expiry_date << endl;
		cout << "\t\t\t*\Blood bag has been inserted successfully   *." << endl;
	}
	o_Fl.close();
}

string User::get_Date_of_last_donation()
{
	donorlink doner;
	doner.get_donor_data(); 
	Node_Donor* temp = new Node_Donor();
	temp = doner.head;
	while (temp != NULL)
	{
		if (loggedin_User.ID == temp->doner.ID && loggedin_User.Password == temp->doner.Password)
		{
			return temp->doner.Date_of_last_donation;
		}
		else
		{
			temp = temp->next;
		}
	}
}

bool User::checkDateOfLastestDonation()
{
	bool Donation_flag;
	if (loggedin_User.get_Date_of_last_donation() == "ND") { Donation_flag = true; }
	else
	{
		//TODO : split date Of Lastest Donation into day , month and year.
		int day, month, year;
		day = stoi(loggedin_User.get_Date_of_last_donation().substr(0, 2));
		month = stoi(loggedin_User.get_Date_of_last_donation().substr(3, 2));
		year = stoi(loggedin_User.get_Date_of_last_donation().substr(6));

		//TODO : Get Currten date .
		time_t now;
		struct tm nowLocal;
		now = time(NULL);
#pragma warning( disable : 4996 )
		nowLocal = *localtime(&now);
		cin.get();

		//TODO : check Date Of Lastest Donation .
		if (nowLocal.tm_year + 1900 > year)
		{
			if ((abs(month - nowLocal.tm_mon + 1) >= 3) || (month <= nowLocal.tm_mon + 1))
			{
				Donation_flag = true;
				cout << "Enough Time To Donate." << endl;
			}
			else
			{
				Donation_flag = false;
				cout << "Not Enough Time To Donate." << endl;
			}
		}
		else if (nowLocal.tm_year + 1900 == year)
		{
			if (abs(nowLocal.tm_mon + 1 - month) >3)
			{
				Donation_flag = true;
				cout << "Enough Time To Donate." << endl;
			}
			else if (abs(nowLocal.tm_mon + 1 - month) == 3)
			{
				if (nowLocal.tm_mday +1 >= day)
				{
					Donation_flag = true;
					cout << "Enough Time To Donate." << endl;
				}
				else
				{
					Donation_flag = false;
					cout << "Not Enough Time To Donate." << endl;
				}
			}
			else
			{
				Donation_flag = false;
				cout << "Not Enough Time To Donate." << endl;
			}
		}
		//TODO : Avoid future date.
		else
		{
			Donation_flag = false;
			cout << "Not Enough Time To Donate." << endl;
		}
	}
	return Donation_flag;
}

bool User::check_Doner_disease_and_medicine()
{
	bool flag = true;
	donorlink donner;
	donner.get_donor_data();
	Node_Donor* temp = new Node_Donor();
	temp = donner.head;
	while (temp != NULL)
	{
		if (loggedin_User.ID == temp->doner.ID && loggedin_User.Password == temp->doner.Password)
		{
			if (temp->doner.ha_disease == 1 || temp->doner.take_medi == 1)
			{
				flag = false;
				return flag;
			}
			else
			{
				flag = true;
				return flag;
			}
		}
		else
		{
			temp = temp->next;
		}

	}
	return flag;

}

bool User::check_Doner_Requeset_Validate_level_1()
{
	bool Validate_flag = true;
	if ((loggedin_User.Age < 17 || loggedin_User.Age > 60) || (checkDateOfLastestDonation() == false) || (check_Doner_disease_and_medicine() == false))
	{
		cout << "\t\t\tUnacceptable doner !" << endl;
		Validate_flag = false;
		return Validate_flag;
	}
	return Validate_flag;
}

bool User::check_Doner_Requeset_Validate_level_2()
{
	bool flag;
	double weight, hemoglobin_ratio, heartBeat, temprature, blood_pressure;
	cout << "Enter your weight :" << endl;
	cin >> weight;
	if (weight <= 50)
	{
		flag = false;
		return flag;
	}
	else
	{
		flag = true;
	}
	cout << "Enter your hemoglobin_ratio :" << endl;
	cin >> hemoglobin_ratio;
	if (loggedin_User.Gender == 'm' && (hemoglobin_ratio < 14 || hemoglobin_ratio > 17))
	{
		flag = false;
		return flag;
	}
	else
	{
		flag = true;
	}
	if (loggedin_User.Gender == 'f' && (hemoglobin_ratio < 12 || hemoglobin_ratio > 14))
	{
		flag = false;
		return flag;
	}
	else
	{
		flag = true;
	}
	cout << "Enter your heartBeat & blood pressure:" << endl;
	cin >> heartBeat >> blood_pressure;
	if ((heartBeat <= 50 || heartBeat >= 100) && (blood_pressure > (80 / 120)))
	{
		flag = false;
		return flag;
	}
	else
	{
		flag = true;
	}
	cout << "Enter your temprature:" << endl;
	cin >> temprature;
	if (temprature > 37)
	{
		flag = false;
		return flag;
	}
	else
	{
		flag = true;
	}

	return flag;
}

void User::updateLastDateOfDonation()
{
	bool found = true;
	donorlink d;
	d.get_donor_data();
	Node_Donor* temp = new Node_Donor();
	temp = d.head;
	ofstream o_Fl("temp.txt");
	while (temp != NULL)
	{
		if (temp->doner.ID == loggedin_User.ID && temp->doner.Password == loggedin_User.Password)
		{
			temp->doner.Date_of_last_donation = d.rececivedDate();
			cout << "\t\t***\tDoner date of last donation has been updated successfully   ***." << endl;
			found = true;
		}
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
	(rename("temp.txt", "doner.txt") == 0) ? cout << "\t\t\t***\tDone   ***." << endl : cout << "\t\t\t***\tError in rename of files   ***." << endl;
}

void User::delete_blood(string bloodType, int quantity)
{
	Bloodlink blood;
	//blood.get_blood_data();
	int counter = quantity;
	Node_Blood* temp = new Node_Blood();
	temp = blood.head;
	ofstream o_F("temp.txt");
	//TODO: loop over the blood bags and check for blood type
	while (temp != NULL)
	{
		if (temp->blood.type == bloodType)
		{
			//TODO: loop over the blood type until delete all required quantity.
			while (counter != 0)
			{
				Node_Blood* del = new Node_Blood();
				del = temp;
				temp = temp->next;
				del = NULL;
				counter--;
				break;
			}
		}
		if (temp != NULL)
		{
			o_F << temp->blood.type << endl;
			o_F << temp->blood.Received_date << endl;
			o_F << temp->blood.Expiry_date << endl;
			temp = temp->next;
		}
	}
	o_F.close();
	remove("blood.txt");
	(rename("temp.txt", "blood.txt") == 0) ? cout << "\t\t\t***\tDone   ***." << endl : cout << "\t\t\t***\tError in rename of files   ***." << endl;
}

void User::delete_blood(string bloodType)
{
	Bloodlink b;
	string blood = bloodType;
	//b.get_blood_data();
	Node_Blood* temp = new Node_Blood();
	temp = b.head;
	ofstream o_F("temp.txt");
	//TODO: loop over the blood bags and check for blood type
	while (temp != NULL)
	{

		if (temp->blood.type == blood)
		{
			Node_Blood* del = new Node_Blood();
			del = temp;
			temp = temp->next;
			del = NULL;
		}
		if (temp != NULL)
		{
			o_F << temp->blood.type << endl;
			o_F << temp->blood.Received_date << endl;
			o_F << temp->blood.Expiry_date << endl;
			temp = temp->next;
		}
	}
	o_F.close();
	remove("blood.txt");
	(rename("temp.txt", "blood.txt") == 0) ? cout << "\t\t\t**\tDone   *." << endl : cout << "\t\t\t*\tError in rename of files   **." << endl;

}





