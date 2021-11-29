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
#ifndef DONORTYPE.H
#define DONORTYPE.H


#include "Database.h"
#include <iostream>
#include <string>
#include "DonorType.h"

class DonorList
{
public:
	DonorList();
	DonorList(DonorType Donor);
	Node* getPtrToNext(return ptrToNext);
private:
	Node* ptrToNext;
	Node* ptrToFirst;
	Node* ptrToLast;
	int count;

};

class Node
{
public:
	Node() : DonorType Donor , ptrToNext(nullptr) {}
	Node(int theData, Node* newPtrToNext)
		: data(theData), ptrToNext(newPtrToNext) {}
	Node* getPtrToNext() const { return ptrToNext; }
	int getDonorType() const { return DonorType; }
	void setDonorType(DonorType) { DonorType = theDonorType; }
	void setPtrToNext(Node* newPtrToNext)
	{
		ptrToNext = newPtrToNext;
	}
	~Node() {}
private:
	int data;
	Node* ptrToNext; 
};

#endif
