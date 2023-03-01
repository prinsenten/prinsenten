#include"Manager.h"
#include<fstream>
Manager::Manager()
{

}
//获取机房数据
void Manager::getComputer()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}

	ifs.close();
}

Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();

	this->getComputer();
}

//获取学生和老师的信息
void Manager::initVector()
{
	//读取学生文件信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs>>s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量" << vTea.size() << endl;
	ifs.close();
}
//检查重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (auto it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
				return true;
		}
	}
	else
	{
		for (auto it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EpId)
				return true;
		}
	}
	return false;
}
void Manager::operMenu()
{
	cout << "欢迎管理员" << this->m_Name << "登录" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.添加账号             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.查看账号             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             3.查看机房             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             4.清空预约             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.注销登录             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "请输入您的选择:" << endl;
}

//添加账号
void Manager:: addPerson()
{
	cout << "请选择添加账号的类型" << endl;
	cout << "1.添加学生账号" << endl;
	cout << "2.添加教师账号" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	string errorTip;//重复提示
	cin >> select;
	switch (select)
	{
	case 1:
		fileName = STUDENT_FILE;
		tip = "请输入学号:";
		errorTip = "学号重复，请重新输入";
		break;
	case 2:
		fileName = TEACHER_FILE;
		tip = "请输入职工号:";
		errorTip = "职工号重复，请重新输入";
		break;
	default:
		cout << "输入非法" << endl;
		break;
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	while (1)
	{
		cout << tip << endl;
		cin >> id;

		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
			break;
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;


	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
	ofs.close();

	//添加完一个人后重置容器，防止未更新重复
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "学号：" << t.m_EpId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
//查看账号
void Manager:: showPerson()
{
	cout << "请选择查看的内容:" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有教师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "学生信息如下:" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下:" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");

}

//查看机房信息
void Manager:: showComputer()
{
	cout << "机房信息如下:" << endl;
	for (auto it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << " 机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");

}

//清空预约记录
void Manager:: cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}