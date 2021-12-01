/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	November 24, 2021

	CSA 250
	Project 1
*/
#include "DonorList.h";
#include "DonorType.h";
#include <iostream>;
#include <string>;
#include <iomanip>;

using namespace std;

DonorList::DonorList() : ptrToFirst(nullptr), ptrToLast(nullptr), count(0) {};

void DonorList::addDonor(const string& newFirstName, const string& newLastName, int newMembershipNo, double newAmountDonated)
{
	ptrToLast->setPtrToNext(new Node({ "", "", 0, 0.0 }, nullptr));
	ptrToLast = ptrToLast->getPtrToNext;
}

bool DonorList::isEmpty() const
{
	return (count == 0); 
}

int DonorList::getNoOfDonors() const
{
	return count;
}

double DonorList::getTotalDonations() const
{
	double donationTotal = 0.0;
	for (int i = 0; i < getData().size(); ++i)
	{
		i += getAmountDonated();
		donationTotal = i;
	}
	return donationTotal;
}

void DonorList::deleteDonor(int membershipNo)
{
	if (ptrToFirst->getMembershipNo() == membershipNo)
	{
		Node* current = ptrToFirst;
		ptrToFirst = ptrToFirst->getPtrToNext();
		delete current;
		current = nullptr;
		--count;
	}
	else
	{
		bool found = false;	
		Node* trailCurrent = ptrToFirst;
		Node* current = ptrToFirst->getPtrToNext();
		while (!found && current != nullptr)
		{
			if (current->getMembershipNo() == membershipNo)
			{
				trailCurrent->setPtrToNext(current->getPtrToNext());
				delete current;
				current = nullptr;
				--count;
				found == true;

			}
			else
			{
				trailCurrent = current;
				current = current->getPtrToNext();
			}
		}
		if (!found)
		{
			cout << "Donor is not in the list";
		}
	}
}

DonorList::~DonorList()
{
	clearList();
}
