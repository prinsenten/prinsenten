#pragma once
#include<iostream>
#include"globalFile.h"
using namespace std;

//��ݳ������
class Identity
{
public:
	//�����˵�
	virtual void operMenu() = 0; //��̬�������ж��в˵�����д��һ���Ĳ˵�

	string m_Name;
	string m_Pwd;//����
};