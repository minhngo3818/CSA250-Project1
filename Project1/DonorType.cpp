#include <iostream>
#include <iomanip>
#include <string>

#include "DonorType.h"

DonorType::DonorType()
{
	// Function body
}


DonorType::DonorType(const std::string& newFirstName,
	const std::string& newLastName,
	int newMembershipNum,
	double newAmountDonated) : MemberType{ newFirstName,
									newLastName, newMembershipNum } {}
{
	// Function body
}


void DonorType::setDonorInfo(const std::string& newFirstName,
	const std::string& LastName,
	int newMembershipNum, double newAmountDonated) 
{
	// Function body
}


void DonorType::setAmountDonated(double newAmountDonated)
{
	// Function body
}


double DonorType::getAmountDonated() const
{
	// Function body
}


void DonorType::printDonor() const
{
	// Function body
}


void DonorType::printDonation() const
{
	// Function body
}


DonorType::~DonorType()
{
	// Function body
}