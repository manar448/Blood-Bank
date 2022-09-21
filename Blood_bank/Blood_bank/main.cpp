#include<iostream>
#include <fstream>
#include<string.h>
#include "User.h"
#include "Doner.h"
#include "Recipient.h"
#include "Blood.h"
#include "main.h"
using namespace std;

bool main_flag = true;    //TODO : flag to end the programe.
User loggedin_User;      //TODO : obj to catch user data who (loggedin or registed) along the programe.

//Global objects
donorlink donner;
recipientlink recipint;
Bloodlink b;
User user;

int main()
{   
	do {
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "\t\t***\tBlood Bank Management System\t***" << endl;
		cout << "-------------------------------------------------------------------------------" << endl << endl;
		//TODO : classify user as doner ,recipient or admin.
        int choice;
		cout << "  1) ==> Donner :" << endl;
		cout << "  2) ==> Recipient :" << endl; 
		cout << "  3) ==> Admin :" << endl;
		cout << "  4) ==> Exit :" << endl << endl << "\t";
		cin >> choice;
		cout << endl;
		//TODO: call all files data 
		donner.get_donor_data();
	    recipint.get_Recipient_data();
	    b.get_blood_data();

		//TODO : log in (his or her) account or register a new account.
        bool menue = true;
		while (menue != false)
		{
			
			int user_choice;
			cout << "  1) ==> IF new user , Make Registeration . " << endl;
			cout << "  2) ==> IF already existed user , log in. " << endl;
			cout << "\n\t";
			cin >> user_choice;
			cout << endl;

			//User newuser;
			if (user_choice == 1) 
			{
				if (User::registration(choice) == true)
				{
					menue = false;
					continue;
				}
			}
			else if(user_choice == 2)
			{
				if (User::login(choice) == true)
				{
					menue = false;
					continue;
				}
			}
		}
		//TODO : Treat  user as a doner.
		if (choice == 1)
		{   
			bool doner = true; //TODO : flag to end doner tour.
			do {
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << "\t\t***\tDoner Operation\t***" << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				
				//TODO : show doner operation menu 
				int Operation;
				cout << "1) ==> Donation request" << endl;
				cout << "2) ==> Update your data" << endl;
				cout << "3) ==> Delete account" << endl;
				cout << "4) ==> Go to home menu" << endl << endl << "\t";
				cin >> Operation;
				cout << endl;

				//TODO : call chosen operation .
				switch (Operation)
				{
					case 1:
						donner.Donation_request();
						break;
					case 2:
						donner.updateData();
						break;
					case 3:
						donner.deleteAccount();
						doner = false;
						break;
					case 4:
						doner = false;
						break;
				}
			} while (doner==true);
		}
		//TODO : Treat  user as a recipient.
		else if (choice == 2)
		{
			bool recipient = true; //TODO : flag to end recipient tour.
			do {
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << "\t\t***\tRecipient Operation\t***" << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl << "\t";
				
				//TODO : show recipient operation menu.
				int operation;
				cout << endl;
				cout << "1) ==> Update your data" << endl;
				cout << "2) ==> Delete account" << endl;
				cout << "3) ==> Search for the availability of blood type" << endl;
				cout << "4) ==> Display all blood data" << endl;
				cout << "5) ==> Request the blood type and quantity she wants and confirm about the hospital" << endl;
				cout << "6) ==> Go to home menu" << endl << endl << "\t";
				cin >> operation;
				
				//TODO : call chosen operation .
				switch (operation)
				{
				case 1:
					recipint.updateData();
					break;
				case 2:
					recipint.deleteAccount();
					recipient = false;
					break;
				case 3:
					recipint.bloodType_availabilitySearch(loggedin_User.Blood_type);
					break;
				case 4:
					recipint.display_All_Blood_Data();
					break;
				case 5:
					recipint.recipient_Request(loggedin_User.Blood_type);
					break;
				case 6:
					recipient=false;
					break;
				}
			} while (recipient==true);
		}
		//TODO : Treat  user as a Admin.
		else if (choice == 3)
		{
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "\t\t***\tAdmin Operation\t***" << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
			bool admin_flag = true;
			do {
				//TODO : show doner operation menu 
				int Operation;
				cout << "  1) ==> Insert New User :" << endl;
				cout << "  2) ==> Update User data :" << endl;
				cout << "  3) ==> Delete User account :" << endl;
				cout << "  4) ==>  Display User data :" << endl;
				cout << "  5) ==> Insert New blood bag :" << endl;
				cout << "  6) ==> Update blood data :" << endl;
				cout << "  7) ==> Delete blood bag :" << endl;
				cout << "  8) ==>  Display blood data" << endl;
				cout << "  9) ==> Go to home menu" << endl << endl << "\t";
				cin >> Operation;
				cout << endl;

				//TODO : Ask for requred data.
				int user_choice;
				string new_blood;
				if (Operation != 5 )
				{
					cout << "  => What type of Users do you want ?" << endl;
					cout << "  => For doner press 1 :" << endl;
					cout << "  => For recipient press 2:" << endl;
					cout << "  => For Blood press 3:" << endl << endl << "\t";
					cin >> user_choice;
					cout << endl;
				}
				else if (Operation == 5)
				{
                    cout<<"  =>Enter Blood type :";
					cin >> new_blood;
				}

				
				//TODO : call chosen operation .
				switch (Operation)
				{
				case 1:
					user.registration(user_choice);
					break;
				case 2:
					user.updateData(user_choice);
					break;
				case 3:
					user.deleteData(user_choice);
					break;
				case 4:
					user.display(user_choice);
					break;
				case 5:
					user.insert(new_blood);
					break;
				case 6:
					user.updateData(user_choice);
					break;
				case 7:
					user.deleteData(user_choice);
					break;
				case 8:
					user.display(user_choice);
					break;
				case 9:
					admin_flag = false;
					break;

				}
			} while (admin_flag != false);
		}
		//TODO : End the programe .
		else if(choice == 4)
		{
			main_flag = false;
			cout << "\t\t***\tEnd of the program \t***" << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	} while (main_flag == true);
	return 0;
}