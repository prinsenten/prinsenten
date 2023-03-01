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

	//����˺�
	void addPerson();

	//��ʼ������  
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//����ظ� (����id����������) ����true��false
	bool checkRepeat(int id, int type);

	//��������
	vector<ComputerRoom> vCom;

	//��ȡ��������
	void getComputer();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();
	

	//���ԤԼ��¼
	void cleanFile();

};