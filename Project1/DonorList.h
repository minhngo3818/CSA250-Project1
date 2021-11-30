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
			Node() : data(0), ptrToNext(nullptr) {}
			Node(DonorType donorInfo, Node* newPtrToNext)
				: donation(donorInfo), ptrToNext(newPtrToNext) {}
			Node* getPtrToNext() const { return ptrToNext; }
			DonorType getDonation() { return &donation; }
			void setDonation(DonorType donorInfo) { donation = donorInfo; }
			void setPtrToNext(Node* newPtrToNext)
			{
				ptrToNext = newPtrToNext;
			}

			~Node() {}

	private:
			int data;
			DonorType donation;
			Node* ptrToNext;
};

class DonorList : public DonorType
{
	public:
			DonorList() : ptrToFirst(nullptr), ptrToLast(nullptr), count(0) {}
			DonorList(const DonorList& donorListToCopy);	// add copy constructor
			void addDonor(const std::string& newFirstName, const std::string& newLastName, int newMembershipNo, double newAmountDonated);
			void creatList();
			int getNoOfDonors() const { return count; }
			double getTotalDonations() const { return donationTotal; }
	
			bool isEmpty() const { return (count == 0); }

			void searchID(int membershipNo);
			void deleteDonor();
			void printAllDonors() const;
			void printAllDonations() const;
			void clearList();

			DonorList& operator=(const DonorList& donorListToCopy); // assignment operator

			~DonorList() {}
	private:
			Node* ptrToFirst;
			Node* ptrToLast;
			int count;

			// Helper functions
			// Conditions to call each function below may be added in assignment operator fucntion 
			// Those functions below must be private
			DonorList& copyCallingObjEmpty(const DonorList& donorListToCopy);
			DonorList& opyObjectsSameLength(const DonorList& donorListToCopy);
			DonorList& copyCallingObjLonger(const DonorList& donorListToCopy);
			DonorList& copyCallingObjShorter(const DonorList& donorListToCopy);

};

#endif
