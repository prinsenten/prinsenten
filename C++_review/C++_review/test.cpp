#include<iostream>
#include<string>
using namespace std;

//void mySwap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	mySwap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}


//
//class Animal
//{
//public:
//	virtual	void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//void dospeak(Animal & animal)
//{
//	animal.speak();
//}
//
//class Cat : public Animal
//{
//public:
//	void speak()
//	{
//		cout << "猫在说话" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "狗在说话" << endl;
//	}
//};
//
//int main()
//{
//	Animal animal;
//	dospeak(animal);
//	Dog dog;
//	dospeak(dog);
//	Cat cat;
//	dospeak(cat);
//	return 0;
//}

#include<fstream>
//int main()
//{
//	char data[100];
//	ofstream ofs;
//	ofs.open("test.txt", ios::out);
//	cin.getline(data,100);
//	ofs << data<<endl;
//	ofs.close();
//	return 0;
//}

//int main()
//{
//	const char* str = "hello world";
//	string s2(str);
//	cout << s2 << endl;
//
//	string s3(10, 'a');
//	cout << s3 << endl;
//	string s4 = "abcdef";
//	//s4.replace(1, 3, "1111");
//	s4.insert(1, "1111");
//	s4.erase(1, 3);
//	cout << s4 << endl;
//	string s5 = "nanjin@qq.com";
//	int pos=s5.find("@");
//	cout << pos << endl;
//	string name = s5.substr(0, pos);
//	cout << name << endl;
//	return 0;
//}

#include<vector>
#include<deque>
#include<algorithm>
//class Person
//{
//public:
//	Person(string name, int score)
//	{
//		this->my_name = name;
//		this->my_score = score;
//	}
//	string my_name;
//	int my_score;
//};
//
//void creat(vector<Person>& v)
//{
//	string nameseed = "ABCDE";
//	int n = 5;
//	while (n--)
//	{
//		string name = "选手";
//		name += nameseed[n];
//		Person p(name, 0);
//
//		v.push_back(p);
//	}
//}
//void show(vector<Person>& v)
//{
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "选手名： " << (*it).my_name << " 得分： " << it->my_score << endl;
//	}
//}
//void creatscore(vector<Person>& v)
//{
//	deque<int>d;
//	int i = 0;
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		int n = 10;
//		while (n--)
//		{
//			i = rand() % 40 + 60;
//			cout << i <<"  ";
//			d.push_back(i);
//		}
//		d.pop_back();
//		d.pop_front();
//		int sum = 0;
//		for (auto dit = d.begin(); dit != d.end(); dit++)
//		{
//			sum += *dit;
//		}
//		cout << "总分：" << sum<<endl;
//		int score = sum / (d.size());
//		it->my_score = score;
//	}
//}
//int main()
//{
//	vector<Person> v;
//	creat(v);
//	creatscore(v);
//	show(v);
//	return 0;
//}
#include<map>
//
//class Mycompare
//{
//public:
//	bool operator()(int a, int b) const
//	{
//		return a > b;
//	}
//};
//
//int main()
//{
//	map<int, int,Mycompare>m;
//
//	m.insert(make_pair(1, 10));
//	m.insert(make_pair(3, 20));
//	m.insert(make_pair(2, 5));
//	m.insert(make_pair(4, 40));
//
//	for (auto it = m.begin(); it != m.end(); it++)
//	{
//		cout << it->first <<" " << it->second << endl;
//	}
//	return 0;
//}
//int main()
//{
//	vector<int>v1;
//	vector<int>v2;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//	v2.assign(v1.begin(), v1.begin() + 3);
//	v1.assign(10, 5);
//	for (auto it = v1.begin(); it != v1.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	for (auto it = v2.begin(); it != v2.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	return 0;
//}
#include"Speaker.h"
#include"SpeakerManger.h"

int main()
{
	SpeakerManger sm;
	int input = 0;
	do 
	{
		sm.menu();
		cin >> input;
		switch (input)
		{
		case 1:
			sm.Start();
			break;
		case 2:
			sm.loadRe();
			break;
		case 3:
			//sm.clearRe();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "输入非法" << endl;
			break;
		}


	} while (input);

	return 0;
}













