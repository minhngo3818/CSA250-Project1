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
			Node() : donation("", "", 0, 0.0), ptrToNext(nullptr) {}
			Node(DonorType donorInfo, Node* newPtrToNext)
				: donation(donorInfo), ptrToNext(newPtrToNext) {}
			Node* getPtrToNext() const { return ptrToNext; }
			DonorType getDonation() { return donation; }
			void setDonation(DonorType donorInfo) { donation = donorInfo; }
			void setPtrToNext(Node* newPtrToNext)
			{
				ptrToNext = newPtrToNext;
			}

			~Node() {}

	private:
			DonorType donation;
			Node* ptrToNext;
};

class DonorList : public DonorType
{
	public:
			DonorList();
			DonorList() : ptrToFirst(nullptr), ptrToLast(nullptr), count(0) {}
			void addDonor(const std::string& newFirstName, const std::string& newLastName,
						int newMembershipNo, double newAmountDonated);
			void createList();
			int getNoOfDonors() const {}
			double getTotalDonations() const {}
	
			bool isEmpty() const {}

			void searchID(int membershipNo);
			void deleteDonor(int membershipNo);
			void printAllDonors() const;
			void printAllDonations() const;

			void clearList();
			~DonorList() {}

			DonorList(const DonorList& listToCopy);					// Part E, copy constructor
			DonorList& operator=(const DonorList& listToCopy);		// Part E, assignment operator

	private:
			DonorList& copyCallingObjEmpty(const DonorList& listToCopy);	// Part E
			DonorList& copyObjectsSameLength(const DonorList& listToCopy);	// Part E
			DonorList& copyCallingObjLonger(const DonorList& listToCopy);	// Part E
			DonorList& copyCallingObjShorter(const DonorList& listToCopy);	// Part E

			Node* ptrToFirst;
			Node* ptrToLast;
			int count;

};

#endif
