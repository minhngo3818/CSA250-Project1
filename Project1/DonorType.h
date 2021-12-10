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

#ifndef DONORTYPE_H
#define DONORTYPE_H

#include "MemberType.h"

class DonorType : public MemberType
{
public:
	DonorType();
	DonorType(const std::string& newFirstName, 
			const std::string& newLastName,
			int newMembershipNo, 
			double newAmountDonated);

	void setDonorInfo(const std::string& newFirstName, 
			const std::string& newLastName,
			int newMembershipNo, 
			double newAmountDonated);
	void setAmountDonated(double newAmountDonated);

	double getAmountDonated() const;

	void printDonor() const;
	void printDonation() const;

	~DonorType();
		
	bool operator<(const DonorType& otherDonor) const;

private:
	double amountDonated;
};

#endif
