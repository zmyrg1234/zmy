#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE��
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
int k = 1, n = 0, m = 0;/*����ȫ�ֱ����� n����ǰ��¼��Ա����������mΪ�����ӵ�Ա������*/
/* ��������*/
void help();         /* ��������*/
void readfile();    /* ��������*/
void modify();       /* �޸�����*/
void insert();       /* ��������*/
void del();          /* ɾ������*/
void display();       /* ��ʾ��Ϣ*/
void save();          /* ������Ϣ*/
void menu();        /* �˵�*/
void man();
void checki();
void seek();
void insert2();

void man()
{
	int num = 0;
	
		readfile();
		printf("1.��ʾ��ǰ��Ϣ\n");
		printf("2.��ѯԱ����Ϣ\n");
		printf("3.�����̨\n");
		printf("4.�˳�\n");
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
	printf("�������̨����\n");
	scanf("%d", &z);
	if(z==12345)
	{
		menu();
	}
	else
	{
		printf("��������˳�\n");
		man();
	}

}
void readfile()
{
	FILE* fp;                             /* �ļ�ָ��*/
	int i = 0;
	if ((fp = fopen("1.txt", "r")) == NULL)
	{
		printf("���ļ�����");
		printf("����Ҫ��ѡ��˵�4����Ա����Ϣ\n");
		system("pause");
		return;
	}
	while (fscanf(fp, "%s%s%d%d%d%d%d", worker[i].code, worker[i].name, &worker[i].age, &worker[i].sex, &worker[i].infm[0], &worker[i].infm[1], &worker[i].infm[2]) == 7)
	{
		i++;
	}
	n = i;
	if (0 == i)
		printf("�ļ�Ϊ�գ�����Ҫ��ѡ��˵�4����Ա����Ϣ\n");
	fclose(fp);
	return n;
}
void seek() /*����*/
{
	int i, item, flag;
	char s1[21]; /* �������͹��������+1Ϊ׼*/
	printf("-----1.�����Ų�ѯ-----\n");
	printf("-----2.��������ѯ-----\n");
	printf("-----3.�˳����˵�-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("��ѡ���Ӳ˵����:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("������Ҫ��ѯ��Ա���Ĺ���:\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
				if (strcmp(worker[i].code, s1) == 0)
				{
					flag = 1;
					printf("����      ����    ����    �Ա�    ����     ����˱���  ���\n");
					printf("--------------------------------------------------------------------\n");
					printf("%6s %7s %6d %6d %10d %6d %6d\n", worker[i].code, worker[i].name, worker[i].age, worker[i].sex, worker[i].infm[0], worker[i].infm[1], worker[i].infm[2]);
				}
			if (0 == flag)
				printf("�ù��Ų����ڣ�\n"); break;
		case 2:
			printf("������Ҫ��ѯ��Ա��������:\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
				if (strcmp(worker[i].name, s1) == 0)
				{
					flag = 1;
					printf("����      ����    ����    �Ա�    ����     ����˱���  ���\n");
					printf("--------------------------------------------------------------------\n");
					printf("%6s %7s %6d %6d %10d %6d %6d\n", worker[i].code, worker[i].name, worker[i].age, worker[i].sex, worker[i].infm[0], worker[i].infm[1], worker[i].infm[2]);
				}
			if (0 == flag)
				printf("�����������ڣ�\n"); break;
		case 3:system("pause");
			man();break;
		default:printf("����1-3֮��ѡ��\n");
		}
	}
}


void modify() /*�޸���Ϣ*/
{
	int i, item, num;
	char sex1, s1[LEN + 1], s2[LEN + 1];
	float infm1;
	printf("������ҪҪ�޸ĵ�Ա���Ĺ���:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++)
		if (strcmp(worker[i].code, s1) == 0) /*�Ƚ��ַ����Ƿ����*/
			num = i;
	printf("------------------\n");
	printf("1.�޸�����\n");
	printf("2.�޸�����\n");
	printf("3.�޸��Ա�\n");
	printf("4.�޸��ֻ�����\n");
	printf("5.�޸Ĺ���\n");
	printf("6.�޸����\n");
	printf("7.�˳����˵�\n");
	printf("------------------\n");
	while (1)
	{
		printf("��ѡ���Ӳ˵����:");
		scanf("%d", &item);
		switch (item)
		{
		case 1:
			printf("�������µ�����(3):\n");
			scanf("%s", s2);
			strcpy(worker[num].name, s2); break;
		case 2:
			printf("�������µ�����(2):\n");
			scanf("%d", worker[num].age); break;
		case 3:
			printf("�������µ��Ա�(1):\n");
			scanf("%c", &sex1);
			worker[num].sex = sex1; break;
		case 4:
			printf("�������µ��ֻ�����(6):\n");
			scanf("%d", &infm1);
			worker[num].infm[0] = infm1; break;
		case 5:
			printf("�������µĹ���(1):\n");
			scanf("%d", &infm1);
			worker[num].infm[1] = infm1; break;
		case 6:
			printf("�������µ����(1):\n");
			scanf("%d", &infm1);
			worker[num].infm[2] = infm1; break;
		case 7: system("pause");
			man(); break;
		default:printf("����1-7֮��ѡ��\n");
		}
	}
}

void insert() /*���뺯��*/
{   
	int j = n, i, flag;

	printf("����������ӵ�Ա����:\n");
	scanf("%d", &m);
	if (m > 0)
	{
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("�������%dλԱ���Ĺ���:\n", j + 1);
				scanf("%s", worker[j].code);
				for (i = 0; i < j; i++)                     /*��֮ǰ�Ĺ���űȽϣ�����ظ�������������*/
					if (strcmp(worker[j].code, worker[i].code) == 0)
					{
						printf("���иù��ţ�������¼��\n");
						flag = 1;
						break;                       /*�����ظ����˳��ڲ�ѭ��*/
					}
			}
			printf("�������%d��Ա��������(3):\n", j + 1);
			scanf("%s", worker[j].name);
			printf("�������%d��Ա��������(2):\n", j + 1);
			scanf("%d", &worker[j].age);
			printf("�������%d��Ա�����Ա�(1):\n", j + 1);
			scanf("%d", &worker[j].sex);
			printf("�������%d��Ա�����ֻ�����(6)\n", j + 1);
			scanf("%d", &worker[j].infm[0]);
			printf("�������%d��Ա���Ĺ���(1):\n", j + 1);
			scanf("%d", &worker[j].infm[1]);
			printf("�������%d��Ա�������(1):\n", j + 1);
			scanf("%d", &worker[j].infm[2]);
			if (0 == flag)
			{
				j++;
			}
		} while (j < n + m);
	}
	n += m;
	printf("��Ϣ������ϣ�\n\n");
	save();
	system("pause");
	man();
}
void insert2() /*���뺯��2*/
{
	int j = n, i, flag;
	m = 1;
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("���ǵ�%dλԱ���������빤��:\n", j + 1);
				scanf("%s", worker[j].code);
				for (i = 0; i < j; i++)                     /*��֮ǰ�Ĺ���űȽϣ�����ظ�������������*/
					if (strcmp(worker[j].code, worker[i].code) == 0)
					{
						printf("���иù��ţ�������¼��\n");
						flag = 1;
						break;                       /*�����ظ����˳��ڲ�ѭ��*/
					}
		
			printf("�������������(3):\n");
			scanf("%s", worker[j].name);
			printf("�������������(2):\n");
			scanf("%d", &worker[j].age);
			printf("��������ĵ��Ա�(��1Ů2):\n");
			scanf("%d", &worker[j].sex);
			printf("��������ĵ��ֻ�����(6)\n");
			scanf("%d", &worker[j].infm[0]);
			printf("��������Ĺ���(1):\n");
			scanf("%d", &worker[j].infm[1]);
			printf("������������(1):\n");
			scanf("%d", &worker[j].infm[2]);
			if (0 == flag)
			{
				j++;
			}
		} 
	} while (j < n + m);
		n++;
	printf("��Ϣ������ϣ�\n\n");
	save();
	system("pause");
}

void del()
{
	int i, j, flag = 0;         /* flagΪ0��ʾ����ʧ�ܣ�Ϊ1��ʾ���ҳɹ�*/
	char s1[LEN + 1];
	printf("������Ҫɾ��Ա���Ĺ���:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++)
		if (strcmp(worker[i].code, s1) == 0)
		{
			flag = 1;                   /*���ҳɹ�*/
			for (j = i; j < n - 1; j++)
				worker[j] = worker[j + 1];

		}
	if (flag == 0)                /*����ʧ��*/
		printf("�ù��Ų����ڣ�\n");
	if (flag == 1)
	{
		printf("ɾ���ɹ�,��ʾ�����ѡ��˵�\n");
		n--;
	}
	system("pause");
	man();
}


void display()
{
	int i;
	printf("����%dλԱ������Ϣ:\n", n);
	if (0 != n)
	{
		printf("����      ����    ����  �Ա���1Ů2��   ����     ����     ���\n");
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
	printf("����ɹ�\n");
	fclose(fp);
	system("pause");
	man();
}


void menu()/* ����*/
{
	int num;
	printf("  Ա����Ϣϵͳ\n");
	printf("1.ˢ��Ա����Ϣ\n");
	printf("2.�޸�Ա����Ϣ\n");
	printf("3.����Ա����Ϣ\n");
	printf("4.������ɾ����Ϣ\n");
	printf("5.��ʾ��ǰ��Ϣ\n");
	printf("6.���浱ǰԱ����Ϣ\n");
	printf("7.��ѯԱ����Ϣ\n");
	printf("8.�˳�ϵͳ\n");
	printf("------------------\n");
	printf("��ѡ��˵����:");
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
	default:printf("����0-7֮��ѡ��\n");
	}
}