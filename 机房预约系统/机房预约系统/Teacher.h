#pragma once
#include"Identity.h"
#include"Student.h"
class Teacher :public Identity
{
public:

	Teacher();

	Teacher(int emId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//չʾ����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EpId;

};