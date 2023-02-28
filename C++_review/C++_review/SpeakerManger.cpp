#include"SpeakerManger.h"

SpeakerManger::SpeakerManger()
{
	this->Init();
	this->Creatper();
	this->loadRe();
	//this->m_Record.clear();
}
void SpeakerManger::menu()
{
	cout << "********************************" << endl;
	cout << "*****   ��ӭ�μ��ݽ�����   *****" << endl;
	cout << "*****   1.��ʼ�ݽ�����     *****" << endl;
	cout << "*****   2.�鿴�����¼     *****" << endl;
	cout << "*****   3.��ձ�����¼     *****" << endl;
	cout << "*****   0.�˳���������     *****" << endl;
	cout << "********************************" << endl;
}

void SpeakerManger::Init()
{
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	this->Index = 1;
}

void SpeakerManger::Creatper()
{
	string nameseed = "ABCDEFGHIGKL";
	for (int i = 0; i < 12; i++)
	{
		string name = "ѡ��";
		name += nameseed[i];

		Speaker s;
		s.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			s.m_Score[j] = 0;
		}
		//��ŷ���v1
		this->v1.push_back(i + 10001);
		//��Ϣ����map
		this->m_Speaker.insert(make_pair(i+10001, s));
	}
}

void SpeakerManger::Draw()
{
	cout << "��" << this->Index << "�ֱ������ڳ�ǩ" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "��ǩ������£�" << endl;
	if (this->Index==1)
	{
		int count = 0;
		random_shuffle(v1.begin(), v1.end());
		cout << "��һ��:  ";
		for (auto it = v1.begin(); it != v1.end(); it++, count++)
		{
			cout << *it << " ";
			if (count == 5)
			{
				cout << endl;
				cout << "�ڶ��飺 ";
			}
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		cout << "��ʤ��:   ";
		for (auto it = v2.begin(); it != v2.end(); it++)
		{

			cout<< *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------" << endl;;
	cout << "��ǩ����������ʼ����" << endl;
	system("pause");
}

void SpeakerManger::Contast()
{
	cout << "��" << this->Index << "�ֱ�����ʽ��ʼ" << endl;
	multimap<double, int, greater<double>>group;
	int num = 0;

	vector<int>v_scr;
	if (this->Index == 1)
	{
		v_scr = v1;
	}
	else
	{
		v_scr=v2;
	}
	for (auto it = v_scr.begin(); it != v_scr.end(); it++)
	{
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = rand()%400+100 / 10.0f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(),0.0f);
		double avg = sum / d.size();

		this->m_Speaker[*it].m_Score[Index - 1] = avg;
		group.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "������������" << endl;
			for (auto it = group.begin(); it != group.end(); it++)
			{
				cout << "ѡ�ֱ�ţ�" << it->second <<" ѡ������:"<<this->m_Speaker[it->second].m_Name
					<< " ѡ�ֵ÷֣�" <<this->m_Speaker[it->second].m_Score[this->Index-1]<<endl;
			}
			int count = 0;
			for (auto it = group.begin(); it != group.end() && count < 3; it++, count++)
			{
				if (this->Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					v3.push_back(it->second);
				}
			}
			group.clear();
			cout << endl;
		}
	}
	cout << "��" << this->Index << "�ֱ������" << endl;
	system("pause");
}
void SpeakerManger::ShowScore()
{
	cout << "��" << this->Index << "�ֱ����������" << endl;
	vector<int>v;
	if (this->Index == 1)
		v = v2;
	else
		v = v3;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout<<"��ţ�" << *it<< "������" << this->m_Speaker[*it].m_Name 
			<< " �÷֣�" << this->m_Speaker[*it].m_Score[this->Index-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}
void SpeakerManger::Start()
{
	this->Draw();//��ǩ
	this->Contast();//����
	this->ShowScore();//��ʾ����
	this->Index++;//��һ��

	this->Draw();
	this->Contast();
	this->ShowScore();
	
	this->saveRe();//����ʤ����Ϣ
	this->Init();
	this->Creatper();
	this->loadRe();
	cout << "����������" << endl;
	system("pause");
	system("cls");
}
void SpeakerManger::saveRe()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << "," ;
	}
	ofs << endl;

	ofs.close();
	cout << "����ɹ�" << endl;
	this->fileIsEmpty = false;
}
void SpeakerManger::loadRe()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (1)
		{
			pos = data.find(",",start);
			if (pos == -1)
				break;
			string temp = data.substr(start, pos-start);

			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}
void SpeakerManger::showRe()
{
	if (this->fileIsEmpty == true)
		cout << "�ļ�Ϊ��" << endl;
	else
	{
		for (int i = 0; i < m_Record.size(); i++)
		{
			cout << "��" << i << "�����" << endl;
			cout<<"�ھ���ţ�"<<m_Record[i][0]<<"�÷�: "<<m_Record[i][1]<<" "
				"�Ǿ���ţ�" << this->m_Record[i][2] << "�÷֣�" << this->m_Record[i][3] << " "
				"������ţ�" << this->m_Record[i][4] << "�÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}
void SpeakerManger::clearRe()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc ������� ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->Init();

		//����ѡ��
		this->Creatper();

		//��ȡ�����¼
		this->loadRe();

		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");

}
SpeakerManger::~SpeakerManger()
{

}