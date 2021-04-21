#pragma once
#include"Teacher.h"
#include"AdministrationStaff.h"
class TAAS :public AdministrationStaff,Teacher
{
public:
	TAAS();
	TAAS(int Clerk_Id, string Clerk_Name, string Clerk_Sex, int Clerk_age, string AdministrationStaff_PoliticalStatus, string AdministrationStaff_JobTitle, string Teacher_Departments, string Teacher_Profession, string Teacher_JobTitle);
	void ShowTAAS();
	~TAAS();
};