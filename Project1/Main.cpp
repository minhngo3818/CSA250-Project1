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
#include "Interface.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	
	DonorList DList;
	DList.createList();
	/*
	if (!DList.isEmpty())
	{
		displayMenu();
		processSelection(DList);
	}
	
	system("Pause");
	*/

	/*
	DonorList listA;
	listA.createList();
	listA.printAllDonors();

	listA.printAllDonations();

	//Test copy constructor
	cout << "\ncreated list1, print list2" << endl;
	DonorList listB(listA);
	listA.printAllDonors();
	listA.printAllDonations();

	cout << "\nthe output of list2 should be the same" << endl;
	listB.printAllDonors();
	listB.printAllDonations();
	*/

	// test the copy assignment operator

	/*
	//copyCallingObjEmpty()
	DonorList list1;

	DonorList list2;
	list2.addDonor("Hoa", "Ta", 123, 1000.01);
	list2.addDonor("Minh", "Ngo", 1234, 1500.01);
	list2.addDonor("Nick", "Richardson", 12345, 2000.01);
	list2.addDonor("Riana", "Ali", 123456, 2500.01);
	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();

	list1 = list2;
	cout << "\n-------After assign list1 = list2-------- \n";
	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();

	cout << "Empty list1 \n";
	list1.clearList();
	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();
	*/

	/*
	//copyCallingObjSameLength()
	cout << "\n------copyCallingObjSameLength Test--------\n";

	//---------------------------------------------------
	// ==> Test one element: passed
	// ==> Test more than 1 elemenet: passed
	//---------------------------------------------------

	DonorList list1;
	list1.addDonor("Hoa1", "Ta", 1234, 1000.01);
	//list1.addDonor("Minh1", "Ngo", 12345, 1500.01);
	//list1.addDonor("Nick1", "Richardson", 123456, 2000.01);
	//list1.addDonor("Riana1", "Ali", 1234567, 2500.01);

	DonorList list2;
	list2.addDonor("Huong", "Ta", 1546, 156456.01);
	//list2.addDonor("Minh", "Ngo", 1234, 1500.01);
	//list2.addDonor("Nick", "Richardson", 12345, 2000.01);
	//list2.addDonor("Riana", "Ali", 123456, 2500.01);

	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();

	list1 = list2;
	cout << "\n--------after assign list1 = list2-------- \n";
	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();

	cout << "Empty list1 \n";
	list2.clearList();
	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();

/*
	//copyCallingObjLonger()
	DonorList list1;
	list1.addDonor("Hoa1", "Ta", 1234, 1000.01);
	list1.addDonor("Minh1", "Ngo", 12345, 1500.01);
	list1.addDonor("Nick1", "Richardson", 123456, 2000.01);
	list1.addDonor("Riana1", "Ali", 1234567, 2500.01);

	DonorList list2;
	list2.addDonor("Hoa", "Ta", 123, 1000.01);
	list2.addDonor("Minh", "Ngo", 1234, 1500.01);

	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();

	list1 = list2;
	cout << "after assign list1 = list2 \n";
	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();

	cout << "Empty list1 \n";
	list1.clearList();
	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();
	*/

/*
	//copyCallingObjShorter()
	DonorList list1;
	list1.addDonor("Hoa", "Ta", 123, 1000.01);
	list1.addDonor("Minh", "Ngo", 1234, 1500.01);
	
	DonorList list2;
	list2.addDonor("Hoa1", "Ta", 1234, 1000.01);
	list2.addDonor("Minh1", "Ngo", 12345, 1500.01);
	list2.addDonor("Nick1", "Richardson", 123456, 2000.01);
	list2.addDonor("Riana1", "Ali", 1234567, 2500.01);

	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();

	list1 = list2;
	cout << "after assign list1 = list2 \n";
	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();

	cout << "Empty list1 \n";
	list1.clearList();
	cout << "print list1 \n";
	list1.printAllDonors();
	list1.printAllDonations();

	cout << "print list2 \n";
	list2.printAllDonors();
	list2.printAllDonations();
*/
	

	return 0;
}
