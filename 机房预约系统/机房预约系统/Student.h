#pragma once
#include"Identity.h"
using namespace std;
#include<string>
#include"computerRoom.h"
#include<vector>
#include"orderFile.h"

class Student :public Identity 
{
public:
	Student();

	Student(int id, string name, string pwd);

	//重写菜单
	virtual void operMenu();

	//机房容器
	vector<ComputerRoom> vCom;

	//获取机房数据
	void getComputer();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_Id;
};

