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

#include "DonorType.h"

#include <iostream>
#include <iomanip>


using namespace std;

DonorType::DonorType() : amountDonated(0.0) {}

DonorType::DonorType(const string& newFirstName, const string& newLastName,
	int newMembershipNo, double newAmountDonated)
	: MemberType(newFirstName, newLastName, newMembershipNo)
{
	amountDonated = newAmountDonated;
}

void DonorType::setDonorInfo(const string& newFirstName, const string& newLastName,
	int newMembershipNo, double newAmountDonated)
{
	setMemberInfo(newFirstName, newLastName, newMembershipNo);
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
	cout << getLastName() << ", " << getFirstName() <<
		"\n    Donation amount: $" << setprecision(2) << fixed << amountDonated << endl;
}

bool DonorType::operator<(const DonorType& otherDonor) const
{
	int membershipNo = getMembershipNo();
	int otherMembershipNo = otherDonor.getMembershipNo();
	
	if (membershipNo == otherMembershipNo)
	{
		cerr << "Member ID must be unique\n";
	}

	return membershipNo < otherMembershipNo;
}

DonorType::~DonorType() {}
