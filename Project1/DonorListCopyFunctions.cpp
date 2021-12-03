/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	November 29, 2021

	CSA 250
	Project 1
*/

#include "DonorList.h"
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
		currentNodeToCopy->getPtrToNext();
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
			return copyCallingObjEmpty(listToCopy);
		}
		else if (count == numOfDonorsToCopy)
		{
			return copyObjectsSameLength(listToCopy);
		}
		else if (count > numOfDonorsToCopy)
		{
			return copyCallingObjLonger(listToCopy);
		}
		else if (count < numOfDonorsToCopy)
		{
			return copyCallingObjShorter(listToCopy);
		}

	}
}

DonorList& DonorList::copyCallingObjEmpty(const DonorList& listToCopy)
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

	return *this;
}

DonorList& DonorList::copyObjectsSameLength(const DonorList& listToCopy)
{
	if (listToCopy.count == 1)
	{
		ptrToFirst->setDonorInfo(
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

	return *this;
}

DonorList& DonorList::copyCallingObjLonger(const DonorList& listToCopy)
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

	//ptrToLast = currentNode; //this is the last node after copying

	Node* currentNodeToDelete = currentNode;

	while (currentNode != nullptr)
	{
		currentNode = currentNode->getPtrToNext();
		delete currentNodeToDelete;
		currentNodeToDelete = currentNode;
	}

	// Update numOfNodes
	count = listToCopy.count;

	return *this;
}

DonorList& DonorList::copyCallingObjShorter(const DonorList& listToCopy)
{
	Node* currentNode = ptrToFirst;
	Node* currentNodeToCopy = listToCopy.ptrToFirst;

	//the loop needs to stop before the lasy node of the calling obj
	for (int i = 0; i < count; ++i)
	{
		currentNode->setDonor(currentNodeToCopy->getDonor());
		currentNode = currentNode->getPtrToNext();
		currentNodeToCopy = currentNodeToCopy->getPtrToNext();
	}

	//create additional nodes
	//Node *thisTemp2 = thisTemp;

	while (currentNodeToCopy != nullptr)
	{
		addDonor(currentNodeToCopy->getDonor().getFirstName(),
			currentNodeToCopy->getDonor().getLastName(),
			currentNodeToCopy->getDonor().getMembershipNo(),
			currentNodeToCopy->getDonor().getAmountDonated());

		currentNodeToCopy = currentNodeToCopy->getPtrToNext();
		ptrToLast = ptrToLast->getPtrToNext();
	}
	count = listToCopy.count;

	return *this;
}


