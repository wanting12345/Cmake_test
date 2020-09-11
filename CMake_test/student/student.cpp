#include <string.h>
#pragma warning(disable:4996)
#include "student.h"
#include<string>

using namespace std;

int student::Count = 0;
void student::insert_stu()
{
	int insertPos;
	cout << "��������Ҫ�����λ�ã�" << endl;
	while (true)
	{
		cin >> insertPos;
		if (!cin >> insertPos)
		{
			cin.clear();
			cin.ignore();
			cout << "������������������" << endl;

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
	cout << "����ѧ������Ϣ���£�" << endl;
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
		cout << "����" << "           ѧ��" << "       �Ա�" << "    ����" << "       �༶" << "          ����״��" << endl;
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
	cout << "  ����" << "           ѧ��" << "      �Ա�" << "         ����" << "          ���ĳɼ�" << "         ��ѧ�ɼ�" << "        Ӣ��ɼ�" << endl;
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
	cout << left << setw(10) << setfill(' ') << " ƽ���֣�"
		<< setw(47) << " "
		<< left << setw(16) << setfill(' ') << fixed << setprecision(2) << aver_Chin()
		<< left << setw(16) << setfill(' ') << fixed << setprecision(2) << aver_math()
		<< left << setw(16) << setfill(' ') << fixed << setprecision(2) << aver_Eng() << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << '\n' << "�����ܹ���" << man_count() << "��, " << "Ů���ܹ���" << (Count - man_count()) << "��" << '\n' << endl;
	system("pause");
}
void student::delete_stu()
{
	char flag_char;
	int deletePos;
	cout << "����������ɾ����ѧ��������λ�ã�";
	while (true)
	{
		cin >> deletePos;
		if (!cin >> deletePos)
		{
			cin.clear();
			cin.ignore();
			cout << "������������������" << endl;

		}
		else break;
	}
	student_data* p = Head;
	//��ʾѧ����Ϣȷ���Ƿ�Ҫɾ��
	show_stu(deletePos);
	while (true)
	{
		cout << "��ȷ��Ҫɾ����ѧ����(Yȷ��Nȡ��)" << endl;
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
			cout << "���Ѿ��ɹ�ɾ����ѧ����";
			break;
		}
		else if (flag_char == 'N' || flag_char == 'n')
		{
			cout << "���Ѿ��ɹ�ȡ���ò�����";
			break;
		}
		else
		{
			cout << "���������������������!";
		}
	}


	system("pause");
	return;
}
void student::modify_stu()
{
	int modifyPos;
	cout << "��������Ҫ�޸ĵ�ѧ����λ�ã�" << endl;
	while (true)
	{
		cin >> modifyPos;
		if ((!cin >> modifyPos) || modifyPos > Count)
		{
			cin.clear();
			cin.ignore();
			cout << "��ѧ�������ڣ�����������" << endl;
		}
		else break;
	}
	cout << "��ѧ��ԭ�е���ϢΪ��" << endl;
	show_stu(modifyPos);
	char name[20] = { 0 };
	cout << "����������Ҫ�޸ĵ�ѧ��������";
	cin >> name;
	student_data* now = new student_data;
	student_data* p = Head;
	int i = 0;
	while (i < modifyPos && p->Next_stu != NULL)
	{
		p = p->Next_stu;
		i++;
	}
	cout << "���������޸ĺ�����֣�";
	cin >> now->_name;
	cout << endl;
	if (now->_name != "NULL")
	{
		strcpy(p->_name, now->_name);
	}
	cout << "���������޸ĺ��ѧ�ţ�";
	cin >> now->_stuID;
	cout << endl;
	if (now->_stuID != NULL)
	{
		p->_stuID = now->_stuID;
	}
	cout << "���������޸ĺ���Ա�";
	cin >> now->_gender;
	cout << endl;
	if (now->_gender != NULL)
	{
		p->_gender = now->_gender;
	}
	cout << "���������޸ĺ�����䣺";
	cin >> now->_age;
	cout << endl;
	if (now->_age != NULL)
	{
		p->_age = now->_age;
	}
	cout << "���������޸ĺ�����Ŀγɼ���";
	cin >> now->_GChin;
	cout << endl;
	if (now->_GChin != NULL)
	{
		p->_GChin = now->_GChin;
	}
	cout << "���������޸ĺ����ѧ�γɼ���";
	cin >> now->_Gmath;
	cout << endl;
	if (now->_Gmath != NULL)
	{
		p->_Gmath = now->_Gmath;
	}
	cout << "���������޸ĺ��Ӣ��γɼ���";
	cin >> now->_GEng;
	cout << endl;
	if (now->_GEng != NULL)
	{
		p->_GEng = now->_GEng;
	}
	cout << "�޸ĺ��ѧ��������£�" << endl;
	show_stu(modifyPos);
	outfile_txt();
	delete now;
	system("pause");
}
void student::Add_Student(char* name, int student_id, char  gender, int age, int GChin, int Gmath, int GEng)
{
	student_data* p = Head;
	student_data* q = new  student_data(name, student_id, gender, age, GChin, Gmath, GEng);
	//����һ���ڵ㲢��������������
	Count++;
	for (int i = 1; i < Count; i++)
	{
		p = p->Next_stu;
	}
	p->Next_stu = q;
	return;
}
void student::rank_stuID()
{  //ð�����򷨶�ѧ�Ž���������Ҫ��ָ���Ĺ�ϵ�Ķ�
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
{  //ð�����򷨶�ѧ�Ž���������Ҫ��ָ���Ĺ�ϵ�Ķ�
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
{  //ð�����򷨶�ѧ�Ž���������Ҫ��ָ���Ĺ�ϵ�Ķ�
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
{  //ð�����򷨶�ѧ�Ž���������Ҫ��ָ���Ĺ�ϵ�Ķ�
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
{  //ð�����򷨶�ѧ�Ž���������Ҫ��ָ���Ĺ�ϵ�Ķ�
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
void student::outfile_txt()  //��������ѧ����Ϣ���ļ���
{
	ofstream outfile("D:\\student.txt");
	//���浽���ļ�Ŀ¼�µ��ļ������û�и��ļ������ᴴ�����ļ����еĻ��������ԭ���ļ��е���������
	student_data* p = Head;
	if (!outfile.is_open())  //����ļ�����ʧ�ܣ��ͷ��ز����к�������
	{
		cout << "�ļ�����ʧ�ܣ�����";
		return;
	}
	outfile << "����" << "           ѧ��" << "       �Ա�" << "    ����" << "   ���ĳɼ�" << "   ��ѧ�ɼ�" << "   Ӣ��ɼ�" << endl;
	for (int i = 1; i <= Count; i++)
	{ //��������룬����ַ����Ƹ�ʽ����������ļ�
		p = p->Next_stu;
		outfile << left << setw(15) << setfill(' ') << p->_name;
		outfile << left << setw(12) << setfill(' ') << p->_stuID;
		outfile << left << setw(8) << setfill(' ') << p->_gender;
		outfile << left << setw(10) << setfill(' ') << p->_age;
		outfile << left << setw(10) << setfill(' ') << p->_GChin;
		outfile << left << setw(10) << setfill(' ') << p->_Gmath;
		outfile << left << setw(10) << setfill(' ') << p->_GEng << endl;
	}
	outfile.close(); //�رո��ļ���
}
void student::infile_txt() //���ļ��ж�ȡѧ����Ϣ
{
	ifstream infile("D:\\student.txt");
	if (!infile.is_open())
	{
		cout << "�ļ���ʧ�ܣ�����";
		return;
	}
	student_data* p = Head;
	char status[80];  //�ļ��еĵ�һ��Ĭ����ʾһЩ��Ϣ��������һ����ϢӦ�ñ���ȡ��Ȼ����
	infile.getline(status, 100);  //��ȡ100���ַ���getline��
	char name[20];
	int stuID;
	char gender;
	int age;
	int _GChi;
	int _Gmath;
	int _GEng;
	while (infile.good())  //good()���Ի�ȡ�Ƿ���һ�ֺõ�״̬���ﵽ�ļ�β���������Ͳ�ƥ�䶼�᷵��false
	{  //���ļ��е���Ϣ��ӵ�������
		infile >> name >> stuID >> gender >> age >> _GChi >> _Gmath >> _GEng;
		Add_Student(name, stuID, gender, age, _GChi, _Gmath, _GEng);
		cout << name << '\t' << stuID << '\t' << gender << '\t' << age << '\t' << _GChi << '\t' << _Gmath << '\t' << _GEng << endl;
	}
	infile.close();  //�ر��ļ���
	cout << "����ѧ����Ϣ�ɹ�" << endl;
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
