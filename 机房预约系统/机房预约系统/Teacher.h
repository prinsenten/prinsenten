#pragma once
#include"Identity.h"
#include"Student.h"
class Teacher :public Identity
{
public:

	Teacher();

	Teacher(int emId, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//展示所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	int m_EpId;

};