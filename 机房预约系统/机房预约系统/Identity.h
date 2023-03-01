#pragma once
#include<iostream>
#include"globalFile.h"
using namespace std;

//身份抽象基类
class Identity
{
public:
	//操作菜单
	virtual void operMenu() = 0; //多态，子类中都有菜单，重写不一样的菜单

	string m_Name;
	string m_Pwd;//密码
};