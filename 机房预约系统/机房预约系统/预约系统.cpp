#include<iostream>
using namespace std;
#include"Identity.h"
#include"globalFile.h"
#include<fstream>
#include<string>
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"



void managerMenu(Identity*& manager)
{
	while(1)
	{
		//调用管理员子菜单
		manager->operMenu();

		//将父类指针转为子类指针,调用子类里其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户选择
		cin >> select;

		switch (select)
		{
		case 1://添加账号
			cout << "添加账号" << endl;
			man->addPerson();
			break;
		case 2://查看账号
			cout << "查看账号" << endl;
			man->showPerson();
			break;
		case 3://查看机房
			cout << "查看机房" << endl;
			man->showComputer();
			break;
		case 4://清空预约
			man->cleanFile();
			break;
		case 0:
			delete manager;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入非法，重新输入" << endl;
			break;
		}
	}
}
void studentMenu(Identity*& student)
{
	while (1)
	{
		//学生菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select=0;
		cin >> select;

		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看我的预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void TeacherMenu(Identity*& teacher)
{
	while (1)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;

		if (select == 1)//查看所有预约
			tea->showAllOrder();
		else if (select == 2)//审核预约
			tea->validOrder();
		else
		{
			delete tea;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void Login(string fileName, int type)
{
	Identity* person=NULL;//先创建一个父类指针
	
	//读文件
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//存在就接受信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号:" << endl;
		cin >> id;
	}

	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;

	if (type == 1)//学生登录
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生子菜单
				studentMenu(person);

				return ;
			}
		}
	}
	else if (type == 2)//老师登录
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入老师子菜单
				TeacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)//管理员登录
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员子菜单
				managerMenu(person);

				return;
			}
		}
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
	return;
}


void menu()
{
	cout << "=====================================欢迎来到机房预约系统==========================================" << endl;
	cout << endl << "请选择您的身份：" << endl;
	cout << "\t\t-------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.学生登录             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.老    师             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             3.管 理 员             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.退    出             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t-------------------------------------\n";
	cout << "请输入您的选择:" << endl;
}
int main()
{
	int select = 0;
	do
	{
		menu();
		cin >> select;
		switch (select)
		{
		case 1:
			Login(STUDENT_FILE, 1);
			break;
		case 2:
			Login(TEACHER_FILE, 2);
			break;
		case 3:
			Login(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			exit(0);
			system("pause");
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (select);

	return 0;
}