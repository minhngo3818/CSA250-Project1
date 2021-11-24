#ifndef DONORTYPE_H
#define DONORTYPE_H

#include "MemberType.h"
#include <string>

class DonorType : public MemberType
{
	public:
		DonorType();

		DonorType(const std::string& newFirstName,
			const std::string& newLastName,
			int newMembershipNum, 
			double newAmountDonated) : MemberType{ newFirstName, 
											newLastName, newMembershipNum } {};

		void setDonorInfo(const std::string& newFirstName,
			const std::string& LastName,
			int newMembershipNum, double newAmountDonated) {};

		void setAmountDonated(double newAmountDonated);

		double getAmountDonated() const;

		void printDonor() const;

		void printDonation() const;

		~DonorType();

	private:
		double amountDonated;


};

#endif

