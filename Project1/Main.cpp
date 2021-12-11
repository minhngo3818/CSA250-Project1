/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	December 3, 2021

	CS A250
	Project 1
*/

#include "Interface.h"

using namespace std;

int main()
{
	DonorList testDonorList;
	testDonorList.createList();
	
	if (!testDonorList.isEmpty())
	{
		displayMenu();
		processSelection(testDonorList);
	}

	return 0;
}
