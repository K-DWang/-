#include "stdafx.h"
#include"admin.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
typedef struct StudentInfo
{
	string studentID;
	string name;
	int cScore;
	int mathScore;
} SI;
using namespace std;
vector<SI> stuInfo;
bool compare(SI, SI);
using namespace std;

void media()
{
	cout<<"           学生成绩管理系统          "<<endl;
	cout<<"           1.添加学生信息            "<<endl;
    cout<<"           2.显示所有信息            "<<endl;
	cout<<"           3.修改学生信息            "<<endl;
	cout<<"           4.删除学生信息            "<<endl;
	cout<<"           5.查找学生信息            "<<endl;
	cout<<"           6.排序学生成绩            "<<endl;
	cout<<"           0.退出系统                "<<endl;
}

void addInfo()
{
	cout << "请输入学生的学号(5位)，姓名，c语言成绩，高数成绩，中间以空格隔开！" << endl;
	SI  tmp;
	cin >> tmp.studentID >> tmp.name >> tmp.cScore >> tmp.mathScore;
	int index = 0;
	for (; index < stuInfo.size(); index++)
		if (stuInfo[index].studentID == tmp.studentID)
			break;
	if (index < stuInfo.size())
		cout << "该学生信息已存在!\n" << endl;
	else
		stuInfo.push_back(tmp);
}

int search()
{
	if (stuInfo.size() == 0)
	{
		cout << "没有任何学生的信息\n";
		return 0;
	}
	cout << "请输入查找学生的姓名" << endl;
	string stmp;
	cin >> stmp;
	int index = 0;
	for (; index < stuInfo.size(); index++)
		if (stuInfo[index].name == stmp)
			break;
	if (index == stuInfo.size())
		cout << "抱歉，没有该学生！" << endl;
	else
		cout << stuInfo[index].studentID <<'\t'<< stuInfo[index].name << '\t' << stuInfo[index].cScore << '\t' << stuInfo[index].mathScore << endl;
	return index;
}

void modify()
{
	int index=search();
	if (index == stuInfo.size())
		return;
	cout << "1.修改c语言成绩" << endl;
	cout << "2.修改高数成绩" << endl;
	cout << "3.修改c语言成绩和高数成绩" << endl;
	int key;
	cin >> key;
	switch (key)
	{
	case 1:
		cin >> stuInfo[index].cScore;
		break;
	case 2:
		cin >> stuInfo[index].mathScore;
		break;
	case 3:
		cin >> stuInfo[index].cScore >> stuInfo[index].mathScore;
		break;
	}
	cout << "修改完成后的数据为：\n";
	cout << stuInfo[index].studentID << '\t' << stuInfo[index].name << '\t' << stuInfo[index].cScore << '\t' << stuInfo[index].mathScore << endl;
}

void del()
{
	int index = search();
	if (index == stuInfo.size())
		return;
	vector<SI>::iterator p = stuInfo.begin() + index;
	stuInfo.erase(p);
	cout << "数据删除完成：\n" << endl;
}

void showAll()
{
	if (stuInfo.size() == 0)
	{
		cout << "没有任何学生的信息\n";
		return;
	}

	cout << "一共有" << stuInfo.size() << "名学生:" << endl;
	for(int index=0;index<stuInfo.size();index++)
		cout << stuInfo[index].studentID << '\t' << stuInfo[index].name << '\t' << stuInfo[index].cScore << '\t' << stuInfo[index].mathScore << endl;
}

void sort()
{
	if (stuInfo.size() == 0)
	{
		cout << "没有任何学生的信息\n";
		return;
	}
	vector<SI> tmp = stuInfo;
	sort(tmp.begin(), tmp.end(), compare);
	cout << "更改后的数据按照成绩从高到低的排序为:\n";
	for (int index = 0; index<stuInfo.size(); index++)
		cout << tmp[index].studentID << '\t' << tmp[index].name << '\t' << tmp[index].cScore << '\t' << tmp[index].mathScore << endl;
}

bool compare(SI s1, SI s2)
{
	if (s1.cScore + s1.cScore != s2.cScore + s2.mathScore) return s1.cScore + s1.cScore > s2.cScore + s2.mathScore;
	return s1.name < s2.name;
}