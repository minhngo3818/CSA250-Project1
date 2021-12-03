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

#include "DonorType.h"
#include "MemberType.h"
#include "DonorList.h"
#include "Interface.h"
#include "Database.h"

#include <iostream>
#include <iomanip>
#include <string>
	
using namespace std;

int main()
{
	DonorList DList;
	DList.createList();
	displayMenu();
	processSelection(DList);




	/*system("Pause");*/
	return 0;
}
