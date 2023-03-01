#include"Manager.h"
#include<fstream>
Manager::Manager()
{

}
//��ȡ��������
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
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();

	this->getComputer();
}

//��ȡѧ������ʦ����Ϣ
void Manager::initVector()
{
	//��ȡѧ���ļ���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs>>s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����" << vTea.size() << endl;
	ifs.close();
}
//����ظ�
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
	cout << "��ӭ����Ա" << this->m_Name << "��¼" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.����˺�             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.�鿴�˺�             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             3.�鿴����             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             4.���ԤԼ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.ע����¼             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "����������ѡ��:" << endl;
}

//����˺�
void Manager:: addPerson()
{
	cout << "��ѡ������˺ŵ�����" << endl;
	cout << "1.���ѧ���˺�" << endl;
	cout << "2.��ӽ�ʦ�˺�" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	string errorTip;//�ظ���ʾ
	cin >> select;
	switch (select)
	{
	case 1:
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
		errorTip = "ѧ���ظ�������������";
		break;
	case 2:
		fileName = TEACHER_FILE;
		tip = "������ְ����:";
		errorTip = "ְ�����ظ�������������";
		break;
	default:
		cout << "����Ƿ�" << endl;
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
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;


	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
	ofs.close();

	//�����һ���˺�������������ֹδ�����ظ�
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ѧ�ţ�" << t.m_EpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}
//�鿴�˺�
void Manager:: showPerson()
{
	cout << "��ѡ��鿴������:" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴���н�ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "ѧ����Ϣ����:" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ����:" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");

}

//�鿴������Ϣ
void Manager:: showComputer()
{
	cout << "������Ϣ����:" << endl;
	for (auto it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << " �������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");

}

//���ԤԼ��¼
void Manager:: cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}