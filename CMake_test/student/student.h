#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include <cstdlib>
#include<fstream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
struct student_data  //����һ���ڵ�ṹ����ʾÿ��ѧ������Ϣ
{
	char* _name;  //����
	int _stuID; //ѧ��
	char _gender; //�Ա�
	int _age; //����
	int _GChin;//���ĳɼ�
	int _Gmath;//��ѧ�ɼ�
	int _GEng;//Ӣ��ɼ�
	student_data* Next_stu;//ָ����һ�����c��ָ�

	
	student_data()  //Ĭ�Ϲ��캯��
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
	student_data(int pos) //�����������е�λ�ô���ѧ����Ϣ�Ĺ��캯��������ѧ��ʱ�õ���
	{
		_name = new char[20];
		cout << "������Ҫ����ĵ�" << pos << "λѧ����������";
		cin >> _name;
		cout << "������" << _name << "��ѧ�ţ�";
		cin >> _stuID;
		cout << "������" << _name << "���Ա�";
		cin >> _gender;
		cout << "������" << _name << "�����䣺";
		cin >> _age;
		cout << "������" << _name << "�����Ŀγɼ���";
		cin >> _GChin;
		cout << "������" << _name << "����ѧ�γɼ���";
		cin >> _Gmath;
		cout << "������" << _name << "��Ӣ��γɼ���";
		cin >> _GEng;

	}
	//���ι��캯�������ļ�ʱ�õ���
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
class student  //������
{

	static int Count;  //ѧ������
	student_data* Head;	//ͷָ��
public:
	student()
	{
		student_data* p = new student_data; //����ͷ��㲢��ʼ���ó�Ա
		Head = p;
		Head->Next_stu = NULL;
	}
	~student()  //��������
	{
	}
	//���ѧ����Ϣ����ͨ���ļ�����ѧ����Ϣʱ��Ҫ�õ�
	void Add_Student(char* name, int student_id, char  gender, int age, int GChi, int Gmath, int GEng);
	void insert_stu();//����ѧ����Ϣ
	void modify_stu(); //�޸�ѧ����Ϣ
	void rank_stuID();//����ѧ������
	void rank_age();//������������
	void rank_GChin();//�������ĳɼ�����
	void rank_Gmath();//������ѧ�ɼ�����
	void rank_GEng();//����Ӣ��ɼ�����
	void rank_name();  //����������������
	void delete_stu();  //ɾ��ѧ����Ϣ�������������Ҳ�ɾ��
	void show_allstu();  //��ӡ����ѧ������Ϣ
	void outfile_txt(); //��������ѧ����Ϣ���ļ���
	void infile_txt(); //���ļ��ж�ȡѧ����Ϣ
	void show_stu(int pos);//��ʾĳ��ѧ������Ϣ���βα�ʾ��ѧ������λ��
	int man_count();//ͳ����������
	double aver_Chin();//ͳ�����ĳɼ���ƽ����
	double aver_math();//ͳ����ѧ�ɼ���ƽ����
	double aver_Eng();	//ͳ��Ӣ��ɼ���ƽ����
};



