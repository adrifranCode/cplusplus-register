#pragma once
#include "stdafx.h"
#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
using namespace std;

class AppointmentType // Class Creation
{
private:
	struct AppointmentStructType
	{
		string name; // Variables to be used
		string ID;
		string phoneContact;
		string date;
		string line; // Variable to be used with search function
		string searchKeyword; // Variable to be used with search function
		string testWord; // Variable to be used with search function
		string printDetails; // Variable used with print all function
		string deleteVar;
		char userAnswer;
		int testnum;
		ofstream writefile; // To be used for file handling
		ifstream readfile;

		char userSelection;
		
	};
	AppointmentStructType appinfo;

public:
	AppointmentType(); // Constructor
	void getUserSelection(); // Function Prototypes
	void addAppointment();
	void updateAppointment();
	void printAllAppointments();
	void searchAppointments();
	void deleteAppointments();
	void helpGuide();
	void rexit();


};
