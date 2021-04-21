#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <vector>
#include<Windows.h>
#include "Teacher.h"
#include "AdministrationStaff.h"
#include "Experimenter.h"
#include "TAAS.h"
#include "mysql.h"
#include <cstdlib> 
#include <string>
#pragma comment(lib, "libmysql.lib")
using namespace std;
vector<Teacher> TeacherList;
vector<AdministrationStaff> AdministrationStaffList;
vector<Experimenter> ExperimenterList;
vector<TAAS> TAASList;
MYSQL mysql, * sock; //声明MySQL的句柄 
MYSQL_RES* selectMysql(const char* i_query, MYSQL mysql) {
	MYSQL_RES* result;
	if (mysql_query(&mysql, i_query) != 0) //如果连接成功，则开始查询 .成功返回0
	{
		fprintf(stderr, "fail to query!\n");
		exit(1);
	}
	else
	{
		
		if ((result = mysql_store_result(&mysql)) == NULL) //保存查询的结果 
		{
			fprintf(stderr, "fail to store result!\n");
			exit(1);
		}
		else
		{
			return result;
		}

	}
}
void start() {
	const char* host = "127.0.0.1"; //因为是作为本机测试，所以填写的是本地IP 
	const char* user = "root"; //这里改为你的用户名，即连接MySQL的用户名 
	const char* passwd = "123456"; //这里改为你的用户密码 
	const char* db = "webdb"; //这里改为你要连接的数据库的名字,一个数据可能有几张表
	unsigned int port = 3306; //这是MySQL的服务器的端口，如果你没有修改过的话就是3306。 
	const char* unix_socket = NULL; //unix_socket这是unix下的，我在Windows下，所以就把它设置为NULL 
	unsigned long client_flag = 0; //这个参数一般为0 
	const char* i_query_teacher = "SELECT * FROM teacher"; //查询语句，从那个表中查询
	const char* i_query_administrationStaff = "SELECT * FROM administrationStaff"; //查询语句，从那个表中查询,
	const char* i_query_experimenter = "SELECT * FROM experimenter"; //查询语句，从那个表中查询,
	const char* i_query_taas = "SELECT * FROM taas"; //查询语句，从那个表中查询,
	mysql_init(&mysql); //连接之前必须使用这个函数来初始化 
	
	if ((sock = mysql_real_connect(&mysql, host, user, passwd, db, port, unix_socket, client_flag)) == NULL) //连接MySQL 
	{
		printf("fail to connect mysql \n");
		fprintf(stderr, " %s\n", mysql_error(&mysql));
		exit(1);
	}
	else
	{
		fprintf(stderr, "connect ok!!\n");
	}
	mysql_query(&mysql, "set names gbk");
	MYSQL_RES* resultTeacher = selectMysql(i_query_teacher, mysql); //保存结果集的
	MYSQL_RES* resultAdministrationStaff = selectMysql(i_query_administrationStaff, mysql); //保存结果集的
	MYSQL_RES* resultExperimenter = selectMysql(i_query_experimenter, mysql); //保存结果集的
	MYSQL_RES* resultTAAS = selectMysql(i_query_taas, mysql); //保存结果集的
	MYSQL_ROW rowTeacher; //代表的是结果集中的一行 
	MYSQL_ROW rowAdministrationStaff; //代表的是结果集中的一行 
	MYSQL_ROW rowExperimenter; //代表的是结果集中的一行 
	MYSQL_ROW rowTAAS; //代表的是结果集中的一行 
	while ((rowTeacher = mysql_fetch_row(resultTeacher)) != NULL) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】 
	{
		TeacherList.push_back(Teacher(atoi(rowTeacher[0]), rowTeacher[1], rowTeacher[2], atoi(rowTeacher[3]), rowTeacher[4], rowTeacher[5], rowTeacher[6]));
	}
	while ((rowAdministrationStaff = mysql_fetch_row(resultAdministrationStaff)) != NULL) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】 
	{
		AdministrationStaffList.push_back(AdministrationStaff(atoi(rowAdministrationStaff[0]), rowAdministrationStaff[1], rowAdministrationStaff[2], atoi(rowAdministrationStaff[3]), rowAdministrationStaff[4], rowAdministrationStaff[5]));
	}
	while ((rowExperimenter = mysql_fetch_row(resultExperimenter)) != NULL) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】 
	{
		ExperimenterList.push_back(Experimenter(atoi(rowExperimenter[0]), rowExperimenter[1], rowExperimenter[2], atoi(rowExperimenter[3]), rowExperimenter[4], rowExperimenter[5]));
	}
	while ((rowTAAS = mysql_fetch_row(resultTAAS)) != NULL) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】 
	{
		TAASList.push_back(TAAS(atoi(rowTAAS[0]), rowTAAS[1], rowTAAS[2], atoi(rowTAAS[3]), rowTAAS[4], rowTAAS[5], rowTAAS[6], rowTAAS[7] , rowTAAS[8]));
	}
	mysql_free_result(resultTeacher); //释放结果集 
	mysql_free_result(resultAdministrationStaff); //释放结果集 
	mysql_free_result(resultExperimenter); //释放结果集 
	mysql_free_result(resultTAAS); //释放结果集 
	
	for (auto i: TAASList) {
		i.ShowTAAS();
	}
}
bool hasIdRepeat(int Clerk_Id) {
	for (auto i : TAASList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			return true;
		}
	}
	for (auto i : TeacherList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			return true;
		}
	}
	for (auto i : ExperimenterList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			return true;
		}
	}
	for (auto i : AdministrationStaffList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			return true;
		}
	}
	return false;
}
bool hasIdRepeatTAAS(int Clerk_Id) {
	for (auto i : TAASList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			return true;
		}
	}
	return false;
}
bool hasIdRepeatExperimenter(int Clerk_Id) {
	for (auto i : ExperimenterList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			return true;
		}
	}
	return false;
}
bool hasIdRepeatAdministrationStaff(int Clerk_Id) {
	for (auto i : AdministrationStaffList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			return true;
		}
	}
	return false;
}
bool hasIdRepeatTeacher(int Clerk_Id) {
	for (auto i : TeacherList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			return true;
		}
	}
	return false;
}
void addTeacher() {
	
	int Clerk_Id;
	string Clerk_Name;
	string Clerk_Sex;
	int Clerk_age;
	string Teacher_Departments;
	string Teacher_Profession;
	string  Teacher_JobTitle;
	cout << "请输入教师信息" << endl;
	cout << "教师ID为" << endl;
	cin >> Clerk_Id;
	cout << "教师姓名为" << endl;
	cin >> Clerk_Name;
	cout << "教师性别为" << endl;
	cin >> Clerk_Sex;
	cout << "教师年龄为" << endl;
	cin >> Clerk_age;
	cout << "教师所在系部为" << endl;
	cin >> Teacher_Departments;
	cout << "教师专业为" << endl;
	cin >> Teacher_Profession;
	cout << "教师职称为" << endl;
	cin >> Teacher_JobTitle;
	if (!hasIdRepeat(Clerk_Id)) {
		TeacherList.push_back(Teacher(Clerk_Id, Clerk_Name, Clerk_Sex, Clerk_age, Teacher_Departments, Teacher_Profession, Teacher_JobTitle));

		string i_insert_teacher = "Insert into teacher values(";
		i_insert_teacher.append(to_string(Clerk_Id));
		i_insert_teacher.append(",'");
		i_insert_teacher.append(Clerk_Name);
		i_insert_teacher.append("','");
		i_insert_teacher.append(Clerk_Sex);
		i_insert_teacher.append("',");
		i_insert_teacher.append(to_string(Clerk_age));
		i_insert_teacher.append(",'");
		i_insert_teacher.append(Teacher_Departments);
		i_insert_teacher.append("','");
		i_insert_teacher.append(Teacher_Profession);
		i_insert_teacher.append("','");
		i_insert_teacher.append(Teacher_JobTitle);
		i_insert_teacher.append("')");
		cout << i_insert_teacher << endl;
		mysql_query(&mysql, data(i_insert_teacher));
	}
	else
		cout << "错误，ID重复" << endl;
}
void addAdministrationStaff() {

	int Clerk_Id;
	string Clerk_Name;
	string Clerk_Sex;
	int Clerk_age;
	string AdministrationStaff_PoliticalStatus;
	string AdministrationStaff_JobTitle;
	cout << "请输入行政人员信息" << endl;
	cout << "行政人员ID为" << endl;
	cin >> Clerk_Id;
	cout << "行政人员姓名为" << endl;
	cin >> Clerk_Name;
	cout << "行政人员性别为" << endl;
	cin >> Clerk_Sex;
	cout << "行政人员年龄为" << endl;
	cin >> Clerk_age;
	cout << "行政人员政治面貌为" << endl;
	cin >> AdministrationStaff_PoliticalStatus;
	cout << "行政人员职称为" << endl;
	cin >> AdministrationStaff_JobTitle;
	if (!hasIdRepeat(Clerk_Id)) {
		AdministrationStaffList.push_back(AdministrationStaff(Clerk_Id, Clerk_Name, Clerk_Sex, Clerk_age, AdministrationStaff_PoliticalStatus, AdministrationStaff_JobTitle));

		string i_insert_administrationstaff = "Insert into administrationstaff values(";
		i_insert_administrationstaff.append(to_string(Clerk_Id));
		i_insert_administrationstaff.append(",'");
		i_insert_administrationstaff.append(Clerk_Name);
		i_insert_administrationstaff.append("','");
		i_insert_administrationstaff.append(Clerk_Sex);
		i_insert_administrationstaff.append("',");
		i_insert_administrationstaff.append(to_string(Clerk_age));
		i_insert_administrationstaff.append(",'");
		i_insert_administrationstaff.append(AdministrationStaff_PoliticalStatus);
		i_insert_administrationstaff.append("','");
		i_insert_administrationstaff.append(AdministrationStaff_JobTitle);
		i_insert_administrationstaff.append("')");
		mysql_query(&mysql, data(i_insert_administrationstaff));
	}
	else
		cout << "错误，ID重复" << endl;
}
void addExperimenter() {

	int Clerk_Id;
	string Clerk_Name;
	string Clerk_Sex;
	int Clerk_age;
	string Experimenter_Laboratory;
	string Experimenter_JobTitle;
	cout << "请输入实验员信息" << endl;
	cout << "实验员ID为" << endl;
	cin >> Clerk_Id;
	cout << "实验员姓名为" << endl;
	cin >> Clerk_Name;
	cout << "实验员性别为" << endl;
	cin >> Clerk_Sex;
	cout << "实验员年龄为" << endl;
	cin >> Clerk_age;
	cout << "实验员所在实验室为" << endl;
	cin >> Experimenter_Laboratory;
	cout << "实验员职务为" << endl;
	cin >> Experimenter_JobTitle;
	if (!hasIdRepeat(Clerk_Id)) {
		ExperimenterList.push_back(Experimenter(Clerk_Id, Clerk_Name, Clerk_Sex, Clerk_age, Experimenter_Laboratory, Experimenter_JobTitle));

		string i_insert_experimenter = "Insert into experimenter values(";
		i_insert_experimenter.append(to_string(Clerk_Id));
		i_insert_experimenter.append(",'");
		i_insert_experimenter.append(Clerk_Name);
		i_insert_experimenter.append("','");
		i_insert_experimenter.append(Clerk_Sex);
		i_insert_experimenter.append("',");
		i_insert_experimenter.append(to_string(Clerk_age));
		i_insert_experimenter.append(",'");
		i_insert_experimenter.append(Experimenter_Laboratory);
		i_insert_experimenter.append("','");
		i_insert_experimenter.append(Experimenter_JobTitle);
		i_insert_experimenter.append("')");
		mysql_query(&mysql, data(i_insert_experimenter));
	}
	else
		cout << "错误，ID重复" << endl;
}
void addTAAS() {

	int Clerk_Id;
	string Clerk_Name;
	string Clerk_Sex;
	int Clerk_age;
	string AdministrationStaff_PoliticalStatus;
	string AdministrationStaff_JobTitle;
	string Teacher_Departments;
	string Teacher_Profession;
	string Teacher_JobTitle;
	cout << "请输入教师兼行政人员信息" << endl;
	cout << "教师兼行政人员ID为" << endl;
	cin >> Clerk_Id;
	cout << "教师兼行政人员员姓名为" << endl;
	cin >> Clerk_Name;
	cout << "教师兼行政人员性别为" << endl;
	cin >> Clerk_Sex;
	cout << "教师兼行政人员年龄为" << endl;
	cin >> Clerk_age;
	cout << "教师兼行政人员政治面貌为" << endl;
	cin >> AdministrationStaff_PoliticalStatus;
	cout << "教师兼行政人员的行政人员职称为" << endl;
	cin >> AdministrationStaff_JobTitle;
	cout << "教师兼行政人员所在系部为" << endl;
	cin >> Teacher_Departments;
	cout << "教师兼行政人员专业为" << endl;
	cin >> Teacher_Profession;
	cout << "教师兼行政人员的教师职称为" << endl;
	cin >> Teacher_JobTitle;
	if (!hasIdRepeat(Clerk_Id)) {
		TAASList.push_back(TAAS(Clerk_Id, Clerk_Name, Clerk_Sex, Clerk_age, AdministrationStaff_PoliticalStatus, AdministrationStaff_JobTitle, Teacher_Departments, Teacher_Profession, Teacher_JobTitle));

		string i_insert_TAAS = "Insert into taas values(";
		i_insert_TAAS.append(to_string(Clerk_Id));
		i_insert_TAAS.append(",'");
		i_insert_TAAS.append(Clerk_Name);
		i_insert_TAAS.append("','");
		i_insert_TAAS.append(Clerk_Sex);
		i_insert_TAAS.append("',");
		i_insert_TAAS.append(to_string(Clerk_age));
		i_insert_TAAS.append(",'");
		i_insert_TAAS.append(AdministrationStaff_PoliticalStatus);
		i_insert_TAAS.append("','");
		i_insert_TAAS.append(AdministrationStaff_JobTitle);
		i_insert_TAAS.append("','");
		i_insert_TAAS.append(Teacher_Departments);
		i_insert_TAAS.append("','");
		i_insert_TAAS.append(Teacher_Profession);
		i_insert_TAAS.append("','");
		i_insert_TAAS.append(Teacher_JobTitle);
		i_insert_TAAS.append("')");
		mysql_query(&mysql, data(i_insert_TAAS));
	}
	else
		cout << "错误，ID重复" << endl;
}
void serchAllId(int Clerk_Id) {
	for (auto i : TAASList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			i.ShowTAAS();
			return ;
		}
	}
	for (auto i : TeacherList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			i.ShowTeacher();
			return ;
		}
	}
	for (auto i : ExperimenterList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			i.ShowExperimenter();
			return ;
		}
	}
	for (auto i : AdministrationStaffList) {
		if (i.GetClerk_Id() == Clerk_Id) {
			i.ShowAdministrationStaff();
			return ;
		}
	}
	cout << "没有查找到该人员" << endl;
}
void serchAllName(string Clerk_Name) {
	bool hasGet = false;
	for (auto i : TAASList) {
		if (i.GetClerk_Name() == Clerk_Name) {
			i.ShowTAAS();
			
		}
	}
	for (auto i : TeacherList) {
		if (i.GetClerk_Name() == Clerk_Name) {
			i.ShowTeacher();
			
		}
	}
	for (auto i : ExperimenterList) {
		if (i.GetClerk_Name() == Clerk_Name) {
			i.ShowExperimenter();
			
		}
	}
	for (auto i : AdministrationStaffList) {
		if (i.GetClerk_Name() == Clerk_Name) {
			i.ShowAdministrationStaff();
			
		}
	}
	if (!hasGet) {
		cout << "没有查找到该人员" << endl;
	}
}
void showAll() {
	for (auto i : TAASList) {
		i.ShowTAAS();
	}
	for (auto i : TeacherList) {
		i.ShowTeacher();
	}
	for (auto i : ExperimenterList) {
		i.ShowExperimenter();
	}
	for (auto i : AdministrationStaffList) {
		i.ShowAdministrationStaff();
	}
}
void deleteId(int Clerk_Id) {
	for (int i = 0; i < TAASList.size();i++) {
		if (TAASList[i].GetClerk_Id() == Clerk_Id) {
			TAASList.erase(TAASList.begin() + i);
			string i_delete_TAAS = "DELETE FROM taas WHERE Clerk_Id=";
			i_delete_TAAS.append(to_string(Clerk_Id));
			mysql_query(&mysql, data(i_delete_TAAS));
			return ;
		}
	}
	for (int i = 0; i < TeacherList.size(); i++) {
		if (TeacherList[i].GetClerk_Id() == Clerk_Id) {
			TeacherList.erase(TeacherList.begin() + i);
			string i_delete_Teacher = "DELETE FROM teacher WHERE Clerk_Id=";
			i_delete_Teacher.append(to_string(Clerk_Id));
			mysql_query(&mysql, data(i_delete_Teacher));
			return ;
		}
	}
	for (int i = 0; i < ExperimenterList.size(); i++) {
		if (ExperimenterList[i].GetClerk_Id() == Clerk_Id) {
			ExperimenterList.erase(ExperimenterList.begin() + i);
			string i_delete_Experimenter = "DELETE FROM experimenter WHERE Clerk_Id=";
			i_delete_Experimenter.append(to_string(Clerk_Id));
			mysql_query(&mysql, data(i_delete_Experimenter));
			return ;
		}
	}
	for (int i = 0; i < AdministrationStaffList.size(); i++) {
		if (AdministrationStaffList[i].GetClerk_Id() == Clerk_Id) {
			AdministrationStaffList.erase(AdministrationStaffList.begin()+i);
			string i_delete_AdministrationStaff = "DELETE FROM administrationstaff WHERE Clerk_Id=";
			i_delete_AdministrationStaff.append(to_string(Clerk_Id));
			mysql_query(&mysql, data(i_delete_AdministrationStaff));
			return ;
		}
	}
	cout << "没有查找到该人员" << endl;
}
void deleteName(string Clerk_Name) {
	for (int i = 0; i < TAASList.size(); i++) {
		if (TAASList[i].GetClerk_Name() == Clerk_Name) {
			TAASList.reserve(i);
			string i_delete_TAAS = "DELETE FROM taas WHERE Clerk_Name='";
			i_delete_TAAS.append(Clerk_Name);
			i_delete_TAAS.append("'");
			mysql_query(&mysql, data(i_delete_TAAS));
			return;
		}
	}
	for (int i = 0; i < TeacherList.size(); i++) {
		if (TeacherList[i].GetClerk_Name() == Clerk_Name) {
			TeacherList.reserve(i);
			string i_delete_Teacher = "DELETE FROM teacher WHERE Clerk_Name=";
			i_delete_Teacher.append(Clerk_Name);
			i_delete_Teacher.append("'");
			mysql_query(&mysql, data(i_delete_Teacher));
			return;
		}
	}
	for (int i = 0; i < ExperimenterList.size(); i++) {
		if (ExperimenterList[i].GetClerk_Name() == Clerk_Name) {
			ExperimenterList.reserve(i);
			string i_delete_Experimenter = "DELETE FROM experimenter WHERE Clerk_Name=";
			i_delete_Experimenter.append(Clerk_Name);
			i_delete_Experimenter.append("'");
			mysql_query(&mysql, data(i_delete_Experimenter));
			return;
		}
	}
	for (int i = 0; i < AdministrationStaffList.size(); i++) {
		if (AdministrationStaffList[i].GetClerk_Name() == Clerk_Name) {
			AdministrationStaffList.reserve(i);
			string i_delete_AdministrationStaff = "DELETE FROM administrationstaff WHERE Clerk_Name=";
			i_delete_AdministrationStaff.append(Clerk_Name);
			i_delete_AdministrationStaff.append("'");
			mysql_query(&mysql, data(i_delete_AdministrationStaff));
			return;
		}
	}
	cout << "没有查找到该人员" << endl;
}
void updateTeacher(int Clerk_Id) {
	string Clerk_Name;
	string Clerk_Sex;
	int Clerk_age;
	string Teacher_Departments;
	string Teacher_Profession;
	string  Teacher_JobTitle;
	for (int i = 0; i < TeacherList.size(); i++) {
		if (TeacherList[i].GetClerk_Id() == Clerk_Id) {
			TeacherList[i].ShowTeacher();
			cout << "教师姓名为" << endl;
			cin >> Clerk_Name;
			cout << "教师性别为" << endl;
			cin >> Clerk_Sex;
			cout << "教师年龄为" << endl;
			cin >> Clerk_age;
			cout << "教师所在系部为" << endl;
			cin >> Teacher_Departments;
			cout << "教师专业为" << endl;
			cin >> Teacher_Profession;
			cout << "教师职称为" << endl;
			cin >> Teacher_JobTitle;
			TeacherList[i] = Teacher(Clerk_Id, Clerk_Name, Clerk_Sex, Clerk_age, Teacher_Departments, Teacher_Profession, Teacher_JobTitle);
		}
	}

		string i_update_teacher = "UPDATE teacher SET Clerk_Name=' ";
		i_update_teacher.append(Clerk_Name);
		i_update_teacher.append("',Clerk_Sex='");
		i_update_teacher.append(Clerk_Sex);
		i_update_teacher.append("',Clerk_age=");
		i_update_teacher.append(to_string(Clerk_age));
		i_update_teacher.append(",Teacher_Departments='");
		i_update_teacher.append(Teacher_Departments);
		i_update_teacher.append("',Teacher_Profession='");
		i_update_teacher.append(Teacher_Profession);
		i_update_teacher.append("',Teacher_JobTitle='");
		i_update_teacher.append(Teacher_JobTitle);
		i_update_teacher.append("' WHERE Clerk_Id=");
		i_update_teacher.append(to_string(Clerk_Id));
		cout << i_update_teacher << endl;
		mysql_query(&mysql, data(i_update_teacher));
}
void updateAdministrationStaff(int Clerk_Id) {
	string Clerk_Name;
	string Clerk_Sex;
	int Clerk_age;
	string AdministrationStaff_PoliticalStatus;
	string AdministrationStaff_JobTitle;
		for (int i = 0; i < AdministrationStaffList.size(); i++) {
			if (AdministrationStaffList[i].GetClerk_Id() == Clerk_Id) {
				AdministrationStaffList[i].ShowAdministrationStaff();
				cout << "行政管理人员姓名为" << endl;
				cin >> Clerk_Name;
				cout << "行政管理人员性别为" << endl;
				cin >> Clerk_Sex;
				cout << "行政管理人员年龄为" << endl;
				cin >> Clerk_age;
				cout << "行政人员政治面貌为" << endl;
				cin >> AdministrationStaff_PoliticalStatus;
				cout << "行政人员职称为" << endl;
				cin >> AdministrationStaff_JobTitle;
				AdministrationStaffList[i] = AdministrationStaff(Clerk_Id, Clerk_Name, Clerk_Sex, Clerk_age, AdministrationStaff_PoliticalStatus, AdministrationStaff_JobTitle);
			}
		}

		string i_update_AdministrationStaff = "UPDATE administrationstaff SET Clerk_Name=' ";
		i_update_AdministrationStaff.append(Clerk_Name);
		i_update_AdministrationStaff.append("',Clerk_Sex='");
		i_update_AdministrationStaff.append(Clerk_Sex);
		i_update_AdministrationStaff.append("',Clerk_age=");
		i_update_AdministrationStaff.append(to_string(Clerk_age));
		i_update_AdministrationStaff.append(",AdministrationStaff_PoliticalStatus='");
		i_update_AdministrationStaff.append(AdministrationStaff_PoliticalStatus);
		i_update_AdministrationStaff.append("',AdministrationStaff_JobTitle='");
		i_update_AdministrationStaff.append(AdministrationStaff_JobTitle);
		i_update_AdministrationStaff.append("' WHERE Clerk_Id=");
		i_update_AdministrationStaff.append(to_string(Clerk_Id));
		cout << i_update_AdministrationStaff << endl;
		mysql_query(&mysql, data(i_update_AdministrationStaff));
}
void updateExperimenter(int Clerk_Id) {
	string Clerk_Name;
	string Clerk_Sex;
	int Clerk_age;
	string Experimenter_Laboratory;
	string Experimenter_JobTitle;
		for (int i = 0; i < ExperimenterList.size(); i++) {
			if (ExperimenterList[i].GetClerk_Id() == Clerk_Id) {
				AdministrationStaffList[i].ShowAdministrationStaff();
				cout << "实验员姓名为" << endl;
				cin >> Clerk_Name;
				cout << "实验员性别为" << endl;
				cin >> Clerk_Sex;
				cout << "实验员年龄为" << endl;
				cin >> Clerk_age;
				cout << "实验员所在实验室为" << endl;
				cin >> Experimenter_Laboratory;
				cout << "实验员职称为" << endl;
				cin >> Experimenter_JobTitle;
				ExperimenterList[i] = Experimenter(Clerk_Id, Clerk_Name, Clerk_Sex, Clerk_age, Experimenter_Laboratory, Experimenter_JobTitle);
			}
		}

		string i_update_Experimenter = "UPDATE experimenter SET Clerk_Name=' ";
		i_update_Experimenter.append(Clerk_Name);
		i_update_Experimenter.append("',Clerk_Sex='");
		i_update_Experimenter.append(Clerk_Sex);
		i_update_Experimenter.append("',Clerk_age=");
		i_update_Experimenter.append(to_string(Clerk_age));
		i_update_Experimenter.append(",Experimenter_Laboratory='");
		i_update_Experimenter.append(Experimenter_Laboratory);
		i_update_Experimenter.append("',Experimenter_JobTitle='");
		i_update_Experimenter.append(Experimenter_JobTitle);
		i_update_Experimenter.append("' WHERE Clerk_Id=");
		i_update_Experimenter.append(to_string(Clerk_Id));
		cout << i_update_Experimenter << endl;
		mysql_query(&mysql, data(i_update_Experimenter));
}
void updateTAAS(int Clerk_Id) {
	string Clerk_Name;
	string Clerk_Sex;
	int Clerk_age;
	string AdministrationStaff_PoliticalStatus;
	string AdministrationStaff_JobTitle;
	string Teacher_Departments;
	string Teacher_Profession;
	string Teacher_JobTitle;
	for (int i = 0; i < TAASList.size(); i++) {
		if (TAASList[i].GetClerk_Id() == Clerk_Id) {
			TAASList[i].ShowTAAS();
			cout << "教师兼行政人员员姓名为" << endl;
			cin >> Clerk_Name;
			cout << "教师兼行政人员性别为" << endl;
			cin >> Clerk_Sex;
			cout << "教师兼行政人员年龄为" << endl;
			cin >> Clerk_age;
			cout << "教师兼行政人员政治面貌为" << endl;
			cin >> AdministrationStaff_PoliticalStatus;
			cout << "教师兼行政人员的行政人员职称为" << endl;
			cin >> AdministrationStaff_JobTitle;
			cout << "教师兼行政人员所在系部为" << endl;
			cin >> Teacher_Departments;
			cout << "教师兼行政人员专业为" << endl;
			cin >> Teacher_Profession;
			cout << "教师兼行政人员的教师职称为" << endl;
			cin >> Teacher_JobTitle;
			TAASList[i] = TAAS(Clerk_Id, Clerk_Name, Clerk_Sex, Clerk_age, AdministrationStaff_PoliticalStatus, AdministrationStaff_JobTitle, Teacher_Departments, Teacher_Profession, Teacher_JobTitle);
		}
	}

	string i_update_TAAS = "UPDATE experimenter SET Clerk_Name=' ";
	i_update_TAAS.append(Clerk_Name);
	i_update_TAAS.append("',Clerk_Sex='");
	i_update_TAAS.append(Clerk_Sex);
	i_update_TAAS.append("',Clerk_age=");
	i_update_TAAS.append(to_string(Clerk_age));
	i_update_TAAS.append(",AdministrationStaff_PoliticalStatus='");
	i_update_TAAS.append(AdministrationStaff_PoliticalStatus);
	i_update_TAAS.append("',AdministrationStaff_JobTitle='");
	i_update_TAAS.append(AdministrationStaff_JobTitle);
	i_update_TAAS.append("',Teacher_Departments='");
	i_update_TAAS.append(Teacher_Departments);
	i_update_TAAS.append("',Teacher_Profession='");
	i_update_TAAS.append(Teacher_Profession);
	i_update_TAAS.append("',Teacher_JobTitle='");
	i_update_TAAS.append(Teacher_JobTitle);
	i_update_TAAS.append("' WHERE Clerk_Id=");
	i_update_TAAS.append(to_string(Clerk_Id));
	cout << i_update_TAAS << endl;
	mysql_query(&mysql, data(i_update_TAAS));
}
void update() {
	int Clerk_Id;
	cout << "请输入你要修改的员工ID" << endl;
	cin >> Clerk_Id;
	if (!hasIdRepeatTAAS(Clerk_Id)) {
		updateTAAS(Clerk_Id);
	}
	else if (!hasIdRepeatAdministrationStaff(Clerk_Id)) {
		updateAdministrationStaff(Clerk_Id);
	}
	else if (!hasIdRepeatExperimenter(Clerk_Id)) {
		updateExperimenter(Clerk_Id);
	}
	else if (!hasIdRepeatTeacher(Clerk_Id)) {
		updateTeacher(Clerk_Id);
	}
	else
		cout << "该ID不存在" << endl;
}
void mainWindow() {
	cout << "请输入您需要的功能" << endl;
	cout << "1.增加员工信息" << endl;
	cout << "2.查找员工信息" << endl;
	cout << "3.浏览全部员工信息" << endl;
	cout << "4.编辑员工信息" << endl;
	cout << "5.删除员工信息" << endl;
	cout << "6.统计员工信息" << endl;
	cout << "0.退出" << endl;
	string InData;
	int TempClerk_ID;
	string TempClerk_Name;
	int man=0;
	int woman=0;
	cin >> InData;
	while (InData != "0") {
		if (InData == "1") {
			cout << "1.增加教师信息" << endl;
			cout << "2.增加实验员信息" << endl;
			cout << "3.增加行政人员信息" << endl;
			cout << "4.增加教师兼行政人员信息" << endl;
			cin >> InData;
			if (InData == "1") {
				addTeacher();
			}
			else if (InData == "2") {
				addExperimenter();
			}
			else if (InData == "3") {
				addAdministrationStaff();
			}
			else if (InData == "4") {
				addTAAS();
			}
		}
		else if (InData == "2") {
			cout << "1.按照ID查找" << endl;
			cout << "2.按照姓名查找" << endl;
			cin >> InData;
			if (InData == "1") {
				cout << "请输入你要查找的员工ID" << endl;
				cin >> TempClerk_ID;
				serchAllId(TempClerk_ID);
			}
			else if (InData == "2") {
				cout << "请输入你要查找的员工姓名" << endl;
				cin >> TempClerk_Name;
				serchAllName(TempClerk_Name);
			}
		}
		else if (InData == "3") {
			showAll();
		}
		else if (InData == "4") {
			update();
		}
		else if (InData == "5") {
			cout << "1.按照ID删除" << endl;
			cout << "2.按照姓名删除" << endl;
			cin >> InData;
			if (InData == "1") {
				cout << "请输入你要删除的员工ID" << endl;
				cin >> TempClerk_ID;
				deleteId(TempClerk_ID);
			}
			else if (InData == "2") {
				cout << "请输入你要删除的员工姓名" << endl;
				cin >> TempClerk_Name;
				deleteName(TempClerk_Name);
			}
		}
		else if (InData == "6") {
			cout << "目前总计有员工" << ExperimenterList.size() + AdministrationStaffList.size() + TAASList.size() + TeacherList.size() << endl;
			for (int i = 0; i < TAASList.size(); i++) {
				if (TAASList[i].GetClerk_Sex() == "男") {
					man++;
				}
				else if (TAASList[i].GetClerk_Sex() == "女") {
					woman++;
				}
			}
			for (int i = 0; i < ExperimenterList.size(); i++) {
				if (ExperimenterList[i].GetClerk_Sex() == "男") {
					man++;
				}
				else if (ExperimenterList[i].GetClerk_Sex() == "女") {
					woman++;
				}
			}
			for (int i = 0; i < AdministrationStaffList.size(); i++) {
				if (AdministrationStaffList[i].GetClerk_Sex() == "男") {
					man++;
				}
				else if (AdministrationStaffList[i].GetClerk_Sex() == "女") {
					woman++;
				}
			}
			for (int i = 0; i < TeacherList.size(); i++) {
				if (TeacherList[i].GetClerk_Sex() == "男") {
					man++;
				}
				else if (TeacherList[i].GetClerk_Sex() == "女") {
					woman++;
				}
			}
			cout << "总计有男员工" << man << "名，总计有女员工" << woman << "名" << endl;
			man = 0;
			woman = 0;
		}
		else
			cout << "错误" << endl;
		cout << "请输入您需要的功能" << endl;
		cout << "1.增加员工信息" << endl;
		cout << "2.查找员工信息" << endl;
		cout << "3.浏览全部员工信息" << endl;
		cout << "4.编辑员工信息" << endl;
		cout << "5.删除员工信息" << endl;
		cout << "6.统计员工信息" << endl;
		cout << "0.退出" << endl;
		cin >> InData;
	}
}
int main()
{
	start();
	mainWindow();
	mysql_close(sock); //关闭连接 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
