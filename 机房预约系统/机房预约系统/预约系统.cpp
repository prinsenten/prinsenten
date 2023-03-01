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
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ��תΪ����ָ��,���������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		switch (select)
		{
		case 1://����˺�
			cout << "����˺�" << endl;
			man->addPerson();
			break;
		case 2://�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
			break;
		case 3://�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
			break;
		case 4://���ԤԼ
			man->cleanFile();
			break;
		case 0:
			delete manager;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "����Ƿ�����������" << endl;
			break;
		}
	}
}
void studentMenu(Identity*& student)
{
	while (1)
	{
		//ѧ���˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select=0;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴�ҵ�ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
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

		if (select == 1)//�鿴����ԤԼ
			tea->showAllOrder();
		else if (select == 2)//���ԤԼ
			tea->validOrder();
		else
		{
			delete tea;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void Login(string fileName, int type)
{
	Identity* person=NULL;//�ȴ���һ������ָ��
	
	//���ļ�
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//���ھͽ�����Ϣ
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����:" << endl;
		cin >> id;
	}

	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;

	if (type == 1)//ѧ����¼
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);

				return ;
			}
		}
	}
	else if (type == 2)//��ʦ��¼
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//������ʦ�Ӳ˵�
				TeacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)//����Ա��¼
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�
				managerMenu(person);

				return;
			}
		}
	}
	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}


void menu()
{
	cout << "=====================================��ӭ��������ԤԼϵͳ==========================================" << endl;
	cout << endl << "��ѡ��������ݣ�" << endl;
	cout << "\t\t-------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.ѧ����¼             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.��    ʦ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             3.�� �� Ա             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.��    ��             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t-------------------------------------\n";
	cout << "����������ѡ��:" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			exit(0);
			system("pause");
			break;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (select);

	return 0;
}