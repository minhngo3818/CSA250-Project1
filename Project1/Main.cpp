/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana Ali

	November 22, 2021

	CSA 250
	Project 1
*/
#include "DonorType.h"
#include "MemberType.h"

#include <iostream>
#include <string>
	
int main()
{

	std::cout << "Hi there, This is the first project\n";

	//member class testing
	MemberType member1;
	MemberType member2("Doug", "Jones", 1);
	
	std::cout << "accessor & default check : N/A N/A 0" << std::endl
		<< member1.getFirstName() << " " << member1.getLastName() << " "
		<< member1.getMembershipNo() << std::endl;
	std::cout << "Testing set function..." << std::endl;
	member2.printMemberInfo;
	member2.setMemberInfo(Tommy, Zhou, 2);
	std::cout << "setMemberInfo check : 2 - Tommy Zhou" << std::endl;
	member2.printMemberInfo;

	std::cout << "Testing print functions..." << std::endl;
	member2.printName();
	member2.printMemberInfo;
	~member2;
	std::string line = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << line << std::endl;
	//donor class testing
	DonorType donor1;
	DonorType donor2("Mark", "Smith", 3, 3.41);
	std::cout << "accessor & default check : N/A N/A 0 0.0" << std::endl
		<< donor1.getFirstName() << " " << donor1.getLastName() << " "
		<< donor1.getMembershipNo() << " " << donor1.getAmountDonated()
		<< std::endl;
	std::cout << "Testing set function..." << std::endl;
	std::cout << "3.41 = " << donor2.getAmountDonated() << std::endl;
	donor2.setAmountDonated(14.23);
	std::cout << "14.23 = " << donor2.getAmountDonated() << std::endl;

	std::cout << "Testing print functions..." << std::endl;
	std::cout << "3 - Mark Smith";
	donor2.printDonor();
	std::cout << "Smith, Mark" << std::endl 
		<< "   Donation Amount: $14.23" << std::endl;
	donor2.printDonation();
	~donor2;

	
	system("Pause");
	return 0;
}
