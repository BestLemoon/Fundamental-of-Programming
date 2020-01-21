#include<iostream>
using namespace std;
#define N 10000
#include<stdlib.h>
int linenum = 0;
struct book
{
	int No;
	string name;
	string author;
	string press;
	int printdate;
	float price;
	int storednum;
}Book_info[N];
//read all books information into book info

int login(char account[], char passwd[])
{
	if (strcmp(account,"admin")==0&&strcmp(passwd,"password")==0)
		return 1;//Right 
	return 0;//Wrong
}

int add_book(book book_info)
{
	int flag = 0;
	FILE* fp = NULL;
	fp = fopen("books.txt", "a");
	for (int i = 0; i < linenum; i++)
	{
		if (book_info.author == Book_info[i].author || book_info.No == Book_info[i].No)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("���ʧ�ܣ������Ѵ���\n");
		return 0;
	}
	fprintf(fp, "%d %s %s %s %d %.2f %d\n", book_info.No, book_info.name.c_str(), book_info.author.c_str(), book_info.press.c_str(), book_info.printdate, book_info.price, book_info.storednum);
	fclose(fp);
	printf("��ӳɹ�������س��Լ���\n");
	return 0;
}

int search_book(string info)
{
	int flag = 0;
	for (int i = 0; i < linenum; i++)
		if (info == Book_info[i].press||info==Book_info[i].author||info==Book_info[i].name)
			flag = i+1;
	if (flag != 0)
	printf("%d %s %s %s %d %.2f %d\n", Book_info[flag-1].No, Book_info[flag-1].name.c_str(), Book_info[flag-1].author.c_str(), Book_info[flag-1].press.c_str(), Book_info[flag-1].printdate, Book_info[flag-1].price, Book_info[flag-1].storednum);
	else 
		printf("���޴���\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	return 0;
}
int search_book_no(int no)
{
	int flag=0;
	for (int i = 0; i < linenum; i++)
		if (no == Book_info[i].No)
			flag = i+1;
	if (flag!=0)
		printf("%d %s %s %s %d %.2f %d\n", Book_info[flag-1].No, Book_info[flag-1].name.c_str(), Book_info[flag-1].author.c_str(), Book_info[flag-1].press.c_str(), Book_info[flag-1].printdate, Book_info[flag-1].price, Book_info[flag-1].storednum);
	else
		printf("���޴���");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	return 0;
}
int delete_book(string info)
{
	linenum=0;
	int flag,c;
	FILE* fp = NULL;
	fp = fopen("books.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum++;
	fclose(fp);
	if ((fp = fopen("books.txt", "r")) == NULL)
	{
		fp = fopen("books.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("books.txt", "r");
		int k = 0;
		char book_name_tmp[50], book_author_tmp[50], book_press_tmp[50];
		for (int k = 0; k < linenum; k++)
		{
			fscanf(fp, "%d %s %s %s %d %f %d", &Book_info[k].No, book_name_tmp, book_author_tmp, book_press_tmp, &Book_info[k].printdate, &Book_info[k].price, &Book_info[k].storednum);
			Book_info[k].name = book_name_tmp;
			Book_info[k].author = book_author_tmp;
			Book_info[k].press = book_press_tmp;
		}
		fclose(fp);
	}
	for (int i = 0; i < linenum; i++)
		if (info == Book_info[i].press || info == Book_info[i].author || info == Book_info[i].name)
			flag = i+1;
	fp = fopen("books.txt", "w");
	if (flag != 0)
	{
		for (int i = 0; i < flag-1;i++)//book is in book_info[flag-1]  0~flag-2  and  flag~linenum-1 read all books first then divide them into two parts finally fprint the two parts
		{
			fprintf(fp, "%d %s %s %s %d %.2f %d\n", Book_info[i].No, Book_info[i].name.c_str(), Book_info[i].author.c_str(), Book_info[i].press.c_str(), Book_info[i].printdate, Book_info[i].price, Book_info[i].storednum);
		}
		for(int i=flag;i<linenum;i++)
		{ 
			fprintf(fp, "%d %s %s %s %d %.2f %d\n", Book_info[i].No, Book_info[i].name.c_str(), Book_info[i].author.c_str(), Book_info[i].press.c_str(), Book_info[i].printdate, Book_info[i].price, Book_info[i].storednum);
		}
	}
	fclose(fp);
	printf("ɾ���ɹ�\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	return 0;
}
int delete_book_no(int no)
{
	linenum = 0;
	int flag, c;
	FILE* fp = NULL;
	fp = fopen("books.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum++;
	fclose(fp);
	if ((fp = fopen("books.txt", "r")) == NULL)
	{
		fp = fopen("books.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("books.txt", "r");
		int k = 0;
		char book_name_tmp[50], book_author_tmp[50], book_press_tmp[50];
		for (int k = 0; k < linenum; k++)
		{
			fscanf(fp, "%d %s %s %s %d %f %d", &Book_info[k].No, book_name_tmp, book_author_tmp, book_press_tmp, &Book_info[k].printdate, &Book_info[k].price, &Book_info[k].storednum);
			Book_info[k].name = book_name_tmp;
			Book_info[k].author = book_author_tmp;
			Book_info[k].press = book_press_tmp;
		}
		fclose(fp);
	}
	for (int i = 0; i < linenum; i++)
		if (no == Book_info[i].No)
			flag = i + 1;
	fp = fopen("books.txt", "w");
	if (flag != 0)
	{
		for (int i = 0; i < flag - 1; i++)//book is in book_info[flag-1]  0~flag-2  and  flag~linenum-1 read all books first then divide them into two parts finally fprint the two parts
		{
			fprintf(fp, "%d %s %s %s %d %.2f %d\n", Book_info[i].No, Book_info[i].name.c_str(), Book_info[i].author.c_str(), Book_info[i].press.c_str(), Book_info[i].printdate, Book_info[i].price, Book_info[i].storednum);
		}
		for (int i = flag; i < linenum; i++)
		{
			fprintf(fp, "%d %s %s %s %d %.2f %d\n", Book_info[i].No, Book_info[i].name.c_str(), Book_info[i].author.c_str(), Book_info[i].press.c_str(), Book_info[i].printdate, Book_info[i].price, Book_info[i].storednum);
		}
	}
	fclose(fp);
	printf("ɾ���ɹ�\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	return 0;
}
int fix_error(int x,string info)
{
	int flag = 0;
	linenum = 0;
	int c;
	FILE* fp = NULL;
	fp = fopen("books.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum++;
	fclose(fp);
	for (int i = 0; i < linenum; i++)
		if (info == Book_info[i].press || info == Book_info[i].author || info == Book_info[i].name)
			flag = i;
	switch (x)
	{
	case 2://name
		Book_info[flag].name = info;
		break;
	case 3://author
		Book_info[flag].author = info;
		break;
	case 4://press
		Book_info[flag].press = info;
		break;
	}
	fp = fopen("books.txt", "w");
	for (int i = 0; i < linenum-1; i++)
	{
		fprintf(fp, "%d %s %s %s %d %.2f %d\n", Book_info[i].No, Book_info[i].name.c_str(), Book_info[i].author.c_str(), Book_info[i].press.c_str(), Book_info[i].printdate, Book_info[i].price, Book_info[i].storednum);
	}
	fclose(fp);
	printf("�޸ĳɹ���\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	//Search the book first then choose what infomation to change then change the information
	return 0;
}
int fix_error_no(int no)
{
	int flag = 0; 
	linenum = 0;
	int c;
	FILE* fp = NULL;
	fp = fopen("books.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum++;
	fclose(fp);
	for (int i = 0; i < linenum; i++)
		if (no == Book_info[i].No)
			flag = i;
	Book_info[flag].No = no;
	fp = fopen("books.txt", "w");
	for (int i = 0; i < linenum; i++)
	{
		fprintf(fp, "%d %s %s %s %d %.2f %d\n", Book_info[i].No, Book_info[i].name.c_str(), Book_info[i].author.c_str(), Book_info[i].press.c_str(), Book_info[i].printdate, Book_info[i].price, Book_info[i].storednum);
	}
	fclose(fp);
	printf("�޸ĳɹ���\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	//Search the book first then choose what infomation to change then change the information
	return 0;
}
int main()
{
	char account[100],passwd[100], c;
	int flag1=0,n,flag=0,count=0;
	FILE *fp=NULL;
	fp = fopen("books.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			linenum++;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag)
		linenum++;
	fclose(fp);
	if ((fp = fopen("books.txt", "r")) == NULL)
	{
		fp = fopen("books.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("books.txt", "r");
		int k = 0;
		char book_name_tmp[50], book_author_tmp[50], book_press_tmp[50];
		for(int k=0;k<linenum;k++)
		{
			fscanf(fp, "%d %s %s %s %d %f %d", &Book_info[k].No, book_name_tmp, book_author_tmp, book_press_tmp, &Book_info[k].printdate,&Book_info[k].price, &Book_info[k].storednum);
			Book_info[k].name = book_name_tmp;
			Book_info[k].author = book_author_tmp;
			Book_info[k].press = book_press_tmp;
		}
		fclose(fp);
	}
	for (;;)
	{
		printf("quu..__\n");
		printf(" $$$b  `---.__\n");
		printf("  \"$$b        `--.                          ___.---uuudP\n");
		printf("   `$$b           `.__.------.__     __.---'      $$$$\"             .\n");
		printf("	 \"$b          -'            `-.-'            $$$\"              .'|\n");
		printf("	   \".                                       d$\"             _.'  |\n");
		printf("	 `.   /                              ...\"             .'     |\n");
		printf("	   `./                           ..::-'            _.'       | \n");
		printf("		/                         .:::-'            .-'         .'\n");
		printf("	   :                          ::''/          _.'            |\n");
		printf("	  .' .-.             .-.           `.      .'               | \n");
		printf("	  .' .-.             .-.           `.      .'               | \n");
		printf("	  : /'$$|           .@\"$/           `.   .'              _.-'\n");
		printf("	 .'|$u$$|          |$$,$$|           |  <            _.-'\n");
		printf("	 | `:$$:'          :$$$$$:           `.  `.       .-'\n");
		printf("	 :                  `\"--'             |    `-.     \n");
		printf("	:##.       ==             .###.       `.      `.    `\n");
		printf("	|##:                      :###:        |        >     > \n");
		printf("	|#'     `..'`..'          `###'        x:      /     /\n");
		printf("	 /                                   xXX|     /    ./ \n");
		printf("	  /                               xXXX'|    /   ./\n");
		printf("	  /`-.                                  `.  /   /\n");
		printf("	 :    `-  ...........,                   | /  .'\n");
		printf("	 |         ``:::::::'       .            |<    `.\n");
		printf("	 |             ```          |           x| / `.:``.\n");
		printf("	 |                         .'    /'   xXX|  `:`M`M':.\n");
		printf("	 |    |                    ;    /:' xXXX'|  -'MMMMM:'\n");
		printf("	 `.  .'                   :    /:'       |-'MMMM.-'\n");
		printf("	  |  |                   .'   /'        .'MMM.-'\n");
		printf("	  `'`'                   :  ,'          |MMM<\n");
		printf("		|                     `'            |tbap\n");
		printf("		 /                                  :MM.-'\n");
		printf("		  /                 |              .''\n");
		printf("		   /.               `.            / \n");
		printf("			/     .:::::::.. :           / \n");
		printf("		   |     .:::::::::::`.         / \n");
		printf("		   |   .:::------------/       / \n");
		printf("		  /   .''               >::'  /\n");
		printf("		  `',:                 :    .'\n");
		printf("							   `:.:'\n");
		printf("               ��ӭ��¼              \n");
		printf("            ͼ����Ϣ����ϵͳ           \n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("��ѡ�������\n");
		printf("1.��¼\n");
		printf("2.�˳�\n");
		scanf("%d", &n);
		int i = 0;
		switch (n)
		{
		case 1:
			printf("�������˺ţ�");
			getchar();
			gets_s(account);
			printf("���������룺");
			gets_s(passwd);
			flag1 = login(account, passwd);
			if (flag1 == 0)
			{
				for (;;)
				{
					system("cls");
					printf("��¼ʧ�ܣ�\n");
					printf("�����������˺�\n");
					printf("�������˺ţ�");
					scanf("%s", &account);
					printf("���������룺");
					scanf("%s", &passwd);
					system("cls");
					flag1 = login(account, passwd);
					if (flag1 == 1)
						break;
				}
			}
			break;
		case 2:exit(0);
		default:
			printf("�������������ѡ��\n");
		}
		if (flag1 == 1)
			break;
	}//login

	for (;;)
	{
		system("cls");
		printf("��ѡ��Ҫ���еĲ�����\n");
		printf("1.���ͼ����Ϣ\n");
		printf("2.��ѯͼ����Ϣ\n");
		printf("3.ɾ��ͼ��\n");
		printf("4.�޸�ͼ����Ϣ\n");
		printf("0.�˳�\n");
		book book_info_tmp;
		scanf("%d", &n);
		system("cls");
		switch (n)
		{
		case 1://add
			printf("�밴���¸�ʽ������Ϣ\n");
			printf("��� ���� ���� ������ �������� �۸� �����\n");
			scanf("%d %s %s %s %d %f %d", &book_info_tmp.No, book_info_tmp.name.c_str(), book_info_tmp.author.c_str(), book_info_tmp.press.c_str(), &book_info_tmp.printdate, &book_info_tmp.price, &book_info_tmp.storednum);
			add_book(book_info_tmp);
			getchar();
			getchar();
			break;
		case 2: //search
			int x,tmp;
			char tmpc[100];
			printf("��ѡ���ѯ��ʽ\n");
			printf("1.���\n");
			printf("2.����\n");
			printf("3.����\n");
			printf("4.������\n");
			printf("0.����\n");
			scanf("%d", &x);
			printf("������\n");
			switch (x)
			{
			case 1:
				scanf("%d", &tmp);
				search_book_no(tmp);
				break;
			case 2:
			case 3:
			case 4:
				scanf("%s", tmpc);
				search_book(tmpc);
				break;
			case 0:
				break;
			}
			break;
		case 3://delete
			printf("��ѡ��ɾ����ʽ\n");
			printf("1.���\n");
			printf("2.����\n");
			printf("3.����\n");
			printf("4.������\n");
			printf("0.����\n");
			scanf("%d", &x);
			printf("������\n");
			switch (x)
			{
			case 1:
				scanf("%d", &tmp);
				delete_book_no(tmp);
				break;
			case 2:
			case 3:
			case 4:
				scanf("%s", tmpc);
				delete_book(tmpc);
				break;
			case 0:
				break;
			}
			break;
		case 4://fix error
			char name[50];
			printf("������Ҫ�޸ĵ�����\n");
			scanf("%s", name);
			search_book(name);
			printf("��ѡ��Ҫ�޸ĵ���Ϣ\n");
			printf("1.���\n");
			printf("2.����\n");
			printf("3.����\n");
			printf("4.������\n");
			printf("0.����\n");
			scanf("%d", &x);
			printf("������\n");
			switch (x)
			{
			case 1:
				scanf("%d", &tmp);
				fix_error_no(tmp);
				break;
			case 2:
				scanf("%s", tmpc);
				fix_error(x,tmpc);
				break;
			case 3:
				scanf("%s", tmpc);
				fix_error(x,tmpc);
				break;
			case 4:
				scanf("%s", tmpc);
				fix_error(x,tmpc);
				break;
			case 0:
				break;
			}
			break;
		case 0:
			printf("�ټ�����ӭ�´�ʹ��\n");
			exit(0);
		default:printf("�������������ѡ��\n"); 
			printf("��ѡ��Ҫ���еĲ�����\n");
			printf("1.���ͼ����Ϣ\n");
			printf("2.���������ѯͼ����Ϣ\n");
			printf("3.ɾ��ͼ��\n");
			printf("4.�޸�ͼ����Ϣ\n");
			printf("0.�˳�\n");
		}
	}//main menu
	return 0;
}