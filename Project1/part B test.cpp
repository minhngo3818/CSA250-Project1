/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	November 28, 2021

	CSA 250
	Project 1
*/

#include "DonorType.h"
#include "MemberType.h"
#include "Database.h"
#include "DonorList.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	DonorList list1;
	list1.addDonor("Patrick", "Hewes", 24, 67.0);
	list1.createList();
	list1.getNoOfDonors();
	list1.isEmpty();
	list1.searchID(80056721);
	list1.deleteDonor(80056721);
	list1.deleteDonor(80056721);
	list1.printAllDonors();
	list1.printAllDonations();
	list1.clearList();
	list1.~DonorList();
	
}