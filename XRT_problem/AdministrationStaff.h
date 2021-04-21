#pragma once
#include <iostream>
#include "Clerk.h"
using  namespace std;
class AdministrationStaff :virtual public Clerk
{
protected:
	string AdministrationStaff_PoliticalStatus;
	string AdministrationStaff_JobTitle;
public:
	AdministrationStaff();
	AdministrationStaff(int Clerk_Id, string Clerk_Name, string Clerk_Sex, int Clerk_age, string AdministrationStaff_PoliticalStatus, string AdministrationStaff_JobTitle);
	void SetAdministrationStaff_PoliticalStatus(string AdministrationStaff_PoliticalStatus);
	void SetAdministrationStaff_JobTitle(string AdministrationStaff_JobTitle);
	void ShowAdministrationStaff();
	~AdministrationStaff();
};