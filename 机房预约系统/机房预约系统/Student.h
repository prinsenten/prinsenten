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

	//��д�˵�
	virtual void operMenu();

	//��������
	vector<ComputerRoom> vCom;

	//��ȡ��������
	void getComputer();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;
};

