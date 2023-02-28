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

	//12人
	vector<int>v1;

	//6人
	vector<int>v2;

	//3人胜者
	vector<int>v3;

	//人员信息
	map<int, Speaker>m_Speaker;
	//比赛次数
	int Index = 1;

	void Init();

	void Creatper();

	void Draw();

	void Start();

	void ShowScore();

	void Contast();

	//保存记录
	void saveRe();

	//读取记录
	void loadRe();

	//文件为空标志
	bool fileIsEmpty;

	//往届记录
	map<int, vector<string>>m_Record;

	//显示往届分数
	void showRe();

	//清空记录
	void clearRe();
	

	~SpeakerManger();
};