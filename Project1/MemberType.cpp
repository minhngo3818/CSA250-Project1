/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	November 22, 2021

	CS A250
	Project 1
*/

#include "MemberType.h"

using namespace std;

MemberType::MemberType() : firstName("N/A"),
	lastName("N/A"), membershipNo(0) {}

MemberType::MemberType(const string& newFirstName,
	const string& newLastName, int newMembershipNo)
	: firstName(newFirstName), lastName(newLastName),
			membershipNo(newMembershipNo) {}

void MemberType::setMemberInfo(const string& newFirstName,
	const string& newLastName, int newMembershipNo)
{
	firstName = newFirstName;
	lastName = newLastName;
	membershipNo = newMembershipNo;
}

string MemberType::getFirstName() const
{
	return firstName;
}

string MemberType::getLastName() const
{
	return lastName;
}

int MemberType::getMembershipNo() const
{
	return membershipNo;
}

void MemberType::printName() const
{
	cout << lastName << ", " << firstName << endl;
}

void MemberType::printMemberInfo() const
{
	cout << membershipNo << " - "  
	<< firstName << " " << lastName << endl;
}

MemberType::~MemberType()
{
	membershipNo = 0;
}
