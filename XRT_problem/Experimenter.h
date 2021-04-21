#pragma once
#include <iostream>
#include "Clerk.h"
using  namespace std;
class Experimenter :virtual public Clerk
{
protected:
	string Experimenter_Laboratory;
	string Experimenter_JobTitle;
public:
	Experimenter();
	Experimenter(int Clerk_Id, string Clerk_Name, string Clerk_Sex, int Clerk_age, string Experimenter_Laboratory, string Experimenter_JobTitle);
	void SetExperimenter_Laboratory(string Experimenter_Laboratory);
	void SetExperimenter_JobTitle(string Experimenter_JobTitle);
	void ShowExperimenter();
	~Experimenter();
};