/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	November 27, 2021

	CS A250
	Project 1
*/

#include "Interface.h"

#include <iostream>
using namespace std;

void displayMenu()
{
	cout << "*************************************************\n"
		<< "                    MAIN MENU                    \n"
		<< "*************************************************\n\n"
		<< "Select one of the following:\n\n"
		<< "    1. Add a donor\n"
		<< "    2. Delete a donor\n"
		<< "    3. Print all donors\n"
		<< "    4: To exit\n";
}

void addDonor(DonorList& aDonorList)
{
	string inputFirstName;
	string inputLastName;
	int inputMembershipNo = 0;
	double inputAmountDonated = 0.0;

	cout << "  => Enter donor's first name: ";
	cin >> inputFirstName;
	cout << "  => Enter donor's last name: ";
	cin >> inputLastName;
	cout << "  => Enter donor's membership number: ";
	cin >> inputMembershipNo;
	cout << "  => Enter amount donated: $ ";
	cin >> inputAmountDonated;
	
	if (aDonorList.searchID(inputMembershipNo))
	{
		cerr << "\n  => Member ID has been used.\n";
	}
	else
	{
		aDonorList.addDonor(inputFirstName, inputLastName,
			inputMembershipNo, inputAmountDonated);
		cout << "\n  => Donor has been added.\n";
	}
	
}

void deleteDonor(DonorList& aDonorList)
{
	if (aDonorList.isEmpty())
	{
		cerr << "The database has no donors.\n";
	}
	else
	{
		int inputMembershipNo;
		cout << "  => Enter donor's membership number: ";
		cin >> inputMembershipNo;
		aDonorList.deleteDonor(inputMembershipNo);
		cout << "\n  => Donor has been deleted.\n";
	}
}

void printAllDonors(const DonorList& aDonorList)
{
	aDonorList.printAllDonors();
}

void processSelection(DonorList& aDonorList)
{
	char userInput = 'c';
	bool done = false;
	bool firstTime = true;

	while (!done)
	{

		if (!firstTime) 
			displayMenu();
		firstTime = false;
		cout << "\n  => Enter your selection: ";
		cin >> userInput;
		cout << endl;

		if (userInput == '4')
		{
			done = true;
			cout << "  => Thank you for visiting our site!\n";
		}
		else
		{
			if (userInput < '1' || userInput > '4')
			{
				cout << "  => Sorry. That is not a selection.\n";
			}
			else if (userInput >= '1' && userInput < '4')
			{

				if (userInput == '1')
				{
					addDonor(aDonorList);
				}
				else if (userInput == '2')
				{
					deleteDonor(aDonorList);
				}
				else
				{
					printAllDonors(aDonorList);
				}
			}

			cout << "\n  => Would you like to continue? (y/n) ";
			cin >> userInput;
			cout << endl;

			if (userInput != 'y')
			{
				done = true;
				cout << "  => Thank you for visiting our site!\n";
			}
		}
	}
}
