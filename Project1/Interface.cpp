/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	November 27, 2021

	CSA 250
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
	string inputFirstName, inputLastName;
	int inputMembershipNo;
	double inputAmountDonated;

	cout << "  => Enter donor's first name: ";
	cin >> inputFirstName;
	cout << "  => Enter donor's last name: ";
	cin >> inputLastName;
	cout << "  => Enter donor's membership number: ";
	cin >> inputMembershipNo;
	cout << "  => Enter amount donated: $ ";
	cin >> inputAmountDonated;
	cout << "\n  => Donor has been added.\n";

	aDonorList.addDonor(inputFirstName, inputLastName, inputMembershipNo, inputAmountDonated);
}

void deleteDonor(DonorList& aDonorList)
{
	int inputMembershipNo;
	cout << "  => Enter donor's membership number: ";
	cin >> inputMembershipNo;
	cout << "\n  => Donor has been deleted.\n";

	aDonorList.deleteDonor(inputMembershipNo);
}

void printAllDonors(const DonorList& aDonorList)
{
	aDonorList.printAllDonors();
}

void processSelection(DonorList& aDonorList)
{
	// Prompts
	string selectionPrompt = "\n  => Enter your selection: ";
	string continuePrompt = "\n  => Would you like to continue? (y/n) ";
	string goodbyeMessage = "\n  => Thank you for visiting our site!\n";
	string wrongInputMessage = "\n  => Sorry. That is not a selection.\n";

	char userInput;
	bool done = false;
	bool firstTime = true;

	while (!done)
	{
		// Notes: Assume user always types correct input

		if (!firstTime) 
			displayMenu();
		firstTime = false;
		cout << selectionPrompt;
		cin >> userInput;
		cout << endl;

		if (userInput < '1' || userInput > '4')
		{
			done = true;
			cout << wrongInputMessage;
		}
		else if (userInput >= '1' && userInput <= '4')
		{
			if (userInput == '4')
			{
				done = true;
				cout << goodbyeMessage;
			}
			else
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

				cout << continuePrompt;
				cin >> userInput;
				cout << endl;

				if (userInput != 'y')
				{
					done = true;
					cout << goodbyeMessage;
				}
			}
		}
	}
}
