#include "Clerk.h"

Clerk::Clerk()
{
}

Clerk::Clerk(int Clerk_Id, string Clerk_Name, string Clerk_Sex, int Clerk_age)
{
	this->Clerk_Id = Clerk_Id;
	this->Clerk_Name = Clerk_Name;
	this->Clerk_Sex = Clerk_Sex;
	this->Clerk_age = Clerk_age;
}

void Clerk::SetCelrk_ID(int Clerk_Id)
{
	this->Clerk_Id = Clerk_Id;
}

void Clerk::SetClerk_Name(string Clerk_Name)
{
	this->Clerk_Name = Clerk_Name;
}

void Clerk::SetClerk_Sex(string Clerk_Sex)
{
	this->Clerk_Sex = Clerk_Sex;
}
void Clerk::SetClerk_age(int Clerk_age)
{
	this->Clerk_age = Clerk_age;
}

void Clerk::ShowClerk()
{
	cout << "{" << "职员ID:" << Clerk_Id << "职员姓名:" << Clerk_Name << "职员性别:" << Clerk_Sex << "职员年龄:" << Clerk_age <<"}" << endl;
}

int Clerk::GetClerk_Id()
{
	return Clerk_Id;
}
string Clerk::GetClerk_Name() {
	return Clerk_Name;
}
string Clerk::GetClerk_Sex() {
	return Clerk_Sex;
}
Clerk::~Clerk()
{
}
