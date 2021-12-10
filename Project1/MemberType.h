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

#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <string>

class MemberType
{
public:
	MemberType();
	MemberType(const std::string& newFirstName,
		const std::string& newLastName, int newMembershipNo);

	void setMemberInfo(const std::string& newFirstName,
		const std::string& newLastName, int newMembershipNo);

	std::string getFirstName() const;
	std::string getLastName() const;
	int getMembershipNo() const;

	void printName() const;
	void printMemberInfo() const;

	~MemberType();
		
private:
	std::string firstName;
	std::string lastName;
	int membershipNo;

};

#endif
