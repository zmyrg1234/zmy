#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE；
#define LEN 15      
#define N 200      
struct record
{
	char code[LEN + 1];
	char name[LEN + 1];
	int age;
	int sex;
	int infm[3];
}worker[N];
int k = 1, n = 0, m = 0;/*定义全局变量， n代表当前记录的员工总人数，m为新增加的员工人数*/
/* 函数声明*/
void help();         /* 帮助界面*/
void readfile();    /* 读入数据*/
void modify();       /* 修改数据*/
void insert();       /* 插入数据*/
void del();          /* 删除数据*/
void display();       /* 显示信息*/
void save();          /* 保存信息*/
void menu();        /* 菜单*/
void man();
void checki();
void seek();
void insert2();

void man()
{
	int num = 0;
	
		readfile();
		printf("1.显示当前信息\n");
		printf("2.查询员工信息\n");
		printf("3.进入后台\n");
		printf("4.退出\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:display(); break;
		case 2:seek(); break;
		case 3:checki(); break;
		case 4: MAIN_LOOP(); break;
		}

}
void checki()
{
	int z = 0;
	printf("请输入后台口令\n");
	scanf("%d", &z);
	if(z==12345)
	{
		menu();
	}
	else
	{
		printf("输入错误，退出\n");
		man();
	}

}
void readfile()
{
	FILE* fp;                             /* 文件指针*/
	int i = 0;
	if ((fp = fopen("1.txt", "r")) == NULL)
	{
		printf("打开文件错误");
		printf("你需要先选择菜单4增加员工信息\n");
		system("pause");
		return;
	}
	while (fscanf(fp, "%s%s%d%d%d%d%d", worker[i].code, worker[i].name, &worker[i].age, &worker[i].sex, &worker[i].infm[0], &worker[i].infm[1], &worker[i].infm[2]) == 7)
	{
		i++;
	}
	n = i;
	if (0 == i)
		printf("文件为空，你需要先选择菜单4增加员工信息\n");
	fclose(fp);
	return n;
}
void seek() /*查找*/
{
	int i, item, flag;
	char s1[21]; /* 以姓名和工号最长长度+1为准*/
	printf("-----1.按工号查询-----\n");
	printf("-----2.按姓名查询-----\n");
	printf("-----3.退出本菜单-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("请输入要查询的员工的工号:\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
				if (strcmp(worker[i].code, s1) == 0)
				{
					flag = 1;
					printf("工号      姓名    年龄    性别    号码     最后账本号  组别\n");
					printf("--------------------------------------------------------------------\n");
					printf("%6s %7s %6d %6d %10d %6d %6d\n", worker[i].code, worker[i].name, worker[i].age, worker[i].sex, worker[i].infm[0], worker[i].infm[1], worker[i].infm[2]);
				}
			if (0 == flag)
				printf("该工号不存在！\n"); break;
		case 2:
			printf("请输入要查询的员工的姓名:\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
				if (strcmp(worker[i].name, s1) == 0)
				{
					flag = 1;
					printf("工号      姓名    年龄    性别    号码     最后账本号  组别\n");
					printf("--------------------------------------------------------------------\n");
					printf("%6s %7s %6d %6d %10d %6d %6d\n", worker[i].code, worker[i].name, worker[i].age, worker[i].sex, worker[i].infm[0], worker[i].infm[1], worker[i].infm[2]);
				}
			if (0 == flag)
				printf("该姓名不存在！\n"); break;
		case 3:system("pause");
			man();break;
		default:printf("请在1-3之间选择\n");
		}
	}
}


void modify() /*修改信息*/
{
	int i, item, num;
	char sex1, s1[LEN + 1], s2[LEN + 1];
	float infm1;
	printf("请输入要要修改的员工的工号:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++)
		if (strcmp(worker[i].code, s1) == 0) /*比较字符串是否相等*/
			num = i;
	printf("------------------\n");
	printf("1.修改姓名\n");
	printf("2.修改年龄\n");
	printf("3.修改性别\n");
	printf("4.修改手机号码\n");
	printf("5.修改工龄\n");
	printf("6.修改组别\n");
	printf("7.退出本菜单\n");
	printf("------------------\n");
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		switch (item)
		{
		case 1:
			printf("请输入新的姓名(3):\n");
			scanf("%s", s2);
			strcpy(worker[num].name, s2); break;
		case 2:
			printf("请输入新的年龄(2):\n");
			scanf("%d", worker[num].age); break;
		case 3:
			printf("请输入新的性别(1):\n");
			scanf("%c", &sex1);
			worker[num].sex = sex1; break;
		case 4:
			printf("请输入新的手机号码(6):\n");
			scanf("%d", &infm1);
			worker[num].infm[0] = infm1; break;
		case 5:
			printf("请输入新的工龄(1):\n");
			scanf("%d", &infm1);
			worker[num].infm[1] = infm1; break;
		case 6:
			printf("请输入新的组别(1):\n");
			scanf("%d", &infm1);
			worker[num].infm[2] = infm1; break;
		case 7: system("pause");
			man(); break;
		default:printf("请在1-7之间选择\n");
		}
	}
}

void insert() /*插入函数*/
{   
	int j = n, i, flag;

	printf("请输入待增加的员工数:\n");
	scanf("%d", &m);
	if (m > 0)
	{
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("请输入第%d位员工的工号:\n", j + 1);
				scanf("%s", worker[j].code);
				for (i = 0; i < j; i++)                     /*与之前的工龄号比较，如果重复，则重新输入*/
					if (strcmp(worker[j].code, worker[i].code) == 0)
					{
						printf("已有该工号，请重新录入\n");
						flag = 1;
						break;                       /*如有重复，退出内层循环*/
					}
			}
			printf("请输入第%d个员工的姓名(3):\n", j + 1);
			scanf("%s", worker[j].name);
			printf("请输入第%d个员工的年龄(2):\n", j + 1);
			scanf("%d", &worker[j].age);
			printf("请输入第%d个员工的性别(1):\n", j + 1);
			scanf("%d", &worker[j].sex);
			printf("请输入第%d个员工的手机号码(6)\n", j + 1);
			scanf("%d", &worker[j].infm[0]);
			printf("请输入第%d个员工的工龄(1):\n", j + 1);
			scanf("%d", &worker[j].infm[1]);
			printf("请输入第%d个员工的组别(1):\n", j + 1);
			scanf("%d", &worker[j].infm[2]);
			if (0 == flag)
			{
				j++;
			}
		} while (j < n + m);
	}
	n += m;
	printf("信息增加完毕！\n\n");
	save();
	system("pause");
	man();
}
void insert2() /*插入函数2*/
{
	int j = n, i, flag;
	m = 1;
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("你是第%d位员工，请输入工号:\n", j + 1);
				scanf("%s", worker[j].code);
				for (i = 0; i < j; i++)                     /*与之前的工龄号比较，如果重复，则重新输入*/
					if (strcmp(worker[j].code, worker[i].code) == 0)
					{
						printf("已有该工号，请重新录入\n");
						flag = 1;
						break;                       /*如有重复，退出内层循环*/
					}
		
			printf("请输入你的姓名(3):\n");
			scanf("%s", worker[j].name);
			printf("请输入你的年龄(2):\n");
			scanf("%d", &worker[j].age);
			printf("请输入你的的性别(男1女2):\n");
			scanf("%d", &worker[j].sex);
			printf("请输入你的的手机号码(6)\n");
			scanf("%d", &worker[j].infm[0]);
			printf("请输入你的工龄(1):\n");
			scanf("%d", &worker[j].infm[1]);
			printf("请输入你的组别(1):\n");
			scanf("%d", &worker[j].infm[2]);
			if (0 == flag)
			{
				j++;
			}
		} 
	} while (j < n + m);
		n++;
	printf("信息增加完毕！\n\n");
	save();
	system("pause");
}

void del()
{
	int i, j, flag = 0;         /* flag为0表示查找失败，为1表示查找成功*/
	char s1[LEN + 1];
	printf("请输入要删除员工的工号:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++)
		if (strcmp(worker[i].code, s1) == 0)
		{
			flag = 1;                   /*查找成功*/
			for (j = i; j < n - 1; j++)
				worker[j] = worker[j + 1];

		}
	if (flag == 0)                /*查找失败*/
		printf("该工号不存在！\n");
	if (flag == 1)
	{
		printf("删除成功,显示结果请选择菜单\n");
		n--;
	}
	system("pause");
	man();
}


void display()
{
	int i;
	printf("共有%d位员工的信息:\n", n);
	if (0 != n)
	{
		printf("工号      姓名    年龄  性别（男1女2）   号码     工龄     组别\n");
		for (i = 0; i < n; i++)
		{
			printf("%7s %7s %6d %6d %10d %6d %6d\n", worker[i].code, worker[i].name, worker[i].age, worker[i].sex, worker[i].infm[0], worker[i].infm[1], worker[i].infm[2]);
		}
	}
	system("pause");
	man();
}

void save()
{
	int i;
	FILE* fp;
	fp = fopen("1.txt", "w");
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %d %d %d %d %d\n", worker[i].code, worker[i].name, worker[i].age, worker[i].sex, worker[i].infm[0], worker[i].infm[1], worker[i].infm[2]);
	}
	printf("保存成功\n");
	fclose(fp);
	system("pause");
	man();
}


void menu()/* 界面*/
{
	int num;
	printf("  员工信息系统\n");
	printf("1.刷新员工信息\n");
	printf("2.修改员工信息\n");
	printf("3.增加员工信息\n");
	printf("4.按工号删除信息\n");
	printf("5.显示当前信息\n");
	printf("6.保存当前员工信息\n");
	printf("7.查询员工信息\n");
	printf("8.退出系统\n");
	printf("------------------\n");
	printf("请选择菜单编号:");
	scanf("%d", &num);
	switch (num)
	{
	case 1:readfile(); break;
	case 2:modify(); break;
	case 3:insert(); break;
	case 4:del(); break;
	case 5:display(); break;
	case 6:save(); break;
	case 7:seek(); break;
	case 8:k = 0; break;
	default:printf("请在0-7之间选择\n");
	}
}