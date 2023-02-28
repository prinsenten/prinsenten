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
	cout << "*****   欢迎参加演讲比赛   *****" << endl;
	cout << "*****   1.开始演讲比赛     *****" << endl;
	cout << "*****   2.查看往届记录     *****" << endl;
	cout << "*****   3.清空比赛记录     *****" << endl;
	cout << "*****   0.退出比赛程序     *****" << endl;
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
		string name = "选手";
		name += nameseed[i];

		Speaker s;
		s.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			s.m_Score[j] = 0;
		}
		//编号放入v1
		this->v1.push_back(i + 10001);
		//信息存入map
		this->m_Speaker.insert(make_pair(i+10001, s));
	}
}

void SpeakerManger::Draw()
{
	cout << "第" << this->Index << "轮比赛正在抽签" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "抽签结果如下：" << endl;
	if (this->Index==1)
	{
		int count = 0;
		random_shuffle(v1.begin(), v1.end());
		cout << "第一组:  ";
		for (auto it = v1.begin(); it != v1.end(); it++, count++)
		{
			cout << *it << " ";
			if (count == 5)
			{
				cout << endl;
				cout << "第二组： ";
			}
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		cout << "决胜组:   ";
		for (auto it = v2.begin(); it != v2.end(); it++)
		{

			cout<< *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------" << endl;;
	cout << "抽签结束即将开始比赛" << endl;
	system("pause");
}

void SpeakerManger::Contast()
{
	cout << "第" << this->Index << "轮比赛正式开始" << endl;
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
			cout << "第" << num / 6 << "组比赛结果如下" << endl;
			for (auto it = group.begin(); it != group.end(); it++)
			{
				cout << "选手编号：" << it->second <<" 选手姓名:"<<this->m_Speaker[it->second].m_Name
					<< " 选手得分：" <<this->m_Speaker[it->second].m_Score[this->Index-1]<<endl;
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
	cout << "第" << this->Index << "轮比赛完毕" << endl;
	system("pause");
}
void SpeakerManger::ShowScore()
{
	cout << "第" << this->Index << "轮比赛结果如下" << endl;
	vector<int>v;
	if (this->Index == 1)
		v = v2;
	else
		v = v3;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout<<"编号：" << *it<< "姓名：" << this->m_Speaker[*it].m_Name 
			<< " 得分：" << this->m_Speaker[*it].m_Score[this->Index-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}
void SpeakerManger::Start()
{
	this->Draw();//抽签
	this->Contast();//比赛
	this->ShowScore();//显示分数
	this->Index++;//下一场

	this->Draw();
	this->Contast();
	this->ShowScore();
	
	this->saveRe();//保存胜者信息
	this->Init();
	this->Creatper();
	this->loadRe();
	cout << "本届比赛完毕" << endl;
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
	cout << "保存成功" << endl;
	this->fileIsEmpty = false;
}
void SpeakerManger::loadRe()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
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
		cout << "文件为空" << endl;
	else
	{
		for (int i = 0; i < m_Record.size(); i++)
		{
			cout << "第" << i << "届比赛" << endl;
			cout<<"冠军编号："<<m_Record[i][0]<<"得分: "<<m_Record[i][1]<<" "
				"亚军编号：" << this->m_Record[i][2] << "得分：" << this->m_Record[i][3] << " "
				"季军编号：" << this->m_Record[i][4] << "得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}
void SpeakerManger::clearRe()
{
	cout << "确认清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在 删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->Init();

		//创建选手
		this->Creatper();

		//获取往届记录
		this->loadRe();

		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");

}
SpeakerManger::~SpeakerManger()
{

}