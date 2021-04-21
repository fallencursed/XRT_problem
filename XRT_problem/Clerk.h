#pragma once
#include <iostream>
using  namespace std;
class Clerk
{
protected:
	int Clerk_Id;
	string Clerk_Name;
	string Clerk_Sex;
	int Clerk_age;
public:
	Clerk();
	Clerk(int Clerk_Id,string Clerk_Name, string Clerk_Sex,int Clerk_age);
	void SetCelrk_ID(int Clerk_Id);
	void SetClerk_Name(string Clerk_Name);
	void SetClerk_Sex(string Clerk_Sex);
	void SetClerk_age(int Clerk_age);
	void ShowClerk();
	int GetClerk_Id();
	string GetClerk_Name();
	string GetClerk_Sex();
	~Clerk();
};

