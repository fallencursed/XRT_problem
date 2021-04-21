#pragma once
#include <iostream>
#include "Clerk.h"
using  namespace std;
class Teacher :virtual public Clerk
{
protected:
	string Teacher_Departments;
	string Teacher_Profession;
	string Teacher_JobTitle;
public:
	Teacher();
	Teacher(int Clerk_Id, string Clerk_Name, string Clerk_Sex, int Clerk_age,string Teacher_Departments,string Teacher_Profession,string Teacher_JobTitle);
	void SetTeacher_Departments(string Teacher_Departments);
	void SetTeacher_Profession(string Teacher_Profession);
	void SetTeacher_JobTitle(string Teacher_JobTitle);
	void ShowTeacher();
	~Teacher();
};