#pragma once
#include<iostream>
#include<string.h>
using namespace std; 
//TODO : class user/admin which holds  Common attribute & function  between each user.
class User 
{
public:
	//TODO : Common attribute between each user.
	int ID, Age;
	string Name, Mail, Password, Blood_type;
	char Gender;

	User();

	//TODO : Create new account for user.
	bool static registration(int);
	//TODO : Allow to user to log in his account.
	bool static login(int);

	//***************************************************
	// *** Bouns function [The user could be an admin]***
	//************************ ***************************
	 
	//TODO : Updates the  user data.
	void updateData(int);
	//TODO :Delete the user account.
	void  deleteData(int);
	//TODO : Display all data of user or blood.
	void display(int);
	//TODO : Inserts the blood bag that was donated.
	void insert(string bloodType);
	//TODO : Delete the blood bag from blood file.
	void delete_blood(string bloodType, int quantity);
	void delete_blood(string bloodType);
	//TODO: Get date of last donation of spacific doner.
	string get_Date_of_last_donation();
	//TODO : check that Last donation date has done at least 3 months before her request.
	bool checkDateOfLastestDonation();
	//TODO : check that if the doner is  suffer from any disease or take medicine .
	bool check_Doner_disease_and_medicine();
	//TODO: Validate the donor’s request.
	bool check_Doner_Requeset_Validate_level_1();

	//************************
	// *** Extra function ***
	//************************
	 
	//TODO : checks that the user has an unique id, maiL and password.
	bool static validation(int, string, string, int);
	//TODO : Returns the date of the day the donation was received.
	string rececivedDate();
	//TODO : Returns the date of the day the donation was expired.
	string expireDate();
	//TODO: Ask doner about weight, hemoglobin ratio , heartBeat, blood pressure, temprature to check that the doner is save 
	bool check_Doner_Requeset_Validate_level_2();
	//TODO : Update date of last donation after each donation.
	void updateLastDateOfDonation();
};