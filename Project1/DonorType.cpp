/*
	Night Owls
	
	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali
	
	November 22, 2021
	
	CSA 250
	Project 1
*/

#include <iostream>
#include <iomanip>
#include <string>

#include "DonorType.h"

using namespace std;

DonorType::DonorType()
{
	amountDonated = 0.0;
}

DonorType::DonorType
	(const string& newFirstName, const string& newLastName,
		int newMembershipNum, double newAmountDonated) 
			: MemberType (newFirstName, newLastName, newMembershipNum)
{
	amountDonated = newAmountDonated;
}

void DonorType::setDonorInfo(const string& newFirstName, const string& newLastName,
	int newMembershipNum, double newAmountDonated) 
{
	setMemberInfo(newFirstName, newLastName, newAmountDonated);

	amountDonated = newAmountDonated;
}

void DonorType::setAmountDonated(double newAmountDonated)
{
	amountDonated = newAmountDonated;
}

double DonorType::getAmountDonated() const
{
	return amountDonated;
}


void DonorType::printDonor() const
{
	printMemberInfo();
}

void DonorType::printDonation() const
{
	cout << getLastName() << ", " << getFirstName << 
		"\n    Donnation amount: $" << setprecision(2) << fixed << amountDonated << endl;
}

DonorType::~DonorType() {}
