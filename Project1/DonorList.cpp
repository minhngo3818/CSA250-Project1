/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	November 24, 2021

	CS A250
	Project 1
*/

#include "DonorList.h"
#include "Database.h"

#include <iostream>
using namespace std;

DonorList::DonorList() : ptrToFirst(nullptr), ptrToLast(nullptr),
count(0) {};

void DonorList::addDonor(const string& newFirstName,
	const string& newLastName, int newMembershipNo, 
	double newAmountDonated)
{
	DonorType newDonor = DonorType(newFirstName, newLastName,
		newMembershipNo, newAmountDonated);
	if (count == 0)
	{
		ptrToFirst = new Node(newDonor, nullptr);
		ptrToLast = ptrToFirst;
	}
	else
	{
		if (ptrToFirst->getDonor().getMembershipNo()
		 > newMembershipNo)
		{
			ptrToFirst = new Node(newDonor, ptrToFirst);
		}
		else if (ptrToLast->getDonor().getMembershipNo()
		 < newMembershipNo)
		{
			ptrToLast->setPtrToNext(new Node(newDonor, nullptr));
			ptrToLast = ptrToLast->getPtrToNext();
		}
		else
		{
			bool done = false;
			Node* sortPtr = ptrToFirst->getPtrToNext();
			Node* sortPtrTrail = ptrToFirst;

			while (!done)
			{
				if (sortPtr == nullptr)
					done = true;
				else if (sortPtr->getDonor().getMembershipNo()
				> newMembershipNo)
					done = true;
				else
				{
					sortPtr = sortPtr->getPtrToNext();
					sortPtrTrail = sortPtrTrail->getPtrToNext();
				}
			}

			sortPtrTrail->setPtrToNext(new Node(newDonor, sortPtr));
		}
	}

	++count;
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
	Node* currentNode = ptrToFirst;

	while (currentNode != nullptr)
	{
		donationTotal += currentNode->getDonor().getAmountDonated();
		currentNode = currentNode->getPtrToNext();
	}

	return donationTotal;
}

void DonorList::deleteDonor(int membershipNo)
{
	if (ptrToFirst->getDonor().getMembershipNo() == membershipNo)
	{
		Node* currentNode = ptrToFirst;
		ptrToFirst = ptrToFirst->getPtrToNext();
		delete currentNode;
		currentNode = nullptr;
		--count;
	}
	else
	{
		bool found = false;
		Node* trailCurrent = ptrToFirst;
		Node* currentNode = ptrToFirst->getPtrToNext();

		while (!found && currentNode != nullptr)
		{
			if (currentNode->getDonor().getMembershipNo()
				== membershipNo)
			{
				trailCurrent->setPtrToNext(currentNode->
					getPtrToNext());
				delete currentNode;
				currentNode = nullptr;
				--count;
				found = true;

			}
			else
			{
				trailCurrent = currentNode;
				currentNode = currentNode->getPtrToNext();
			}
		}
		if (!found)
		{
			cout << "\nDonor is not in the list.";
		}
	}
}

void DonorList::createList()
{
	set<DonorType> copyDonors = getData();

	if (copyDonors.size() == 0)
	{
		cerr << "Database has no donations";
	}
	else
	{
		for (auto elem : copyDonors)
		{
			addDonor(elem.getFirstName(), elem.getLastName(),
				elem.getMembershipNo(), elem.getAmountDonated());
		}
	}
}

bool DonorList::searchID(int membershipNo) const
{
	if (ptrToFirst->getDonor().getMembershipNo() == membershipNo
		|| ptrToLast->getDonor().getMembershipNo() == membershipNo)
	{
		return true;
	}
	else
	{
		Node* currentNode = ptrToFirst;

		while (currentNode != nullptr)
		{
			if (currentNode->getDonor().getMembershipNo() 
				== membershipNo)
				return true;
			else
				currentNode = currentNode->getPtrToNext();
		}

		return false;
	}
}

void DonorList::printAllDonors() const
{
	if (count != 0)
	{
		Node* currentNode = ptrToFirst;

		while (currentNode != nullptr)
		{
			currentNode->getDonor().printMemberInfo();
			currentNode = currentNode->getPtrToNext();
		}
	}
}

void DonorList::printAllDonations() const
{
	if (count != 0)
	{
		Node* currentNode = ptrToFirst;

		while (currentNode != nullptr)
		{
			currentNode->getDonor().printDonation();
			currentNode = currentNode->getPtrToNext();
		}
	}
}

void DonorList::clearList()
{
	Node* temp = ptrToFirst;
	while (temp != nullptr)
	{
		ptrToFirst = ptrToFirst->getPtrToNext();
		delete temp;
		temp = ptrToFirst;
	}
	ptrToLast = nullptr;
	count = 0;
}

DonorList::~DonorList()
{
	clearList();
}
