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
	cout << "{" << "ְԱID:" << Clerk::Clerk_Id << "ְԱ����:" << Clerk::Clerk_Name << "ְԱ�Ա�:" << Clerk::Clerk_Sex << "ְԱ����:" << Clerk::Clerk_age << "������Ա������Ŀ:" << AdministrationStaff_PoliticalStatus << "������Աְ��:" << AdministrationStaff_JobTitle << "��ʦϵ��:" << Teacher_Departments << "��ʦרҵ:" << Teacher_Profession << "��ʦְ��:" << Teacher_JobTitle<< "}" << endl;
}

TAAS::~TAAS()
{
}