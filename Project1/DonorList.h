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
#include "Database.h"
#include <iostream>
#include <string>
#include "DonorType.h";
class DonorList
{
public:
	DonorList();
	DonorList(DonorType Donor,);
private:
};

class Node
{
public:
	Node() : data(0), ptrToNext(nullptr) {}
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

// Sorry guys had an 9 hour shift then tried to do what I could running on fumes. Heading in now so I can alter more tonight.
