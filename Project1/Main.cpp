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

#include <iostream>
#include <iomanip>
#include <string>
	
using namespace std;

int main()
{

	cout << "--------------First Project-----------------\n";

	//member class testing
	MemberType member1;
	MemberType member2("Doug", "Jones", 1);
	
	cout << "accessor & default check : N/A N/A 0" << endl
		<< member1.getFirstName() << " " << member1.getLastName() << " "
		<< member1.getMembershipNo() << endl;
	cout << "Testing set function..." << endl;
	member2.printMemberInfo();
	member2.setMemberInfo("Tommy", "Zhou", 2);
	cout << "setMemberInfo check : 2 - Tommy Zhou" << endl;
	member2.printMemberInfo();
	cout << endl;

	cout << "Testing print functions..." << endl;
	member2.printName();
	member2.printMemberInfo();
	member2.~MemberType();

	string line = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << line << endl; //comment

	//donor class testing
	DonorType donor1;
	DonorType donor2("Mark", "Smith", 3, 3.41);
	cout << "accessor & default check : N/A N/A 0 0.0" << endl
		<< donor1.getFirstName() << " " << donor1.getLastName() << " "
		<< donor1.getMembershipNo() << " " << donor1.getAmountDonated()
		<< endl;
	cout << endl;

	cout << "Testing set function..." << endl;
	cout << "3.41 = " << donor2.getAmountDonated() << endl;
	donor2.setAmountDonated(14.23);
	cout << "14.23 = " << donor2.getAmountDonated() << endl;
	cout << endl;

	cout << "Testing print functions..." << endl;
	cout << "3 - Mark Smith";
	donor2.printDonor();
	cout << "Smith, Mark" << endl 
		<< "   Donation Amount: $14.23" << endl;
	donor2.printDonation();
	donor2.~DonorType();

	system("Pause");
	return 0;
}
