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

#ifndef DONORLIST_H
#define DONORLIST_H

#include "DonorType.h"
#include "Database.h"

#include <string>

class Node : public DonorType
{
	public:
		Node() : donor(DonorType("", "", 0, 0.0)),
			ptrToNext(nullptr) {}
		Node(DonorType newDonor, Node* newPtrToNext)
			: donor(newDonor), ptrToNext(newPtrToNext) {}

		Node* getPtrToNext() const { return ptrToNext; }
		DonorType& getDonor() { return donor; }

		void setDonor(DonorType newDonor)
		{
			donor = newDonor; 
		}
		void setPtrToNext(Node* newPtrToNext)
		{
			ptrToNext = newPtrToNext;
		}

		~Node() {}

	private:
		DonorType donor;
		Node* ptrToNext;
};

class DonorList : public DonorType
{
	public:
		DonorList();

		void addDonor(const std::string& newFirstName,
			const std::string& newLastName, int newMembershipNo,
			double newAmountDonated);

		void createList();

		int getNoOfDonors() const;
		double getTotalDonations() const;

		bool isEmpty() const;

		bool searchID(int membershipNo) const;

		void deleteDonor(int membershipNo);

		void printAllDonors() const;
		void printAllDonations() const;

		void clearList();
		~DonorList();

		DonorList(const DonorList& listToCopy);					
		DonorList& operator=(const DonorList& listToCopy);		

	private:
		DonorList& copyCallingObjEmpty(const DonorList& listToCopy);	
		DonorList& copyObjectsSameLength(const DonorList& listToCopy);	
		DonorList& copyCallingObjLonger(const DonorList& listToCopy);	
		DonorList& copyCallingObjShorter(const DonorList& listToCopy);	

		Node* ptrToFirst;
		Node* ptrToLast;
		int count;

};

#endif