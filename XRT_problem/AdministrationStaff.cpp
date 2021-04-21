#include "AdministrationStaff.h"

AdministrationStaff::AdministrationStaff()
{
}

AdministrationStaff::AdministrationStaff(int Clerk_Id, string Clerk_Name, string Clerk_Sex, int Clerk_age, string AdministrationStaff_PoliticalStatus, string AdministrationStaff_JobTitle)
{
	this->Clerk_Id = Clerk_Id;
	this->Clerk_Name = Clerk_Name;
	this->Clerk_Sex = Clerk_Sex;
	this->Clerk_age = Clerk_age;
	this->AdministrationStaff_PoliticalStatus = AdministrationStaff_PoliticalStatus;
	this->AdministrationStaff_JobTitle = AdministrationStaff_JobTitle;
}

void AdministrationStaff::SetAdministrationStaff_PoliticalStatus(string AdministrationStaff_PoliticalStatus)
{
	this->AdministrationStaff_PoliticalStatus = AdministrationStaff_PoliticalStatus;
}

void AdministrationStaff::SetAdministrationStaff_JobTitle(string AdministrationStaff_JobTitle)
{
	this->AdministrationStaff_JobTitle = AdministrationStaff_JobTitle;
}

void AdministrationStaff::ShowAdministrationStaff()
{
	cout << "{" << "职员ID:" << Clerk_Id << "职员姓名:" << Clerk_Name << "职员性别:" << Clerk_Sex << "职员年龄:" << Clerk_age << "行政人员政治面目:" << AdministrationStaff_PoliticalStatus << "行政人员职称:" << AdministrationStaff_JobTitle << "}" << endl;
}

AdministrationStaff::~AdministrationStaff()
{
}