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
	first = nullptr;
	last = nullptr;
	// count, first, last can be removed if default constructor has initialized

	Node* currentNodeToCopy = listToCopy.first;

	for (int i = 0; i < listToCopy.count; ++i)
	{
		addDonor(currentNodeToCopy->getFirstName(),
			currentNodeToCopy->getLastName(),
			currentNodeToCopy->getMembershipNo(),
			currentNodeToCopy->getAmountDonated());

		currentNodeToCopy->getNext();
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
		addDonor(listToCopy.first->getFirstName(),
			listToCopy.first->getLastName(),
			listToCopy.first->getMembershipNo(),
			listToCopy.first->getAmountDonated());
	}
	else
	{
		Node* currentNodeToCopy = listToCopy.first;

		while (currentNodeToCopy != nullptr)
		{
			addDonor(currentNodeToCopy->getFirstName(),
				currentNodeToCopy->getLastName(),
				currentNodeToCopy->getMembershipNo(),
				currentNodeToCopy->getAmountDonated());

			currentNodeToCopy = currentNodeToCopy->getNext();
		}
		
	}

	return *this;
}

DonorList& DonorList::copyObjectsSameLength(const DonorList& listToCopy)
{
	if (listToCopy.count == 1)
	{
		first->setDonorInfo(listToCopy.first->getFirstName(),
			listToCopy.first->getLastName(),
			listToCopy.first->getMembershipNo(),
			listToCopy.first->getAmountDonated());
	}
	else
	{
		Node* currentNode = first;
		Node* currentNodeToCopy = listToCopy.first;

		while (currentNodeToCopy != nullptr)
		{
			// Method 1: Using setDonorInfo()
			// currentNode->setDonorInfo(currentNode->getFirstName(),
			//			currentNode->getLastName(),
			//			currentNode->getMembershipNo(),
			//			currentNode->getAmountDonated() );

			// Method 2: Using setDonation() from Node
			currentNode->setDonor(currentNodeToCopy->getDonor());
			// End copy section

			currentNode = currentNode->getNext();
			currentNodeToCopy = currentNodeToCopy->getNext();
		}
	}

	return *this;
}

DonorList& DonorList::copyCallingObjLonger(const DonorList& listToCopy)
{
	Node *thisTemp = first;
	Node *otherTemp = listToCopy.first;
	
	for (int copyNode = 0; copyNode < count; copyNode++)
	{
		thisTemp->setDonor(otherTemp->getDonor());
		thisTemp = thisTemp->getNext();
		otherTemp = otherTemp->getNext();
	}
	
	last = otherTemp; //this is the last node after copying

	//delete the rest
	int nodesToDelete = count - listToCopy.count;
	Node *thisTemp2 = thisTemp;
	
	while (thisTemp != nullptr)
	{
		thisTemp->getNext();
		delete thisTempt2;
		thisTemp2->getNext();
	}
	
	return *this;
}

DonorList& DonorList::copyCallingObjShorter(const DonorList& listToCopy)
{
	Node *thisTemp = first;
	Node *otherTemp = listToCopy.first;

	//the loop needs to stop before the lasy node of the calling obj
	for(int copyNode = 0; copyNode < count; copyNode++)
	{
		thisTemp->setDonor(otherTemp->getDonor());
		thisTemp = thisTemp->getNext();
		otherTemp = otherTemp->getNext();
	}

	//create additional nodes
	//Node *thisTemp2 = thisTemp;
	
	while (otherTemp != nullptr)
	{
		addDonor(otherTemp->getDonor().getFirstName(), 
			otherTemp->getDonor().getLastName(),
			otherTemp->getDonor().getMembershipNo(), 
			otherTemp->getDonor().getAmountDonated() );

		otherTemp = otherTemp->getNext();
		last = last->getNext();
	}
	
	return *this;
}


