/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	November 29, 2021

	CS A250
	Project 1
*/

#include "DonorList.h"

#include <iostream>
using namespace std;

DonorList::DonorList(const DonorList& listToCopy)
{
	count = 0;
	ptrToFirst = nullptr;
	ptrToLast = nullptr;

	Node* currentNodeToCopy = listToCopy.ptrToFirst;

	for (int i = 0; i < listToCopy.count; ++i)
	{
		addDonor(currentNodeToCopy->getDonor().getFirstName(),
			currentNodeToCopy->getDonor().getLastName(),
			currentNodeToCopy->getDonor().getMembershipNo(),
			currentNodeToCopy->getDonor().getAmountDonated());
		count++;
		currentNodeToCopy = currentNodeToCopy->getPtrToNext();
	}

}

DonorList& DonorList::operator=(const DonorList& listToCopy)
{
	if (&listToCopy == this)
	{
		cerr << "Attempt assignment to itself.";
	}
	else
	{
		int numOfDonorsToCopy = listToCopy.count;

		if (count == 0)
		{
			copyCallingObjEmpty(listToCopy);
		}
		else if (count == numOfDonorsToCopy)
		{
			copyObjectsSameLength(listToCopy);
		}
		else if (count > numOfDonorsToCopy)
		{
			copyCallingObjLonger(listToCopy);
		}
		else if (count < numOfDonorsToCopy)
		{
			copyCallingObjShorter(listToCopy);
		}
	}

	return *this;
}

void DonorList::copyCallingObjEmpty
(const DonorList& listToCopy)
{
	if (listToCopy.count == 1)
	{
		addDonor(listToCopy.ptrToFirst->getDonor().getFirstName(),
			listToCopy.ptrToFirst->getDonor().getLastName(),
			listToCopy.ptrToFirst->getDonor().getMembershipNo(),
			listToCopy.ptrToFirst->getDonor().getAmountDonated());
	}
	else
	{
		Node* currentNodeToCopy = listToCopy.ptrToFirst;

		while (currentNodeToCopy != nullptr)
		{
			addDonor(currentNodeToCopy->getDonor().getFirstName(),
				currentNodeToCopy->getDonor().getLastName(),
				currentNodeToCopy->getDonor().getMembershipNo(),
				currentNodeToCopy->getDonor().getAmountDonated());

			currentNodeToCopy = currentNodeToCopy->getPtrToNext();
		}

	}
}

void DonorList::copyObjectsSameLength
(const DonorList& listToCopy)
{
	if (listToCopy.count == 1)
	{
		ptrToFirst->getDonor().setDonorInfo(
			listToCopy.ptrToFirst->getDonor().getFirstName(),
			listToCopy.ptrToFirst->getDonor().getLastName(),
			listToCopy.ptrToFirst->getDonor().getMembershipNo(),
			listToCopy.ptrToFirst->getDonor().getAmountDonated());
	}
	else
	{
		Node* currentNode = ptrToFirst;
		Node* currentNodeToCopy = listToCopy.ptrToFirst;

		while (currentNodeToCopy != nullptr)
		{
			currentNode->setDonor(currentNodeToCopy->getDonor());
			currentNode = currentNode->getPtrToNext();
			currentNodeToCopy = currentNodeToCopy->getPtrToNext();
		}
	}
}

void DonorList::copyCallingObjLonger
(const DonorList& listToCopy)
{
	if (listToCopy.count == 1)
	{
		ptrToFirst = ptrToLast;
		ptrToLast->getDonor().setDonorInfo(
			listToCopy.ptrToFirst->getDonor().getFirstName(),
			listToCopy.ptrToFirst->getDonor().getLastName(),
			listToCopy.ptrToFirst->getDonor().getMembershipNo(),
			listToCopy.ptrToFirst->getDonor().getAmountDonated());
	}
	else 
	{
		Node* currentNode = ptrToFirst;
		Node* currentNodeToCopy = listToCopy.ptrToFirst;

		while (currentNodeToCopy != nullptr)
		{
			currentNode->setDonor(currentNodeToCopy->getDonor());
			ptrToLast = currentNode;
			currentNode = currentNode->getPtrToNext();
			currentNodeToCopy = currentNodeToCopy->getPtrToNext();
		}

		ptrToLast->setPtrToNext(nullptr);
		Node* currentNodeToDelete = currentNode;

		while (currentNode != nullptr)
		{
			currentNode = currentNode->getPtrToNext();
			delete currentNodeToDelete;
			currentNodeToDelete = currentNode;
		}
	}
	
	count = listToCopy.count;
}

void DonorList::copyCallingObjShorter
(const DonorList& listToCopy)
{
	if (listToCopy.count == 2)
	{
		ptrToFirst->setDonor(listToCopy.ptrToFirst->getDonor());

		addDonor(listToCopy.ptrToLast->getDonor().getFirstName(),
			listToCopy.ptrToLast->getDonor().getLastName(),
			listToCopy.ptrToLast->getDonor().getMembershipNo(),
			listToCopy.ptrToLast->getDonor().getAmountDonated());
	}
	else
	{
		Node* currentNode = ptrToFirst;
		Node* currentNodeToCopy = listToCopy.ptrToFirst;

		// the loop needs to stop before the last node of the
		// calling obj
		while (currentNode != nullptr)
		{
			currentNode->setDonor(currentNodeToCopy->getDonor());
			currentNode = currentNode->getPtrToNext();
			currentNodeToCopy = currentNodeToCopy->getPtrToNext();
		}

		//create additional nodes
		while (currentNodeToCopy != nullptr)
		{
			addDonor(currentNodeToCopy->getDonor().getFirstName(),
				currentNodeToCopy->getDonor().getLastName(),
				currentNodeToCopy->getDonor().getMembershipNo(),
				currentNodeToCopy->getDonor().getAmountDonated());

			currentNodeToCopy = currentNodeToCopy->getPtrToNext();
		}
	}
	
	count = listToCopy.count;
}


