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
	int nums;//销售数量or退货数量
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
		printf("添加失败！此商品已存在\n");
		return 0;
	}
	products[linenum1].name =name;
	products[linenum1].stored_nums =nums;
	linenum1++;
	printf("添加成功！记得存盘！按回车以继续\n");
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
		printf("查无此商品\n");
	printf("按回车以继续\n");
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
	printf("修改成功！记得存盘！\n");
	printf("按回车以继续\n");
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
	printf("删除成功！记得存盘！\n");
	printf("按回车以继续\n");
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
	printf("按回车以继续\n");
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
		printf("添加失败！此人已存在\n");
		return 0;
	}
	guest[linenum4].name = name;
	guest[linenum4].passwd = nums;
	linenum4++;
	printf("添加成功！记得存盘！按回车以继续\n");
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
		printf("查无此人\n");
	printf("按回车以继续\n");
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
	printf("修改成功！记得存盘！\n");
	printf("按回车以继续\n");
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
	printf("删除成功！记得存盘！\n");
	printf("按回车以继续\n");
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
	printf("按回车以继续\n");
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
	printf("按回车以继续\n");
	getchar();
	getchar();
}
void sell_sum(char* date)
{
	int sum;
	printf("%s销售情况\n", date);
	for (int i = 0; i < linenum1; i++)
	{
		sum = 0;
		for (int j = 0; j < linenum2; j++)
		{
			if (products[i].name == sell[j].name&&date==sell[j].date)
				sum+=sell[j].nums;
		}
		printf("%s销售了%d件\n", products[i].name.c_str(), sum);
	}
	printf("按回车以继续\n");
	getchar();
	getchar();
}
int add_refund(char* name,int nums)
{
	refund[linenum3].name = name;
	refund[linenum3].nums = nums;
	linenum3++;
	printf("添加成功！记得存盘！按回车以继续\n");
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
	printf("按回车以继续\n");
	getchar();
	getchar();
}
void search_min()
{
	for (int i = 0; i < linenum1; i++)
	{
		if (products[i].stored_nums < 2)
			printf("%s库存不足\n", products[i].name.c_str());
	}
	printf("按回车以继续\n");
	getchar();
	getchar();
}
void notice()
{
	for (int i = 0; i < linenum2; i++)
	{
		if (sell[i].nums > 10)
			printf("%s提醒进货\n", sell[i].name.c_str());
	}
	printf("按回车以继续\n");
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
	printf("按回车以继续\n");
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
	printf("添加成功！按回车以继续\n");
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
		printf("\n               欢迎登录              \n");
		printf("          五金店库存管理系统           \n");
		printf("\n");
		printf("\n");
		printf("请选择身份：\n");
		printf("1.管理员\n");
		printf("2.员工\n");
		printf("0.退出\n");
		scanf("%d", &a);
		system("cls");
		switch (a)
		{
		case 1://admin
			printf("请输入管理员账号:\n");
			getchar();
			gets_s(account);
			printf("请输入密码:\n");
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
					printf("登录失败！\n");
					printf("请重新输入账号\n");
					printf("请输入账号：\n");
					scanf("%s", &account);
					printf("请输入密码：\n");
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
			printf("请输入账号:\n");
			getchar();
			gets_s(account);
			printf("请输入密码:\n");
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
					printf("登录失败！\n");
					printf("请重新输入账号\n");
					printf("请输入账号：\n");
					scanf("%s", &account);
					printf("请输入密码：\n");
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
				printf("请选择:\n");
				printf("1.记录销售信息\n");
				printf("2.修改密码\n");
				printf("0.退出\n");
				scanf("%d", &i);
				switch (i)
				{
				case 1:
					char tmp[50], tmp2[50], tmpc[50];
					int nums;
					printf("请输入   商品 数量 日期\n");
					scanf("%s %d %s", tmp, &nums, tmp2);
					add_sell(tmp, tmp2, nums);
					break;
				case 2:
					printf("输入原密码:\n");
					scanf("%s", tmp);
					printf("请输入要修改的密码:\n");
					scanf("%s", tmpc);
					change_pass(tmp, tmpc);
					break;
				case 0:
					printf("再见，欢迎下次使用\n");
					exit(0);
				}
			}

		}
	} 
	while (1)
	{
	menu:
		system("cls");
		printf("\n请选择要进行的操作：\n");
		printf("1.产品信息管理\n");
		printf("2.人员信息管理\n");
		printf("3.销售信息管理\n");
		printf("4.退货管理\n");
		printf("5.查询功能\n");
		printf("0.退出\n");
		scanf("%d", &a);
		system("cls");
		product products_tmp;
		switch (a)
		{
		case 1:
			system("cls");
			printf("\n请选择要进行的操作：\n");
			printf("1.添加商品信息\n");
			printf("2.查询商品信息\n");
			printf("3.修改商品信息\n");
			printf("4.删除商品信息\n");
			printf("5.存盘\n");
			printf("6.浏览商品信息\n");
			printf("0.返回\n");
			scanf("%d", &c);
			system("cls");
			switch (c)
			{
			case 1://add
				char name_tmp[50];
				int nums;
				printf("请按如下格式输入信息\n");
				printf("商品名称  库存量\n");
				scanf("%s %d", name_tmp, &nums);
				add(name_tmp,nums);
				getchar();
				getchar();
				break;
			case 2://search
				char tmpc[50];
				int x;
				printf("请输入商品名称\n");
				scanf("%s", tmpc);
				search(tmpc);
				break;
			case 3://fix
				char name[50];
				printf("请输入要修改的商品名\n");
				scanf("%s", name);
				search(name);
				printf("请选择要修改的信息\n");
				printf("1.商品名\n");
				printf("2.数量\n");
				printf("0.返回\n");
				scanf("%d", &x);
				printf("请输入\n");
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
				printf("请输入要删除的商品名\n");
				scanf("%s", name);
				search(name);
				printf("按回车以确认删除\n");
				getchar();
				del(name);
				break;
			case 5://store
				printf("按回车以存盘\n");
				getchar();
				store();
				printf("存盘成功！按回车以继续\n");
				getchar();
				break;
			case 6://view
				printf("     商品列表         \n");
				printf("商品名       库存数量\n");
				view();
				break;
			case 0:
				goto menu;
			default:
				getchar();
				printf("输入错误，请重新选择\n");
				printf("请选择要进行的操作：\n");
				printf("1.添加商品信息\n");
				printf("2.查询商品信息\n");
				printf("3.修改商品信息\n");
				printf("4.删除商品信息\n");
				printf("5.存盘\n");
				printf("6.浏览商品信息\n");
				printf("0.返回\n");
				break;
			}
			break;
		case 2://人员信息
		menu2:
			printf("请选择要进行的操作：\n");
			printf("1.添加人员信息\n");
			printf("2.查询人员信息\n");
			printf("3.修改人员信息\n");
			printf("4.删除人员信息\n");
			printf("5.存盘\n");
			printf("6.浏览人员信息\n");
			printf("0.返回\n");
			scanf("%d", &h);
			system("cls");
			switch (h)
			{
				switch (c)
				{
				case 1://add
					char name_tmp[50];
					int nums;
					printf("请按如下格式输入信息\n");
					printf("商品名称  库存量\n");
					scanf("%s %d", name_tmp, &nums);
					add2(name_tmp, nums);
					getchar();
					getchar();
					break;
				case 2://search
					char tmpc[50];
					int x;
					printf("请输入人员\n");
					scanf("%s", tmpc);
					search2(tmpc);
					break;
				case 3://fix
					char name[50];
					printf("请输入要修改的人员\n");
					scanf("%s", name);
					search(name);
					printf("请选择要修改的信息\n");
					printf("1.人名\n");
					printf("2.密码\n");
					printf("0.返回\n");
					scanf("%d", &x);
					printf("请输入\n");
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
					printf("请输入要删除的人员\n");
					scanf("%s", name);
					search2(name);
					printf("按回车以确认删除\n");
					getchar();
					del2(name);
					break;
				case 5://store
					printf("按回车以存盘\n");
					getchar();
					store2();
					printf("存盘成功！按回车以继续\n");
					getchar();
					break;
				case 6://view
					printf("人员     密码\n");
					view2();
					break;
				case 0:
					goto menu2;
				default:
					getchar();
					printf("输入错误，请重新选择\n");
					printf("请选择要进行的操作：\n");
					printf("1.添加人员信息\n");
					printf("2.查询人员信息\n");
					printf("3.修改人员信息\n");
					printf("4.删除人员信息\n");
					printf("5.存盘\n");
					printf("6.浏览人员信息\n");
					printf("0.返回\n");
					break;
				}
			}
			break;
		case 3://销售信息
			char tmpc[50];
			printf("请选择查询方式:\n");
			printf("1.商品名\n");
			printf("2.日期\n");
			printf("3.统计销售情况\n");
			printf("0.返回\n");
			scanf("%d", &e);
			if(e==0)
				goto menu;
			if (e == 3)
			{
				printf("请输入日期:\n");
				scanf("%s", tmpc);
				sell_sum(tmpc);
			}
			else 
			{
				printf("请输入:\n");
				scanf("%s", tmpc);
				search_sell(e, tmpc);
			}
		case 4://退货
			printf("1.记录退货信息\n");
			printf("2.查询退货信息\n");
			printf("0.返回\n");
			scanf("%d", &f);
			switch (f)
			{
			case 1:
				char name_tmp[50];
				int nums;
				printf("请按如下格式输入信息\n");
				printf("商品名称  退货量\n");
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
		case 5://查询
			char c;
			printf("1.查询库存少的五金件\n");
			printf("2.查看提醒\n");
			printf("3.查看热销\n");
			printf("0.返回\n");
			scanf("%d", &g);
			
			switch (g)
			{
			case 1:
				search_min();
				printf("是否要查询销售记录？(Y/N)\n");
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
				printf("请输入日期:\n");
				scanf("%s", tmpc);
				search_max(tmpc);
				break;
			case 0:
				goto menu;
			}
			break;
		case 0:
			printf("再见，欢迎下次使用\n");
			exit(0);
		}
	}
}