#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include <cstdlib>
#include<fstream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
struct student_data  //定义一个节点结构，表示每个学生的信息
{
	char* _name;  //姓名
	int _stuID; //学号
	char _gender; //性别
	int _age; //年龄
	int _GChin;//语文成绩
	int _Gmath;//数学成绩
	int _GEng;//英语成绩
	student_data* Next_stu;//指向下一個節點的指針

	
	student_data()  //默认构造函数
	{
		_name = new char[20];
		_stuID = NULL;
		_gender = NULL;
		_age = NULL;
		_Gmath = NULL;
		_GChin = NULL;
		_GEng = NULL;
		Next_stu = NULL;
	}
	student_data(int pos) //根据在链表中的位置创建学生信息的构造函数（插入学生时用到）
	{
		_name = new char[20];
		cout << "请输入要插入的第" << pos << "位学生的姓名：";
		cin >> _name;
		cout << "请输入" << _name << "的学号：";
		cin >> _stuID;
		cout << "请输入" << _name << "的性别：";
		cin >> _gender;
		cout << "请输入" << _name << "的年龄：";
		cin >> _age;
		cout << "请输入" << _name << "的语文课成绩：";
		cin >> _GChin;
		cout << "请输入" << _name << "的数学课成绩：";
		cin >> _Gmath;
		cout << "请输入" << _name << "的英语课成绩：";
		cin >> _GEng;

	}
	//带参构造函数（读文件时用到）
	student_data(char* name, int stuID, char  gender, int age, int Gchi, int Gmath, int Geng)
	{
		_name = new char[20];
		strcpy(_name, name);
		_stuID = stuID;
		_gender = gender;
		_age = age;
		_GChin = Gchi;
		_Gmath = Gmath;
		_GEng = Geng;
		Next_stu = NULL;
	}
};
class student  //链表类
{

	static int Count;  //学生人数
	student_data* Head;	//头指针
public:
	student()
	{
		student_data* p = new student_data; //创建头结点并初始化该成员
		Head = p;
		Head->Next_stu = NULL;
	}
	~student()  //析构函数
	{
	}
	//添加学生信息，在通过文件导入学生信息时需要用到
	void Add_Student(char* name, int student_id, char  gender, int age, int GChi, int Gmath, int GEng);
	void insert_stu();//插入学生信息
	void modify_stu(); //修改学生信息
	void rank_stuID();//根据学号排序
	void rank_age();//根据年龄排序
	void rank_GChin();//根据语文成绩排序
	void rank_Gmath();//根据数学成绩排序
	void rank_GEng();//根据英语成绩排序
	void rank_name();  //根据姓名进行排序
	void delete_stu();  //删除学生信息，利用姓名查找并删除
	void show_allstu();  //打印所有学生的信息
	void outfile_txt(); //保存所有学生信息到文件中
	void infile_txt(); //从文件中读取学生信息
	void show_stu(int pos);//显示某个学生的信息，形参表示该学生所在位置
	int man_count();//统计男生人数
	double aver_Chin();//统计语文成绩的平均分
	double aver_math();//统计数学成绩的平均分
	double aver_Eng();	//统计英语成绩的平均分
};



