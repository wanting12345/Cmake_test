#include"student.h"
#include<iostream>
#include<string>
#include"menu.h"
using namespace std;

int flag1, flag2;
int main()
{
	student stu_list;
	stu_list.infile_txt();
	while (true)
	{
		choice1(flag1);
		if (flag1 == 4)break;
		switch (flag1)
		{
		case 1:
		{
			while (true)
			{
				choice2_1(flag2);
				if (flag2 == 4)break;
				switch (flag2)
				{
				case 1:stu_list.insert_stu(); break;
				case 2:stu_list.modify_stu(); break;
				case 3:stu_list.delete_stu(); break;
				}
			}
			break;
		}
		case 2:
		{
			while (true)
			{
				choice2_2(flag2);
				if (flag2 == 7)break;
				switch (flag2)
				{
				case 1:stu_list.rank_name(); stu_list.show_allstu(); break;
				case 2:stu_list.rank_stuID(); stu_list.show_allstu(); break;
				case 3:stu_list.rank_age(); stu_list.show_allstu(); break;
				case 4:stu_list.rank_GChin(); stu_list.show_allstu(); break;
				case 5:stu_list.rank_Gmath(); stu_list.show_allstu(); break;
				case 6:stu_list.rank_GEng(); stu_list.show_allstu(); break;
				}
			}
			break;
		}
		case 3:stu_list.show_allstu(); break;

		}
	}
}

