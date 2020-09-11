#include <string.h>
#pragma warning(disable:4996)
#include "student.h"
#include<string>

using namespace std;

int student::Count = 0;
void student::insert_stu()
{
	int insertPos;
	cout << "请输入你要插入的位置：" << endl;
	while (true)
	{
		cin >> insertPos;
		if (!cin >> insertPos)
		{
			cin.clear();
			cin.ignore();
			cout << "输入有误，请重新输入" << endl;

		}
		else break;
	}
	student_data* p = Head;
	student_data* q = new  student_data(insertPos);
	Count++;
	if (Count == 1)
	{
		Head->Next_stu = q;
	}
	else
	{
		int i = 0;
		student_data* h = new student_data;
		while (i < insertPos && p->Next_stu != NULL)
		{
			h = p;
			p = p->Next_stu;
			i++;
		}
		q->Next_stu = p;
		h->Next_stu = q;
		return;
	}
	cout << "插入学生的信息如下：" << endl;
	show_stu(insertPos);
	system("pause");
}
void student::show_stu(int pos)
{
	student_data* now = new student_data;
	student_data* p = Head;
	int i = 0;
	while (i < pos && p->Next_stu != NULL)
	{
		p = p->Next_stu;
		i++;
	}
	if (p->_name != "NULL")
	{
		cout << "姓名" << "           学号" << "       性别" << "    年龄" << "       班级" << "          健康状况" << endl;
		cout << left << setw(15) << setfill(' ') << p->_name;
		cout << left << setw(12) << setfill(' ') << p->_stuID;
		cout << left << setw(8) << setfill(' ') << p->_gender;
		cout << left << setw(10) << setfill(' ') << p->_age;
		cout << left << setw(10) << setfill(' ') << p->_GChin;
		cout << left << setw(10) << setfill(' ') << p->_Gmath;
		cout << left << setw(10) << setfill(' ') << p->_GEng << endl;
	}
	system("pause");
}
void student::show_allstu()
{
	student_data* p;
	p = Head;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "  姓名" << "           学号" << "      性别" << "         年龄" << "          语文成绩" << "         数学成绩" << "        英语成绩" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	for (int i = 1; i <= Count; i++)
	{
		p = p->Next_stu;
		cout << left << setw(10) << setfill(' ') << p->_name << left << setw(6) << setfill(' ') << "|";
		cout << left << setw(6) << setfill(' ') << p->_stuID << left << setw(6) << setfill(' ') << "|";
		cout << left << setw(8) << setfill(' ') << p->_gender << left << setw(6) << setfill(' ') << "|";
		cout << left << setw(10) << setfill(' ') << p->_age << left << setw(6) << setfill(' ') << "|";
		cout << left << setw(10) << setfill(' ') << p->_GChin << left << setw(6) << setfill(' ') << "|";
		cout << left << setw(10) << setfill(' ') << p->_Gmath << left << setw(6) << setfill(' ') << "|";
		cout << left << setw(10) << setfill(' ') << p->_GEng << left << setw(6) << setfill(' ') << "|" << endl;
		cout << "----------------------------------------------------------------------------------------------------" << endl;
	}
	cout << left << setw(10) << setfill(' ') << " 平均分："
		<< setw(47) << " "
		<< left << setw(16) << setfill(' ') << fixed << setprecision(2) << aver_Chin()
		<< left << setw(16) << setfill(' ') << fixed << setprecision(2) << aver_math()
		<< left << setw(16) << setfill(' ') << fixed << setprecision(2) << aver_Eng() << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << '\n' << "男生总共有" << man_count() << "人, " << "女生总共有" << (Count - man_count()) << "人" << '\n' << endl;
	system("pause");
}
void student::delete_stu()
{
	char flag_char;
	int deletePos;
	cout << "请输入你想删除的学生所处的位置：";
	while (true)
	{
		cin >> deletePos;
		if (!cin >> deletePos)
		{
			cin.clear();
			cin.ignore();
			cout << "输入有误，请重新输入" << endl;

		}
		else break;
	}
	student_data* p = Head;
	//显示学生信息确定是否要删除
	show_stu(deletePos);
	while (true)
	{
		cout << "你确定要删除该学生？(Y确认N取消)" << endl;
		cin >> flag_char;
		if (flag_char == 'Y' || flag_char == 'y')
		{
			Count--;
			int i = 0;
			while (i < deletePos - 1 && p->Next_stu != NULL)
			{
				p = p->Next_stu;
				i++;
			}
			student_data* q = new student_data;
			q = p->Next_stu->Next_stu;
			p->Next_stu = q;
			cout << "你已经成功删除该学生！";
			break;
		}
		else if (flag_char == 'N' || flag_char == 'n')
		{
			cout << "你已经成功取消该操作！";
			break;
		}
		else
		{
			cout << "你的输入有误，请重新输入!";
		}
	}


	system("pause");
	return;
}
void student::modify_stu()
{
	int modifyPos;
	cout << "请输入您要修改的学生的位置：" << endl;
	while (true)
	{
		cin >> modifyPos;
		if ((!cin >> modifyPos) || modifyPos > Count)
		{
			cin.clear();
			cin.ignore();
			cout << "该学生不存在，请重新输入" << endl;
		}
		else break;
	}
	cout << "该学生原有的信息为：" << endl;
	show_stu(modifyPos);
	char name[20] = { 0 };
	cout << "请你输入想要修改的学生姓名：";
	cin >> name;
	student_data* now = new student_data;
	student_data* p = Head;
	int i = 0;
	while (i < modifyPos && p->Next_stu != NULL)
	{
		p = p->Next_stu;
		i++;
	}
	cout << "请你输入修改后的名字：";
	cin >> now->_name;
	cout << endl;
	if (now->_name != "NULL")
	{
		strcpy(p->_name, now->_name);
	}
	cout << "请你输入修改后的学号：";
	cin >> now->_stuID;
	cout << endl;
	if (now->_stuID != NULL)
	{
		p->_stuID = now->_stuID;
	}
	cout << "请你输入修改后的性别：";
	cin >> now->_gender;
	cout << endl;
	if (now->_gender != NULL)
	{
		p->_gender = now->_gender;
	}
	cout << "请你输入修改后的年龄：";
	cin >> now->_age;
	cout << endl;
	if (now->_age != NULL)
	{
		p->_age = now->_age;
	}
	cout << "请你输入修改后的语文课成绩：";
	cin >> now->_GChin;
	cout << endl;
	if (now->_GChin != NULL)
	{
		p->_GChin = now->_GChin;
	}
	cout << "请你输入修改后的数学课成绩：";
	cin >> now->_Gmath;
	cout << endl;
	if (now->_Gmath != NULL)
	{
		p->_Gmath = now->_Gmath;
	}
	cout << "请你输入修改后的英语课成绩：";
	cin >> now->_GEng;
	cout << endl;
	if (now->_GEng != NULL)
	{
		p->_GEng = now->_GEng;
	}
	cout << "修改后的学生情况如下：" << endl;
	show_stu(modifyPos);
	outfile_txt();
	delete now;
	system("pause");
}
void student::Add_Student(char* name, int student_id, char  gender, int age, int GChin, int Gmath, int GEng)
{
	student_data* p = Head;
	student_data* q = new  student_data(name, student_id, gender, age, GChin, Gmath, GEng);
	//创建一个节点并将它与链表连接
	Count++;
	for (int i = 1; i < Count; i++)
	{
		p = p->Next_stu;
	}
	p->Next_stu = q;
	return;
}
void student::rank_stuID()
{  //冒泡排序法对学号进行排序，主要是指针间的关系改动
	int j = 0;
	student_data* k;
	student_data* p;
	student_data* q;
	for (int i = 0; i < Count - 1; i++)
	{
		k = Head;
		p = Head->Next_stu;
		q = Head->Next_stu->Next_stu;
		for (j = 0; j < Count - 1 - i; j++)
		{
			if (p->_stuID > q->_stuID)
			{
				k->Next_stu = q;
				p->Next_stu = q->Next_stu;
				q->Next_stu = p;
				k = k->Next_stu;
				q = p->Next_stu;
			}
			else
			{
				k = k->Next_stu;
				p = p->Next_stu;
				q = q->Next_stu;
			}
		}
	}
}
void student::rank_age()
{  //冒泡排序法对学号进行排序，主要是指针间的关系改动
	int j = 0;
	student_data* k;
	student_data* p;
	student_data* q;
	for (int i = 0; i < Count - 1; i++)
	{
		k = Head;
		p = Head->Next_stu;
		q = Head->Next_stu->Next_stu;
		for (j = 0; j < Count - 1 - i; j++)
		{
			if (p->_age > q->_age)
			{
				k->Next_stu = q;
				p->Next_stu = q->Next_stu;
				q->Next_stu = p;
				k = k->Next_stu;
				q = p->Next_stu;
			}
			else
			{
				k = k->Next_stu;
				p = p->Next_stu;
				q = q->Next_stu;
			}
		}
	}
}
void student::rank_GChin()
{  //冒泡排序法对学号进行排序，主要是指针间的关系改动
	int j = 0;
	student_data* k;
	student_data* p;
	student_data* q;
	for (int i = 0; i < Count - 1; i++)
	{
		k = Head;
		p = Head->Next_stu;
		q = Head->Next_stu->Next_stu;
		for (j = 0; j < Count - 1 - i; j++)
		{
			if (p->_GChin > q->_GChin)
			{
				k->Next_stu = q;
				p->Next_stu = q->Next_stu;
				q->Next_stu = p;
				k = k->Next_stu;
				q = p->Next_stu;
			}
			else
			{
				k = k->Next_stu;
				p = p->Next_stu;
				q = q->Next_stu;
			}
		}
	}
}
void student::rank_Gmath()
{  //冒泡排序法对学号进行排序，主要是指针间的关系改动
	int j = 0;
	student_data* k;
	student_data* p;
	student_data* q;
	for (int i = 0; i < Count - 1; i++)
	{
		k = Head;
		p = Head->Next_stu;
		q = Head->Next_stu->Next_stu;
		for (j = 0; j < Count - 1 - i; j++)
		{
			if (p->_Gmath > q->_Gmath)
			{
				k->Next_stu = q;
				p->Next_stu = q->Next_stu;
				q->Next_stu = p;
				k = k->Next_stu;
				q = p->Next_stu;
			}
			else
			{
				k = k->Next_stu;
				p = p->Next_stu;
				q = q->Next_stu;
			}
		}
	}
}
void student::rank_GEng()
{  //冒泡排序法对学号进行排序，主要是指针间的关系改动
	int j = 0;
	student_data* k;
	student_data* p;
	student_data* q;
	for (int i = 0; i < Count - 1; i++)
	{
		k = Head;
		p = Head->Next_stu;
		q = Head->Next_stu->Next_stu;
		for (j = 0; j < Count - 1 - i; j++)
		{
			if (p->_GEng > q->_GEng)
			{
				k->Next_stu = q;
				p->Next_stu = q->Next_stu;
				q->Next_stu = p;
				k = k->Next_stu;
				q = p->Next_stu;
			}
			else
			{
				k = k->Next_stu;
				p = p->Next_stu;
				q = q->Next_stu;
			}
		}
	}
}
void student::rank_name()
{
	int j = 0;
	student_data* k;
	student_data* p;
	student_data* q;
	for (int i = 0; i < Count - 1; i++)
	{
		k = Head;
		p = Head->Next_stu;
		q = Head->Next_stu->Next_stu;
		for (j = 0; j < Count - 1 - i; j++)
		{
			int a = p->_name[0];
			int b = q->_name[0];
			if (a > b)
			{
				k->Next_stu = q;
				p->Next_stu = q->Next_stu;
				q->Next_stu = p;
				k = k->Next_stu;
				q = p->Next_stu;
			}
			else
			{
				k = k->Next_stu;
				p = p->Next_stu;
				q = q->Next_stu;
			}
		}
	}
}
void student::outfile_txt()  //保存所有学生信息到文件中
{
	ofstream outfile("D:\\student.txt");
	//保存到该文件目录下的文件，如果没有该文件，将会创建该文件，有的话，会清空原有文件中的所有内容
	student_data* p = Head;
	if (!outfile.is_open())  //如果文件创建失败，就返回不进行后续操作
	{
		cout << "文件创建失败！！！";
		return;
	}
	outfile << "姓名" << "           学号" << "       性别" << "    年龄" << "   语文成绩" << "   数学成绩" << "   英语成绩" << endl;
	for (int i = 1; i <= Count; i++)
	{ //利用左对齐，填充字符控制格式化的输出到文件
		p = p->Next_stu;
		outfile << left << setw(15) << setfill(' ') << p->_name;
		outfile << left << setw(12) << setfill(' ') << p->_stuID;
		outfile << left << setw(8) << setfill(' ') << p->_gender;
		outfile << left << setw(10) << setfill(' ') << p->_age;
		outfile << left << setw(10) << setfill(' ') << p->_GChin;
		outfile << left << setw(10) << setfill(' ') << p->_Gmath;
		outfile << left << setw(10) << setfill(' ') << p->_GEng << endl;
	}
	outfile.close(); //关闭该文件流
}
void student::infile_txt() //从文件中读取学生信息
{
	ifstream infile("D:\\student.txt");
	if (!infile.is_open())
	{
		cout << "文件打开失败！！！";
		return;
	}
	student_data* p = Head;
	char status[80];  //文件中的第一行默认显示一些信息，所以这一行信息应该被读取掉然后丢弃
	infile.getline(status, 100);  //读取100个字符到getline中
	char name[20];
	int stuID;
	char gender;
	int age;
	int _GChi;
	int _Gmath;
	int _GEng;
	while (infile.good())  //good()可以获取是否处于一种好的状态，达到文件尾部或者类型不匹配都会返回false
	{  //将文件中的信息添加到链表中
		infile >> name >> stuID >> gender >> age >> _GChi >> _Gmath >> _GEng;
		Add_Student(name, stuID, gender, age, _GChi, _Gmath, _GEng);
		cout << name << '\t' << stuID << '\t' << gender << '\t' << age << '\t' << _GChi << '\t' << _Gmath << '\t' << _GEng << endl;
	}
	infile.close();  //关闭文件流
	cout << "导入学生信息成功" << endl;
	system("pause");
}
int student::man_count()
{
	student_data* p = Head;
	int num = 0;
	for (int i = 0; i < Count; i++)
	{
		p = p->Next_stu;
		if (p->_gender == 'M' || p->_gender == 'm')num++;
	}
	return num;
}
double student::aver_Chin()
{
	student_data* p = Head;
	double score;
	double aver_score = 0;
	for (int i = 0; i < Count; i++)
	{
		p = p->Next_stu;
		score = p->_GChin;
		aver_score += score;
	}
	aver_score = double(aver_score / Count);
	return aver_score;
}
double student::aver_math()
{
	student_data* p = Head;
	double score;
	double aver_score = 0;
	for (int i = 0; i < Count; i++)
	{
		p = p->Next_stu;
		score = p->_Gmath;
		aver_score += score;
	}
	aver_score = double(aver_score / Count);
	return aver_score;
}
double student::aver_Eng()
{
	student_data* p = Head;
	double score;
	double aver_score = 0;
	for (int i = 0; i < Count; i++)
	{
		p = p->Next_stu;
		score = p->_GEng;
		aver_score += score;
	}
	aver_score = double(aver_score / Count);
	return aver_score;
}
