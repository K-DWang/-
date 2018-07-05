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
	cout<<"           ѧ���ɼ�����ϵͳ          "<<endl;
	cout<<"           1.���ѧ����Ϣ            "<<endl;
    cout<<"           2.��ʾ������Ϣ            "<<endl;
	cout<<"           3.�޸�ѧ����Ϣ            "<<endl;
	cout<<"           4.ɾ��ѧ����Ϣ            "<<endl;
	cout<<"           5.����ѧ����Ϣ            "<<endl;
	cout<<"           6.����ѧ���ɼ�            "<<endl;
	cout<<"           0.�˳�ϵͳ                "<<endl;
}

void addInfo()
{
	cout << "������ѧ����ѧ��(5λ)��������c���Գɼ��������ɼ����м��Կո������" << endl;
	SI  tmp;
	cin >> tmp.studentID >> tmp.name >> tmp.cScore >> tmp.mathScore;
	int index = 0;
	for (; index < stuInfo.size(); index++)
		if (stuInfo[index].studentID == tmp.studentID)
			break;
	if (index < stuInfo.size())
		cout << "��ѧ����Ϣ�Ѵ���!\n" << endl;
	else
		stuInfo.push_back(tmp);
}

int search()
{
	if (stuInfo.size() == 0)
	{
		cout << "û���κ�ѧ������Ϣ\n";
		return 0;
	}
	cout << "���������ѧ��������" << endl;
	string stmp;
	cin >> stmp;
	int index = 0;
	for (; index < stuInfo.size(); index++)
		if (stuInfo[index].name == stmp)
			break;
	if (index == stuInfo.size())
		cout << "��Ǹ��û�и�ѧ����" << endl;
	else
		cout << stuInfo[index].studentID <<'\t'<< stuInfo[index].name << '\t' << stuInfo[index].cScore << '\t' << stuInfo[index].mathScore << endl;
	return index;
}

void modify()
{
	int index=search();
	if (index == stuInfo.size())
		return;
	cout << "1.�޸�c���Գɼ�" << endl;
	cout << "2.�޸ĸ����ɼ�" << endl;
	cout << "3.�޸�c���Գɼ��͸����ɼ�" << endl;
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
	cout << "�޸���ɺ������Ϊ��\n";
	cout << stuInfo[index].studentID << '\t' << stuInfo[index].name << '\t' << stuInfo[index].cScore << '\t' << stuInfo[index].mathScore << endl;
}

void del()
{
	int index = search();
	if (index == stuInfo.size())
		return;
	vector<SI>::iterator p = stuInfo.begin() + index;
	stuInfo.erase(p);
	cout << "����ɾ����ɣ�\n" << endl;
}

void showAll()
{
	if (stuInfo.size() == 0)
	{
		cout << "û���κ�ѧ������Ϣ\n";
		return;
	}

	cout << "һ����" << stuInfo.size() << "��ѧ��:" << endl;
	for(int index=0;index<stuInfo.size();index++)
		cout << stuInfo[index].studentID << '\t' << stuInfo[index].name << '\t' << stuInfo[index].cScore << '\t' << stuInfo[index].mathScore << endl;
}

void sort()
{
	if (stuInfo.size() == 0)
	{
		cout << "û���κ�ѧ������Ϣ\n";
		return;
	}
	vector<SI> tmp = stuInfo;
	sort(tmp.begin(), tmp.end(), compare);
	cout << "���ĺ�����ݰ��ճɼ��Ӹߵ��͵�����Ϊ:\n";
	for (int index = 0; index<stuInfo.size(); index++)
		cout << tmp[index].studentID << '\t' << tmp[index].name << '\t' << tmp[index].cScore << '\t' << tmp[index].mathScore << endl;
}

bool compare(SI s1, SI s2)
{
	if (s1.cScore + s1.cScore != s2.cScore + s2.mathScore) return s1.cScore + s1.cScore > s2.cScore + s2.mathScore;
	return s1.name < s2.name;
}