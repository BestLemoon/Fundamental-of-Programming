#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<algorithm>
#define N 1000
int linenum1 = 0;
int linenum2 = 0;
int linenum3 = 0;
int linenum4 = 0;
struct product
{
	string name;
	int stored_nums;
	int nums;//��������or�˻�����
	string date;

}products[N],refund[N], sell[N];
struct passwd
{
	string name;
	string passwd;
}guest[N];
int pass(char account[], char passwd[],int flag)
{
	char admin_name[10] = "admin";
	char admin_password[20] = "password";
	if (flag == 1)
	{
		if (strcmp(account, admin_name) == 0 && strcmp(passwd, admin_password) == 0)
			return 1;//Right 
		return 0;//Wrong
	}
	else
	{
		for(int i=0;i<linenum4;i++)
			if(guest[i].name==account&&guest[i].passwd==passwd)
				return 1;//Right 
		return 0;//Wrong
	}
}
int add(char* name,int nums)
{
	int flag = 0;
	for (int i = 0; i < linenum1; i++)
	{
		if (products[i].name==name)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("���ʧ�ܣ�����Ʒ�Ѵ���\n");
		return 0;
	}
	products[linenum1].name =name;
	products[linenum1].stored_nums =nums;
	linenum1++;
	printf("��ӳɹ����ǵô��̣����س��Լ���\n");
	return 0;
}
int search(string info)
{
	int flag = 0;
	for (int i = 0; i < linenum1; i++)
	{
		if (info==products[i].name)
		{
			printf("%s %d\n", products->name.c_str(),products->stored_nums);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("���޴���Ʒ\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	return 0;
}
int fix(int x, char* info,char* name)
{
	int flag = 0;
	for (int i = 0; i < linenum1; i++)
		if (name == products[i].name)
			flag = i;
	switch (x)
	{
	case 1:
		products[flag].name = info;
		break;
	case 2:
		products[flag].stored_nums = atoi(info);
		break;
	}
	printf("�޸ĳɹ����ǵô��̣�\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	//Search first then choose what infomation to change then change the information
	return 0;
}
void del(string info)
{
	int flag = 0;
	for (int i = 0; i < linenum1; i++)
		if (products[i].name == info)
			flag = i;
	for (int i = flag; i < linenum1; i++)
		products[i] = products[i + 1];
	linenum1--;
	printf("ɾ���ɹ����ǵô��̣�\n");
	printf("���س��Լ���\n");
	getchar();
}
void store()
{
	FILE* fp = NULL;
	int flag = 0, c;
	fp = fopen("products.txt", "w");
	for (int i = 0; i < linenum1; i++)
		fprintf(fp, "%s %d\n", products[i].name.c_str(),products[i].stored_nums);
	fclose(fp);
}
void view()
{
	FILE* fp;
	int flag = 0, c;
	linenum1 = 0;
	fp = fopen("products.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum1++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum1++;
	fclose(fp);
	if ((fp = fopen("products.txt", "r")) == NULL)
	{
		fp = fopen("products.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("products.txt", "r");
		char products_name_tmp[50];
		for (int k = 0; k < linenum1; k++)
		{
			fscanf(fp, "%s %d", products_name_tmp,&products[k].stored_nums);
			products[k].name = products_name_tmp;
		}
		fclose(fp);
	}//store all infos into list
	for (int i = 0; i < linenum1; i++)
		printf("%s      %d\n", products[i].name.c_str(),products[i].stored_nums);
	printf("���س��Լ���\n");
	getchar();
	getchar();
}


int add2(char* name, int nums)
{
	int flag = 0;
	for (int i = 0; i < linenum4; i++)
	{
		if (guest[i].name == name)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("���ʧ�ܣ������Ѵ���\n");
		return 0;
	}
	guest[linenum4].name = name;
	guest[linenum4].passwd = nums;
	linenum4++;
	printf("��ӳɹ����ǵô��̣����س��Լ���\n");
	return 0;
}
int search2(string info)
{
	int flag = 0;
	for (int i = 0; i < linenum4; i++)
	{
		if (info == guest[i].name)
		{
			printf("%s %s\n", products->name.c_str(), guest->passwd.c_str());
			flag = 1;
		}
	}
	if (flag == 0)
		printf("���޴���\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	return 0;
}
int fix2(int x, char* info, char* name)
{
	int flag = 0;
	for (int i = 0; i < linenum4; i++)
		if (name == guest[i].name)
			flag = i;
	switch (x)
	{
	case 1:
		guest[flag].name = info;
		break;
	case 2:
		guest[flag].passwd = info;
		break;
	}
	printf("�޸ĳɹ����ǵô��̣�\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	//Search first then choose what infomation to change then change the information
	return 0;
}
void del2(string info)
{
	int flag = 0;
	for (int i = 0; i < linenum4; i++)
		if (guest[i].name == info)
			flag = i;
	for (int i = flag; i < linenum4; i++)
		guest[i] = guest[i + 1];
	linenum4--;
	printf("ɾ���ɹ����ǵô��̣�\n");
	printf("���س��Լ���\n");
	getchar();
}
void store2()
{
	FILE* fp = NULL;
	int flag = 0, c;
	fp = fopen("pass.txt", "w");
	for (int i = 0; i < linenum4; i++)
		fprintf(fp, "%s %s\n", guest[i].name.c_str(), guest[i].passwd.c_str());
	fclose(fp);
}
void view2()
{
	FILE* fp;
	int flag = 0, c;
	linenum4 = 0;
	fp = fopen("pass.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum4++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum4++;
	fclose(fp);
	if ((fp = fopen("pass.txt", "r")) == NULL)
	{
		fp = fopen("pass.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("pass.txt", "r");
		char guest_name_tmp[50], guest_pass_tmp[50];
		for (int k = 0; k < linenum1; k++)
		{
			fscanf(fp, "%s %s", guest_name_tmp,guest_pass_tmp );
			guest[k].name = guest_name_tmp;
			guest[k].passwd = guest_pass_tmp;
		}
		fclose(fp);
	}//store all infos into list
	for (int i = 0; i < linenum4; i++)
		printf("%s      %s\n", guest[i].name.c_str(), guest[i].passwd.c_str());
	printf("���س��Լ���\n");
	getchar();
	getchar();
}


void search_sell(int flag,string info)//1 products 2 date
{
	for (int i = 0; i < linenum2; i++)
	{
		if (flag == 1 && info == sell[i].name || flag == 2 && info == sell[i].date)
			printf("%s %d %s\n", sell[i].name.c_str(), sell[i].nums, sell[i].date.c_str());
	}
	printf("���س��Լ���\n");
	getchar();
	getchar();
}
void sell_sum(char* date)
{
	int sum;
	printf("%s�������\n", date);
	for (int i = 0; i < linenum1; i++)
	{
		sum = 0;
		for (int j = 0; j < linenum2; j++)
		{
			if (products[i].name == sell[j].name&&date==sell[j].date)
				sum+=sell[j].nums;
		}
		printf("%s������%d��\n", products[i].name.c_str(), sum);
	}
	printf("���س��Լ���\n");
	getchar();
	getchar();
}
int add_refund(char* name,int nums)
{
	refund[linenum3].name = name;
	refund[linenum3].nums = nums;
	linenum3++;
	printf("��ӳɹ����ǵô��̣����س��Լ���\n");
	return 0;
}
void search_num()
{
	for (int i = 0; i < linenum1; i++)
	{
		if (products[i].nums < 2)
		{
			search_sell(1, products[i].name);
			break;
		}
	}
}
void search_refund()
{
	for (int i = 0; i < linenum3; i++)
	{
		printf("%s %d %s\n", refund[i].name.c_str(), refund[i].nums, refund[i].date.c_str());
	}
	printf("���س��Լ���\n");
	getchar();
	getchar();
}
void search_min()
{
	for (int i = 0; i < linenum1; i++)
	{
		if (products[i].stored_nums < 2)
			printf("%s��治��\n", products[i].name.c_str());
	}
	printf("���س��Լ���\n");
	getchar();
	getchar();
}
void notice()
{
	for (int i = 0; i < linenum2; i++)
	{
		if (sell[i].nums > 10)
			printf("%s���ѽ���\n", sell[i].name.c_str());
	}
	printf("���س��Լ���\n");
	getchar();
	getchar();
}
bool cmp(product a, product b)
{
	return a.nums > b.nums;
}
void search_max(string tmpc)
{
	int n = 0;
	sort(sell, sell + linenum2, cmp);
	for (int i = 0; i < linenum2&&n<5; i++)
	{
		if (sell[i].date == tmpc)
		{
			printf("%s\n", sell[i].name.c_str());
			n++;
		}
	}
	printf("���س��Լ���\n");
	getchar();
	getchar();
}
void store_sell()
{
	FILE* fp;
	fp = fopen("sell.txt", "w");
	for (int i = 0; i < linenum2; i++)
	{
		fprintf(fp, "%s %d %s\n", sell[i].name.c_str(), sell[i].nums, sell[i].date.c_str());
	}
	fclose(fp);
	printf("��ӳɹ������س��Լ���\n");
	getchar();
	getchar();
}
void add_sell(char* info1,char* info2, int nums)
{
	sell[linenum2].name = info1;
	sell[linenum2].nums = nums;
	sell[linenum2++].date = info2;
	store_sell();
}
void change_pass(char* pass ,char* tmpc)
{
	for (int i = 0; i < linenum4; i++)
	{
		if (pass == guest[i].passwd)
			guest[i].passwd = tmpc;
	}
	store2();
}
int main()
{

	int a, b, flag1 = 0, flag = 0, c, d, e, n = 0, m = 0,f, num,g,h;
	char account[20], passwd[20], ch, i = 0;
	FILE* fp=NULL;
	fp = fopen("products.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum1++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum1++;
	fclose(fp);//get lines
	if ((fp = fopen("products.txt", "r")) == NULL)
	{
		fp = fopen("products.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("products.txt", "r");
		char products_name_tmp[50];
		for (int k = 0; k < linenum1; k++)
		{
			fscanf(fp, "%s %d", products_name_tmp, &products[k].stored_nums);
			products[k].name = products_name_tmp;
		}
		fclose(fp);
	}//store all infos into list

	fp = fopen("sell.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum2++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum2++;
	fclose(fp);//get lines
	if ((fp = fopen("sell.txt", "r")) == NULL)
	{
		fp = fopen("sell.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("sell.txt", "r");
		char products_name_tmp[50],products_date_tmp[50];
		for (int k = 0; k < linenum2; k++)
		{
			fscanf(fp, "%s %d %s", products_name_tmp, &sell[k].nums,products_date_tmp);
			sell[k].name = products_name_tmp;
			sell[k].date = products_date_tmp;
		}
		fclose(fp);
	}//store all infos into list

	fp = fopen("pass.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum4++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum4++;
	fclose(fp);//get lines
	if ((fp = fopen("pass.txt", "r")) == NULL)
	{
		fp = fopen("pass.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("pass.txt", "r");
		char name_tmp[50], passwd_tmp[50];
		for (int k = 0; k < linenum4; k++)
		{
			fscanf(fp, "%s %s", name_tmp, passwd_tmp);
			guest[k].name = name_tmp;
			guest[k].passwd = passwd_tmp;
		}
		fclose(fp);
	}//store all infos into list

	fp = fopen("refund.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum3++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum3++;
	fclose(fp);//get lines
	if ((fp = fopen("refund.txt", "r")) == NULL)
	{
		fp = fopen("refund.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("refund.txt", "r");
		char products_name_tmp[50],products_date_tmp[50];
		for (int k = 0; k < linenum3; k++)
		{
			fscanf(fp, "%s %d %s", products_name_tmp, &refund[k].nums,products_date_tmp);
			refund[k].name = products_name_tmp;
			refund[k].date = products_date_tmp;
		}
		fclose(fp);
	}//store all infos into list
	while(1)
	{
		printf("\n");
		printf("\n               ��ӭ��¼              \n");
		printf("          ���������ϵͳ           \n");
		printf("\n");
		printf("\n");
		printf("��ѡ����ݣ�\n");
		printf("1.����Ա\n");
		printf("2.Ա��\n");
		printf("0.�˳�\n");
		scanf("%d", &a);
		system("cls");
		switch (a)
		{
		case 1://admin
			printf("���������Ա�˺�:\n");
			getchar();
			gets_s(account);
			printf("����������:\n");
			while ((ch = getch()) != '\r')
			{
				if (ch != 8)
				{
					passwd[i] = ch;
					putchar('*');
					i++;
				}
				else
				{
					putchar('\b');
					putchar(' ');
					putchar('\b');
					i--;
				}
			}
			passwd[i] = '\0';
			flag1 = pass(account, passwd, a);
			if (flag1 == 0)
			{
				for (;;)
				{
					system("cls");
					printf("��¼ʧ�ܣ�\n");
					printf("�����������˺�\n");
					printf("�������˺ţ�\n");
					scanf("%s", &account);
					printf("���������룺\n");
					i = 0;
					while ((ch = getch()) != '\r')
					{
						if (ch != 8)
						{
							passwd[i] = ch;
							putchar('*');
							i++;
						}
						else
						{
							putchar('\b');
							putchar(' ');
							putchar('\b');
							i--;
						}
					}
					passwd[i] = '\0';
					system("cls");
					flag1 = pass(account, passwd, a);
					if (flag1 == 1)
						break;
				}
			}
			break;
		case 2://guest
			printf("�������˺�:\n");
			getchar();
			gets_s(account);
			printf("����������:\n");
			while ((ch = getch()) != '\r')
			{
				if (ch != 8)
				{
					passwd[i] = ch;
					putchar('*');
					i++;
				}
				else
				{
					putchar('\b');
					putchar(' ');
					putchar('\b');
					i--;
				}
			}
			passwd[i] = '\0';
			flag1 = pass(account, passwd, a);
			if (flag1 == 0)
			{
				for (;;)
				{
					system("cls");
					printf("��¼ʧ�ܣ�\n");
					printf("�����������˺�\n");
					printf("�������˺ţ�\n");
					scanf("%s", &account);
					printf("���������룺\n");
					i = 0;
					while ((ch = getch()) != '\r')
					{
						if (ch != 8)
						{
							passwd[i] = ch;
							putchar('*');
							i++;
						}
						else
						{
							putchar('\b');
							putchar(' ');
							putchar('\b');
							i--;
						}
					}
					passwd[i] = '\0';
					system("cls");
					flag1 = pass(account, passwd, a);
					if (flag1 == 1)
						break;
				}
			}
			for (;;)
			{
				system("cls");
				printf("��ѡ��:\n");
				printf("1.��¼������Ϣ\n");
				printf("2.�޸�����\n");
				printf("0.�˳�\n");
				scanf("%d", &i);
				switch (i)
				{
				case 1:
					char tmp[50], tmp2[50], tmpc[50];
					int nums;
					printf("������   ��Ʒ ���� ����\n");
					scanf("%s %d %s", tmp, &nums, tmp2);
					add_sell(tmp, tmp2, nums);
					break;
				case 2:
					printf("����ԭ����:\n");
					scanf("%s", tmp);
					printf("������Ҫ�޸ĵ�����:\n");
					scanf("%s", tmpc);
					change_pass(tmp, tmpc);
					break;
				case 0:
					printf("�ټ�����ӭ�´�ʹ��\n");
					exit(0);
				}
			}

		}
	} 
	while (1)
	{
	menu:
		system("cls");
		printf("\n��ѡ��Ҫ���еĲ�����\n");
		printf("1.��Ʒ��Ϣ����\n");
		printf("2.��Ա��Ϣ����\n");
		printf("3.������Ϣ����\n");
		printf("4.�˻�����\n");
		printf("5.��ѯ����\n");
		printf("0.�˳�\n");
		scanf("%d", &a);
		system("cls");
		product products_tmp;
		switch (a)
		{
		case 1:
			system("cls");
			printf("\n��ѡ��Ҫ���еĲ�����\n");
			printf("1.�����Ʒ��Ϣ\n");
			printf("2.��ѯ��Ʒ��Ϣ\n");
			printf("3.�޸���Ʒ��Ϣ\n");
			printf("4.ɾ����Ʒ��Ϣ\n");
			printf("5.����\n");
			printf("6.�����Ʒ��Ϣ\n");
			printf("0.����\n");
			scanf("%d", &c);
			system("cls");
			switch (c)
			{
			case 1://add
				char name_tmp[50];
				int nums;
				printf("�밴���¸�ʽ������Ϣ\n");
				printf("��Ʒ����  �����\n");
				scanf("%s %d", name_tmp, &nums);
				add(name_tmp,nums);
				getchar();
				getchar();
				break;
			case 2://search
				char tmpc[50];
				int x;
				printf("��������Ʒ����\n");
				scanf("%s", tmpc);
				search(tmpc);
				break;
			case 3://fix
				char name[50];
				printf("������Ҫ�޸ĵ���Ʒ��\n");
				scanf("%s", name);
				search(name);
				printf("��ѡ��Ҫ�޸ĵ���Ϣ\n");
				printf("1.��Ʒ��\n");
				printf("2.����\n");
				printf("0.����\n");
				scanf("%d", &x);
				printf("������\n");
				switch (x)
				{
				case 1:
				case 2:
					scanf("%s", tmpc);
					fix(x, tmpc,name);
					break;
				case 0:
					break;
				}
				break;
			case 4://delete
				printf("������Ҫɾ������Ʒ��\n");
				scanf("%s", name);
				search(name);
				printf("���س���ȷ��ɾ��\n");
				getchar();
				del(name);
				break;
			case 5://store
				printf("���س��Դ���\n");
				getchar();
				store();
				printf("���̳ɹ������س��Լ���\n");
				getchar();
				break;
			case 6://view
				printf("     ��Ʒ�б�         \n");
				printf("��Ʒ��       �������\n");
				view();
				break;
			case 0:
				goto menu;
			default:
				getchar();
				printf("�������������ѡ��\n");
				printf("��ѡ��Ҫ���еĲ�����\n");
				printf("1.�����Ʒ��Ϣ\n");
				printf("2.��ѯ��Ʒ��Ϣ\n");
				printf("3.�޸���Ʒ��Ϣ\n");
				printf("4.ɾ����Ʒ��Ϣ\n");
				printf("5.����\n");
				printf("6.�����Ʒ��Ϣ\n");
				printf("0.����\n");
				break;
			}
			break;
		case 2://��Ա��Ϣ
		menu2:
			printf("��ѡ��Ҫ���еĲ�����\n");
			printf("1.�����Ա��Ϣ\n");
			printf("2.��ѯ��Ա��Ϣ\n");
			printf("3.�޸���Ա��Ϣ\n");
			printf("4.ɾ����Ա��Ϣ\n");
			printf("5.����\n");
			printf("6.�����Ա��Ϣ\n");
			printf("0.����\n");
			scanf("%d", &h);
			system("cls");
			switch (h)
			{
				switch (c)
				{
				case 1://add
					char name_tmp[50];
					int nums;
					printf("�밴���¸�ʽ������Ϣ\n");
					printf("��Ʒ����  �����\n");
					scanf("%s %d", name_tmp, &nums);
					add2(name_tmp, nums);
					getchar();
					getchar();
					break;
				case 2://search
					char tmpc[50];
					int x;
					printf("��������Ա\n");
					scanf("%s", tmpc);
					search2(tmpc);
					break;
				case 3://fix
					char name[50];
					printf("������Ҫ�޸ĵ���Ա\n");
					scanf("%s", name);
					search(name);
					printf("��ѡ��Ҫ�޸ĵ���Ϣ\n");
					printf("1.����\n");
					printf("2.����\n");
					printf("0.����\n");
					scanf("%d", &x);
					printf("������\n");
					switch (x)
					{
					case 1:
					case 2:
						scanf("%s", tmpc);
						fix2(x, tmpc, name);
						break;
					case 0:
						break;
					}
					break;
				case 4://delete
					printf("������Ҫɾ������Ա\n");
					scanf("%s", name);
					search2(name);
					printf("���س���ȷ��ɾ��\n");
					getchar();
					del2(name);
					break;
				case 5://store
					printf("���س��Դ���\n");
					getchar();
					store2();
					printf("���̳ɹ������س��Լ���\n");
					getchar();
					break;
				case 6://view
					printf("��Ա     ����\n");
					view2();
					break;
				case 0:
					goto menu2;
				default:
					getchar();
					printf("�������������ѡ��\n");
					printf("��ѡ��Ҫ���еĲ�����\n");
					printf("1.�����Ա��Ϣ\n");
					printf("2.��ѯ��Ա��Ϣ\n");
					printf("3.�޸���Ա��Ϣ\n");
					printf("4.ɾ����Ա��Ϣ\n");
					printf("5.����\n");
					printf("6.�����Ա��Ϣ\n");
					printf("0.����\n");
					break;
				}
			}
			break;
		case 3://������Ϣ
			char tmpc[50];
			printf("��ѡ���ѯ��ʽ:\n");
			printf("1.��Ʒ��\n");
			printf("2.����\n");
			printf("3.ͳ���������\n");
			printf("0.����\n");
			scanf("%d", &e);
			if(e==0)
				goto menu;
			if (e == 3)
			{
				printf("����������:\n");
				scanf("%s", tmpc);
				sell_sum(tmpc);
			}
			else 
			{
				printf("������:\n");
				scanf("%s", tmpc);
				search_sell(e, tmpc);
			}
		case 4://�˻�
			printf("1.��¼�˻���Ϣ\n");
			printf("2.��ѯ�˻���Ϣ\n");
			printf("0.����\n");
			scanf("%d", &f);
			switch (f)
			{
			case 1:
				char name_tmp[50];
				int nums;
				printf("�밴���¸�ʽ������Ϣ\n");
				printf("��Ʒ����  �˻���\n");
				scanf("%s %d", name_tmp, &nums);
				add_refund(name_tmp, nums);
				break;
			case 2:
				search_refund();
				break;
			case 0:
				goto menu;
				break;
			}
			break;
		case 5://��ѯ
			char c;
			printf("1.��ѯ����ٵ�����\n");
			printf("2.�鿴����\n");
			printf("3.�鿴����\n");
			printf("0.����\n");
			scanf("%d", &g);
			
			switch (g)
			{
			case 1:
				search_min();
				printf("�Ƿ�Ҫ��ѯ���ۼ�¼��(Y/N)\n");
				scanf("%c", &c);
				if (c == 'N')
					goto menu;
				else
					search_num();
				break;
			case 2:
				notice();
				break;
			case 3:
				printf("����������:\n");
				scanf("%s", tmpc);
				search_max(tmpc);
				break;
			case 0:
				goto menu;
			}
			break;
		case 0:
			printf("�ټ�����ӭ�´�ʹ��\n");
			exit(0);
		}
	}
}