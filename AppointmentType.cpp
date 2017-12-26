#include "stdafx.h"
#include "AppointmentType.h"
#include<iostream>
#include<string>
#include <windows.h>
#include <fstream>

using namespace std;

AppointmentType::AppointmentType() // Automatically calls functions as well as menu on creation of object in main function
{
	while (true)
	{
		cout << "____________________________________________________________________________________________________"
			<< "\n\n   ********** Welcome to Endsoft Appointment Register 2017! *********"
			<< "\n\n Please type the number from the menu that correlates with the task needed and then press enter."
			<< "\n\n(1.) Add New Appointment" << "\n\n(2.) Update/Edit an Appointment" << "\n\n(3.) Display All Appointments"
			<< "\n\n(4.) Search for an Appointment" << "\n\n(5.) Delete an Appointment" << "\n\n(6.) Help Guide" << "\n\n(7.) Exit"
			<< "\n___________________________________________________________________________________________________\n\n";

		getUserSelection();

	}
}

void AppointmentType::getUserSelection() // To get user input for menu selection
{
	appinfo.userSelection = ' ';
	
	cin >> appinfo.userSelection;

	switch (appinfo.userSelection) // Call functions to follow through with selected task
	{
		case '1':
			addAppointment();
			break;
			
		case '2':
			updateAppointment();
			break;

		case '3':
			printAllAppointments();
			break;
		case '4':
			searchAppointments();
			break;

		case '5':
			deleteAppointments();
			break;

		case '6':
			helpGuide();
			break;

		case '7':
			rexit();
			

	}

	

}

void AppointmentType::addAppointment() // Function to add appointments
{
	
	appinfo.writefile.open("AppointmentData1.txt", ios::app);
	
	if (appinfo.writefile.is_open()) // Checks to see if file is open and gives user instructions
	{
	
		cin.get();
		cout << "Enter the name of the person whose appointment it will be: \n";
		getline(cin, appinfo.name);
		appinfo.writefile << appinfo.name << endl;
		cout << "Enter the ID of the person: \n";
		getline(cin, appinfo.ID);
		appinfo.writefile << appinfo.ID << endl;
		cout << "Enter the phone number of the person: \n";
		getline(cin, appinfo.phoneContact);
		appinfo.writefile << appinfo.phoneContact << endl;
		cout << "Now please enter the date of the appointment: \n";
		getline(cin, appinfo.date);
		appinfo.writefile << appinfo.date << endl;
        cout << "\n\nThank You! To add again please select from the menu. Have a good day. Press enter to go to menu.\n\n";
		cin.get();

		appinfo.writefile.close();
	
	}
	else // Error handling
	{
		cout << "\n\nWe can't input the data you entered. There was a error with file handling\n\n" << endl;
	}
	(appinfo.writefile.close());

	


}
void AppointmentType::updateAppointment() // Function to update appointments
{
	appinfo.writefile.open("AppointmentData1.txt", ios::app);

	if (appinfo.writefile.is_open()) // Checks to see if file is open and gives user instructions
	{
		cout << "\n -----Welcome to Appointment Manager 2017 Update Helper!-----";
		cin.get();
		cout << "\n\nEnter the name of the person whose appointment will be updated or changed: \n";
		getline(cin, appinfo.name);
		appinfo.writefile << appinfo.name << endl;
		cout << "Enter the ID of the same person: \n";
		getline(cin, appinfo.ID);
		appinfo.writefile << appinfo.ID << endl;
		cout << "Enter the phone number of the same person: \n";
		getline(cin, appinfo.phoneContact);
		appinfo.writefile << appinfo.phoneContact << endl;
		cout << "Now please enter the date of the appointment for this person: \n";
		getline(cin, appinfo.date);
		appinfo.writefile << appinfo.date << endl;
		cout << "\n\nThank You! All revisions will be created at the bottom portion of the display all appointments section. Enjoy your day. Press enter to go to menu.\n\n";
		cin.get();

		appinfo.writefile.close();

	}
	else // Error handling
	{
		cout << "\n\nWe can't input the data you entered. There was a error with file handling\n\n" << endl;
	}
	(appinfo.writefile.close());
}

void AppointmentType::printAllAppointments() // Function to print all appointments
{
	cout << "Here are all your current appointment details (Top to Down: Name, ID, Phone Number, Date of Appointment /// Each Name Starts a New Section): \n\n";
	
	appinfo.readfile.open("AppointmentData1.txt");
	if (appinfo.readfile.fail())
	{
		cerr << "\nThere was a problem opening the file!\n" << endl;
		exit(1);
	}
	while(getline(appinfo.readfile,appinfo.printDetails)) // Prints out all appointment data in text file for user
	{
		 cout << "|0|: " << appinfo.printDetails << " :|0|\n";
 
    }
	cout << "\n Please press enter to continue to the menu.";

	appinfo.readfile.close();
	
	cin.get();
	cin.get();
	
	AppointmentType();

}

void AppointmentType::searchAppointments() // Function to search for appointments
{
	cout << "\nHey There! Welcome to Endsoft's search function for Appointment Register 2017!\n";

	appinfo.line = "AppointmentData1.txt";  // Setting the file name path for the txt that is used in this project

	appinfo.readfile.open(appinfo.line.c_str());   // .c.str() brings the ability to search through the entire txt file

	if (appinfo.readfile.is_open())   // Function that checks to see if the file is open and gives instructions to the user
	{
		std::cout << "\n\nFile '" << appinfo.line << "' opened.\n";

		std::cout << "\n\nWrite the name or ID of the appointment data you're searching for and Appointment Manager will try to find it!\n";
		std::cin >> appinfo.searchKeyword;

		appinfo.testnum = 0;
		while (appinfo.readfile >> appinfo.testWord) // Looking through each word in the txt file
		{
			if (appinfo.searchKeyword == appinfo.testWord) ++appinfo.testnum;
		}

		if (appinfo.testnum > 0) // If words that are matched are found in the txt file this if statement will go through
		{
			cout << "\nThe word '" << appinfo.searchKeyword << "' has been found " << appinfo.testnum << " times in Appointment Register.\n"
				<< "There is appointment data for the Name/ID that was inputted. Please go to the menu and display all appointments to see what you seek."
				<< "Press the enter key to continue.\n";

			cin.get();
		}
		else
		{
			cout << "\nUnfortunately there was no appointment data found that correlates to the search input that was given. Sorry! \n"
				 << " Press enter to continue.\n\n";
			cin.get();
		}
		appinfo.readfile.close(); // Closing file
	}
	else //Error Handling
	{
		std::cerr << "Error! File not found!\n";
		exit(1);
	}
	
		

	cin.get();
	
	
}


void AppointmentType::deleteAppointments() // Function definition to delete appointments
{
	cout << "\nAre you sure you want to delete your appointment data and start a new?\n Type Y for yes or N for no and press enter.";
	cin >> appinfo.userAnswer;

	if (appinfo.userAnswer == 'Y')
	{
		appinfo.writefile.open("AppointmentData1.txt", ios::out);
		appinfo.writefile << appinfo.deleteVar;
		cout << "\nYour appointment data will now be deleted. Thank You! Press enter to continue. \n";

		appinfo.writefile.close();

		cin.get();

	}
}

void AppointmentType::helpGuide() // Functon to display Help Guide
{
	cout << "---------------------------------============================-------------------------------==========================------------------\n\n"
		<< "\n                                        Welcome to the Appointment Manger 2017 Help Manual!\n\n"
		<< "\n                                        Remember these tips for a great user experience!:"
		<< "\n\n\n1. All (AM 2017) information is stored in a data file called AppointmentData1.txt!"
		<< "\n\n2. Use the search function seen on the menu to make sure that the information you entered previously was stored!"
		<< "\n\n3. You can also use the search function to find out how many instances of a specific person's appointment data is currently stored."
		<< "\n\n4. You can add an almost unlimited amount of Appointment Data to the text file using the Add Appointment option on the menu!"
		<< "\n\n5. Finallly be on the look out for our next product coming out soon. Appointment Manager 2018. We hope you enjoy our program!\n"
		<< "\n\n\nPlease press enter to continue to the menu!."
		<< "\n----------------------------------=============================------------------------------==========================-----------------\n\n";
	cin.get();
	cin.get();
}

void AppointmentType::rexit() // Function to exit program
{
	cout << "\n\nWe hope you enjoyed your time here. Good bye! \n\nPress enter to end your session.";
    cin.get();

	exit(0);

}





