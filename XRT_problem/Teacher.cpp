#include "Teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int Clerk_Id, string Clerk_Name, string Clerk_Sex, int Clerk_age, string Teacher_Departments, string Teacher_Profession, string Teacher_JobTitle)
{
	this->Clerk_Id = Clerk_Id;
	this->Clerk_Name = Clerk_Name;
	this->Clerk_Sex = Clerk_Sex;
	this->Clerk_age = Clerk_age;
	this->Teacher_Departments = Teacher_Departments;
	this->Teacher_Profession = Teacher_Profession;
	this->Teacher_JobTitle = Teacher_JobTitle;
}

void Teacher::SetTeacher_Departments(string Teacher_Departments)
{
	this->Teacher_Departments = Teacher_Departments;
}

void Teacher::SetTeacher_Profession(string Teacher_Profession)
{
	this->Teacher_Profession = Teacher_Profession;
}

void Teacher::SetTeacher_JobTitle(string Teacher_JobTitle)
{
	this->Teacher_JobTitle = Teacher_JobTitle;
}

void Teacher::ShowTeacher()
{
	cout << "{" << "ְԱID:" << Clerk_Id << "ְԱ����:" << Clerk_Name << "ְԱ�Ա�:" << Clerk_Sex << "ְԱ����:" << Clerk_age << "��ʦϵ��:" << Teacher_Departments << "��ʦרҵ:" << Teacher_Profession << "��ʦְ��:" << Teacher_JobTitle << "}" << endl;
}

Teacher::~Teacher()
{
}