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
	cout << "{" << "职员ID:" << Clerk_Id << "职员姓名:" << Clerk_Name << "职员性别:" << Clerk_Sex << "职员年龄:" << Clerk_age << "教师系部:" << Teacher_Departments << "教师专业:" << Teacher_Profession << "教师职称:" << Teacher_JobTitle << "}" << endl;
}

Teacher::~Teacher()
{
}