#include "Experimenter.h"

Experimenter::Experimenter()
{
}

Experimenter::Experimenter(int Clerk_Id, string Clerk_Name, string Clerk_Sex, int Clerk_age, string Experimenter_Laboratory, string Experimenter_JobTitle)
{
	this->Clerk_Id = Clerk_Id;
	this->Clerk_Name = Clerk_Name;
	this->Clerk_Sex = Clerk_Sex;
	this->Clerk_age = Clerk_age;
	this->Experimenter_Laboratory = Experimenter_Laboratory;
	this->Experimenter_JobTitle = Experimenter_JobTitle;
}

void Experimenter::SetExperimenter_Laboratory(string Experimenter_Laboratory)
{
	this->Experimenter_Laboratory = Experimenter_Laboratory;
}

void Experimenter::SetExperimenter_JobTitle(string Experimenter_JobTitle)
{
	this->Experimenter_JobTitle = Experimenter_JobTitle;
}


void Experimenter::ShowExperimenter()
{
	cout << "{" << "职员ID:" << Clerk_Id << "职员姓名:" << Clerk_Name << "职员性别:" << Clerk_Sex << "职员年龄:" << Clerk_age << "实验员所在实验室:" << Experimenter_Laboratory << "实验员职称:" << Experimenter_JobTitle  << "}" << endl;
}

Experimenter::~Experimenter()
{
}