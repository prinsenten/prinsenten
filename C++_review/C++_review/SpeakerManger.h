#pragma once
#include"Speaker.h"
#include<vector>
#include<map>
#include<functional>
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
class SpeakerManger
{
public:
	SpeakerManger();

	void menu();

	//12��
	vector<int>v1;

	//6��
	vector<int>v2;

	//3��ʤ��
	vector<int>v3;

	//��Ա��Ϣ
	map<int, Speaker>m_Speaker;
	//��������
	int Index = 1;

	void Init();

	void Creatper();

	void Draw();

	void Start();

	void ShowScore();

	void Contast();

	//�����¼
	void saveRe();

	//��ȡ��¼
	void loadRe();

	//�ļ�Ϊ�ձ�־
	bool fileIsEmpty;

	//�����¼
	map<int, vector<string>>m_Record;

	//��ʾ�������
	void showRe();

	//��ռ�¼
	void clearRe();
	

	~SpeakerManger();
};