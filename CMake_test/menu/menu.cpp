#include "menu.h"
#include<iostream>
#include<iomanip>

using namespace std;
int choice1(int& flag)
{
	system("cls");
	cout << endl;
	cout << setw(20) << "" << setw(17) << "ѧ������ϵͳ" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "�༭��Ϣ  ���밴1��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "��������  ���밴2��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "��ʾ��Ϣ  ���밴3��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "�˳�      ���밴4��" << "|" << '\n' << endl;
	while (true)
	{
		cin >> flag;
		if ((!cin >> flag) || flag == 0 || flag > 4)
		{
			cin.clear();
			cin.ignore();
			cout << "������������������" << endl;
		}
		else break;
	}
	return flag;
}

int choice2_1(int& flag)
{
	system("cls");
	cout << endl;
	cout << setw(20) << "" << setw(17) << "ѧ������ϵͳ" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "����ѧ����Ϣ  ���밴1��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "�޸�ѧ����Ϣ  ���밴2��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "ɾ��ѧ����Ϣ  ���밴3��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "�������˵�    ���밴4��" << "|" << '\n' << endl;
	cout << " ������ѡ��" << endl;
	while (true)
	{
		cin >> flag;
		if ((!cin >> flag) || flag == 0 || flag > 4)
		{
			cin.clear();
			cin.ignore();
			cout << "������������������" << endl;

		}
		else break;
	}
	return flag;
}

int choice2_2(int& flag)
{
	system("cls");
	cout << endl;
	cout << setw(20) << "" << setw(17) << "ѧ������ϵͳ" << '\n' << endl;
	cout << setw(20) << "" << "   ��ѡ���������ݣ�" << endl;
	cout << setw(20) << "" << "|" << setw(20) << "����������������  ���밴1��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "����ѧ�Ž�������  ���밴2��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "���������������  ���밴3��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "�������ĳɼ�����  ���밴4��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "������ѧ�ɼ�����  ���밴5��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "����Ӣ��ɼ�����  ���밴6��" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "�������˵�        ���밴7��" << "|" << '\n' << endl;

	while (true)
	{
		cin >> flag;
		if ((!cin >> flag) || flag == 0 || flag > 7)
		{
			cin.clear();
			cin.ignore();
			cout << "������������������" << endl;

		}
		else break;
	}
	return flag;
}





