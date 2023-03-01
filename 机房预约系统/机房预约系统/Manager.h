#pragma once
#include"Identity.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include<algorithm>
#include"computerRoom.h"

class Manager :public Identity
{
public:
	Manager();

	Manager(string name,string pwd);

	virtual void operMenu();

	//添加账号
	void addPerson();

	//初始化容器  
	void initVector();

	//学生容器
	vector<Student> vStu;

	//老师容器
	vector<Teacher> vTea;

	//检查重复 (传入id，传入类型) 返回true或false
	bool checkRepeat(int id, int type);

	//机房容量
	vector<ComputerRoom> vCom;

	//获取机房数据
	void getComputer();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();
	

	//清空预约记录
	void cleanFile();

};