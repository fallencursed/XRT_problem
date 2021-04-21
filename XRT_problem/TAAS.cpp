#include "TAAS.h"
#include <iostream>
TAAS::TAAS()
{
}

TAAS::TAAS(int Clerk_Id, string Clerk_Name, string Clerk_Sex, int Clerk_age, string AdministrationStaff_PoliticalStatus, string AdministrationStaff_JobTitle, string Teacher_Departments, string Teacher_Profession, string Teacher_JobTitle)
{
	this->Clerk::Clerk_Id = Clerk_Id;
	this->Clerk::Clerk_Name = Clerk_Name;
	this->Clerk::Clerk_Sex = Clerk_Sex;
	this->Clerk::Clerk_age = Clerk_age;
	this->AdministrationStaff_PoliticalStatus = AdministrationStaff_PoliticalStatus;
	this->AdministrationStaff_JobTitle = AdministrationStaff_JobTitle;
	this->Teacher_Departments = Teacher_Departments;
	this->Teacher_Profession = Teacher_Profession;
	this->Teacher_JobTitle = Teacher_JobTitle;
}

void TAAS::ShowTAAS()
{
	cout << "{" << "职员ID:" << Clerk::Clerk_Id << "职员姓名:" << Clerk::Clerk_Name << "职员性别:" << Clerk::Clerk_Sex << "职员年龄:" << Clerk::Clerk_age << "行政人员政治面目:" << AdministrationStaff_PoliticalStatus << "行政人员职称:" << AdministrationStaff_JobTitle << "教师系部:" << Teacher_Departments << "教师专业:" << Teacher_Profession << "教师职称:" << Teacher_JobTitle<< "}" << endl;
}

TAAS::~TAAS()
{
}