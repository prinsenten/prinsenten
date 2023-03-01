#include"Student.h"
#include<fstream>

Student::Student()
{

}
//获取机房数据
void Student::getComputer()
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
Student::Student(int id, string name, string pwd)
{
	//初始化
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->getComputer();
}

//菜单
void Student:: operMenu()
{
	cout << "欢迎学生" << this->m_Name << "登录" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.申请预约             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.查看我的预约         |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             3.查看所有预约         |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             4.取消预约             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.注销登录             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "请输入您的选择:" << endl;
}

//申请预约
void Student:: applyOrder()
{
	cout << "机房开放时间为周一至周五" << endl;
	cout << "请输入申请预约时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date = 0;//日期
	int interval = 0;//时间段
	int roomId = 0;//机房编号
	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，重新输入" << endl;
	}

	cout << "请选择预约时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (1)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "号机房容量为:" << vCom[i].m_MaxNum << endl;
	}

	while (1)

	{
		cin >> roomId;
		if (roomId >= 1 && roomId <= 3)
		{
			break;
		}
		cout << "输入有误，重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << roomId << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//查看我的预约
void Student:: showMyOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		//.c_str是先转成c语言风格->const char*  atoi是转换为int类型 否则无法比较
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "预约日期:周" << of.m_orderDate[i]["date"];
			cout << " 时段:" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房:" << of.m_orderDate[i]["roomId"];
			string status = " 状态：";
			if (of.m_orderDate[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderDate[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderDate[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}
//查看所有预约
void Student:: showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";

		cout << "预约日期:周" << of.m_orderDate[i]["date"];
		cout << " 时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.m_orderDate[i]["stuId"];
		cout << " 姓名：" << of.m_orderDate[i]["stuName"];
		cout << " 机房：" << of.m_orderDate[i]["roomId"];
		string status = " 状态：";
		if (of.m_orderDate[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderDate[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderDate[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//取消预约
void Student:: cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_orderDate[i]["status"] == "1" || of.m_orderDate[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";

				cout << "预约日期:周" << of.m_orderDate[i]["date"];
				cout << " 时段:" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房:" << of.m_orderDate[i]["roomId"];
				string status = " 状态：";
				if (of.m_orderDate[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderDate[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
	while (1)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderDate[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}




