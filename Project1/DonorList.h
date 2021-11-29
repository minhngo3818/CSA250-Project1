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

#ifndef DONORTYPE_H
#define DONORTYPE_H

#include "DonorType.h"

#include <string>


class Node : public DonorType
{
	public:
		Node() : donation(getFirstName, getLastName, getMembershipNo, getAmountDonated), ptrToNext(nullptr) {}
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
		DonorType donation;
		Node* ptrToNext;
};

class DonorList : public DonorType
{
public:
	DonorList() : ptrToFirst(nullptr), count(0) {}

	~DonorList() {}
private:
	Node* ptrToFirst;
	Node* ptrToLast;
	int count;

};

#endif
