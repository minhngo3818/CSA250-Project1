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

#include "DonorList.h"

using namespace std;

//Copy constructor
DonorList::DonorList(const DonorList& donorListToCopy)
{
	// Funtion body
}

//Copy assignment operator
DonorList& DonorList::operator=(const DonorList& donorListToCopy)
{
	// Funtion body
	return *this;
}

//Function copyCallingObjIsEmpty
DonorList& DonorList::copyCallingObjEmpty(const DonorList& donorListToCopy)
{
	// Funtion body
	return *this;
}

//Function copyObjectsSameLength
DonorList& DonorList::opyObjectsSameLength(const DonorList& donorListToCopy)
{
	// Funtion body
	return *this;
}

//Function copyCallingObjLonger
DonorList& DonorList::copyCallingObjLonger(const DonorList& donorListToCopy)
{
	// Funtion body
	Node *thisTemp = first;
	Node *otherTemp = donorListToCopy.first;
	for(int copyNode = 0; copyNode < count; copyNode++)
	{
		thisTemp->setDonor(otherTemp->getDonor());
		thisTemp = thisTemp->getNext();
		otherTemp = otherTemp->getNext();
	}
	last = otherTemp; //this is the last node after copying

	//delete the rest
	int nodesToDelete = count - donorListToCopy.count;
	Node *thisTemp2 = thisTemp;
	
	while (thisTemp != nullptr)
	{
		thisTemp->getNext();
		delete thisTempt2;
		thisTemp2->getNext();

	}
	return *this;
}

//Function copyCallingObjShorter
DonorList& DonorList::copyCallingObjShorter(const DonorList& donorListToCopy)
{
	// Funtion body
	Node *thisTemp = first;
	Node *otherTemp = donorListToCopy.first;

	//the loop needs to stop before the lasy node of the calling obj
	for(int copyNode = 0; copyNode < count; copyNode++)
	{
		thisTemp->setDonor(otherTemp->getDonor());
		thisTemp = thisTemp->getNext();
		otherTemp = otherTemp->getNext();
	}

	//create additional nodes
	//int nodesToDelete = count - donorListToCopy.count;
	Node *thisTemp2 = thisTemp;
	
	while (otherTemp != nullptr)
	{
		this->addDonor(first->getDonor().getFirstName(), first->getDonor().getLastName(),
			first->getDonor().getMembershipNo(), first->getDonor().donationAmount);

		otherTemp->getNext();
		last = last->getNext();

	}
	return *this;
}


