/*
	Night Owls

	Breton, Liam (leader)
	Ta, Hoa
	Ngo, Minh
	Richardson, Nick
	Riana, Ali

	November 27, 2021

	CS A250
	Project 1
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "DonorList.h"

void displayMenu();
void processSelection(DonorList& aDonorList);
void addDonor(DonorList& aDonorList);
void deleteDonor(DonorList& aDonorList);
void printAllDonors(const DonorList& aDonorList);

#endif
