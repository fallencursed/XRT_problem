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
	cout << "{" << "ְԱID:" << Clerk_Id << "ְԱ����:" << Clerk_Name << "ְԱ�Ա�:" << Clerk_Sex << "ְԱ����:" << Clerk_age << "ʵ��Ա����ʵ����:" << Experimenter_Laboratory << "ʵ��Աְ��:" << Experimenter_JobTitle  << "}" << endl;
}

Experimenter::~Experimenter()
{
}