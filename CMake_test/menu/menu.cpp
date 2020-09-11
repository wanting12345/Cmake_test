#include "menu.h"
#include<iostream>
#include<iomanip>

using namespace std;
int choice1(int& flag)
{
	system("cls");
	cout << endl;
	cout << setw(20) << "" << setw(17) << "学生管理系统" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "编辑信息  【请按1】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "重新排序  【请按2】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "显示信息  【请按3】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "退出      【请按4】" << "|" << '\n' << endl;
	while (true)
	{
		cin >> flag;
		if ((!cin >> flag) || flag == 0 || flag > 4)
		{
			cin.clear();
			cin.ignore();
			cout << "输入有误，请重新输入" << endl;
		}
		else break;
	}
	return flag;
}

int choice2_1(int& flag)
{
	system("cls");
	cout << endl;
	cout << setw(20) << "" << setw(17) << "学生管理系统" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "插入学生信息  【请按1】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "修改学生信息  【请按2】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "删除学生信息  【请按3】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "返回主菜单    【请按4】" << "|" << '\n' << endl;
	cout << " 请输入选择" << endl;
	while (true)
	{
		cin >> flag;
		if ((!cin >> flag) || flag == 0 || flag > 4)
		{
			cin.clear();
			cin.ignore();
			cout << "输入有误，请重新输入" << endl;

		}
		else break;
	}
	return flag;
}

int choice2_2(int& flag)
{
	system("cls");
	cout << endl;
	cout << setw(20) << "" << setw(17) << "学生管理系统" << '\n' << endl;
	cout << setw(20) << "" << "   请选择排序依据：" << endl;
	cout << setw(20) << "" << "|" << setw(20) << "按照姓名进行排序  【请按1】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "按照学号进行排序  【请按2】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "按照年龄进行排序  【请按3】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "按照语文成绩排序  【请按4】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "按照数学成绩排序  【请按5】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "按照英语成绩排序  【请按6】" << "|" << '\n' << endl;
	cout << setw(20) << "" << "|" << setw(20) << "返回主菜单        【请按7】" << "|" << '\n' << endl;

	while (true)
	{
		cin >> flag;
		if ((!cin >> flag) || flag == 0 || flag > 7)
		{
			cin.clear();
			cin.ignore();
			cout << "输入有误，请重新输入" << endl;

		}
		else break;
	}
	return flag;
}





