#include<iostream>
using namespace std;
#define N 10000
#include<stdlib.h>
#include<conio.h>
#include<string.h>
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
typedef struct NODE
{
	book data[1];
	struct NODE* next;
}NODE;
NODE* head;
NODE* tail;
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
	NODE* tmp;
	tmp = new(NODE);
	tmp = head;
	for (int i = 0; i < linenum; i++)
	{
		if (book_info.name ==  tmp->data->name.c_str()|| book_info.No == tmp->data->No)
		{
			flag = 1;
		}
		tmp = tmp->next;
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
	linenum = 0;
	head = new(NODE);
	tail = new(NODE);
	tail->next = NULL;
	head->next = tail;//create linklist
	char c;
	int n, flag = 0;
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
		char book_name_tmp[50], book_author_tmp[50], book_press_tmp[50];
		NODE* temp;
		for (int k = 0; k < linenum; k++)
		{
			temp = new(NODE);
			fscanf(fp, "%d %s %s %s %d %f %d", &Book_info[k].No, book_name_tmp, book_author_tmp, book_press_tmp, &Book_info[k].printdate, &Book_info[k].price, &Book_info[k].storednum);
			Book_info[k].name = book_name_tmp;
			Book_info[k].author = book_author_tmp;
			Book_info[k].press = book_press_tmp;
			*(temp->data) = Book_info[k];
			tail->next = temp;
			tail = temp;
		}
		fclose(fp);
		head = head->next->next;
	}
	flag = 0;
	NODE* tmp;
	tmp = new(NODE);
	tmp = head;
	for (int i = 0; i < linenum; i++)
	{
		if (info == tmp->data->press.c_str() || info == tmp->data->author.c_str() || info == tmp->data->name.c_str())
			flag = i + 1;
		tmp = tmp->next;
	}
	tmp = head;
	for (int i = 0; i < flag-1; i++)
		tmp = tmp->next;
	if (flag != 0)
		printf("%d %s %s %s %d %.2f %d\n", tmp->data->No,tmp->data->name.c_str(), tmp->data->author.c_str(), tmp->data->press.c_str(), tmp->data->printdate,tmp->data->price, tmp->data->storednum);
	else 
		printf("���޴���\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	return 0;
}
int search_book_no(int no)
{
	linenum = 0;
	head = new(NODE);
	tail = new(NODE);
	tail->next = NULL;
	head->next = tail;//create linklist
	char c;
	int n, flag = 0;
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
		char book_name_tmp[50], book_author_tmp[50], book_press_tmp[50];
		NODE* temp;
		for (int k = 0; k < linenum; k++)
		{
			temp = new(NODE);
			fscanf(fp, "%d %s %s %s %d %f %d", &Book_info[k].No, book_name_tmp, book_author_tmp, book_press_tmp, &Book_info[k].printdate, &Book_info[k].price, &Book_info[k].storednum);
			Book_info[k].name = book_name_tmp;
			Book_info[k].author = book_author_tmp;
			Book_info[k].press = book_press_tmp;
			*(temp->data) = Book_info[k];
			tail->next = temp;
			tail = temp;
		}
		fclose(fp);
		head = head->next->next;
	}
	flag = 0;
	NODE* tmp;
	tmp = new(NODE);
	tmp = head;
	for (int i = 0; i < linenum; i++)
	{
		if (no == tmp->data->No)
			flag = i + 1;
		tmp = tmp->next;
	}
	tmp = head;
	for (int i = 0; i < flag - 1; i++)
		tmp = tmp->next;
	if (flag != 0)
		printf("%d %s %s %s %d %.2f %d\n", tmp->data->No, tmp->data->name.c_str(), tmp->data->author.c_str(), tmp->data->press.c_str(), tmp->data->printdate, tmp->data->price, tmp->data->storednum);
	else
		printf("���޴���\n");
	printf("���س��Լ���\n");
	getchar();
	getchar();
	return 0;
}
int delete_book(string info)
{
	linenum = 0;
	head = new(NODE);
	tail = new(NODE);
	tail->next = NULL;
	head->next = tail;//create linklist
	char c;
	int n, flag = 0;
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
		char book_name_tmp[50], book_author_tmp[50], book_press_tmp[50];
		NODE* temp;
		for (int k = 0; k < linenum; k++)
		{
			temp = new(NODE);
			fscanf(fp, "%d %s %s %s %d %f %d", &Book_info[k].No, book_name_tmp, book_author_tmp, book_press_tmp, &Book_info[k].printdate, &Book_info[k].price, &Book_info[k].storednum);
			Book_info[k].name = book_name_tmp;
			Book_info[k].author = book_author_tmp;
			Book_info[k].press = book_press_tmp;
			*(temp->data) = Book_info[k];
			tail->next = temp;
			tail = temp;
		}
		fclose(fp);
		head = head->next->next;
	}
	if ((fp = fopen("books.txt", "r")) == NULL)
	{
		fp = fopen("books.txt", "r");
		fclose(fp);
	}
	else
	{
		NODE* p1, * p2;
		int flag = 0, flag_ = 0;
		NODE* tmp;
		tmp = new(NODE);
		p1 = new(NODE);
		p2 = new(NODE);
		tmp = head;
		for (int i = 0; i < linenum; i++)
		{
			if (info == tmp->data->press.c_str() || info == tmp->data->author.c_str() || info == tmp->data->name.c_str())
				flag = i + 1;
			tmp = tmp->next;
		}
		tmp = head;
		for (int i = 0; i < flag - 1; i++)
			tmp = tmp->next;
		p1 = head;
		p2 = tmp->next;
		if (flag != 0)
		{
			fp = fopen("books.txt", "w");
			for (;;)
			{
				if (p1->data->No == tmp->data->No)
					break;
				fprintf(fp, "%d %s %s %s %d %.2f %d\n", p1->data->No, p1->data->name.c_str(), p1->data->author.c_str(), p1->data->press.c_str(), p1->data->printdate, p1->data->price, p1->data->storednum);
				p1 = p1->next;
			}
			for (int i = 0; i < linenum - flag; i++)
			{
				fprintf(fp, "%d %s %s %s %d %.2f %d\n", p2->data->No, p2->data->name.c_str(), p2->data->author.c_str(), p2->data->press.c_str(), p2->data->printdate, p2->data->price, p2->data->storednum);
				p2 = p2->next;
			}
			printf("ɾ���ɹ�\n");
		}
		else
			printf("���޴��飡\n");
	}
	fclose(fp);
	printf("���س��Լ���\n");
	getchar();
	getchar();
	return 0;
}
int delete_book_no(int no)
{
	linenum = 0;
	head = new(NODE);
	tail = new(NODE);
	tail->next = NULL;
	head->next = tail;//create linklist
	char c;
	int n, flag = 0;
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
		char book_name_tmp[50], book_author_tmp[50], book_press_tmp[50];
		NODE* temp;
		for (int k = 0; k < linenum; k++)
		{
			temp = new(NODE);
			fscanf(fp, "%d %s %s %s %d %f %d", &Book_info[k].No, book_name_tmp, book_author_tmp, book_press_tmp, &Book_info[k].printdate, &Book_info[k].price, &Book_info[k].storednum);
			Book_info[k].name = book_name_tmp;
			Book_info[k].author = book_author_tmp;
			Book_info[k].press = book_press_tmp;
			*(temp->data) = Book_info[k];
			tail->next = temp;
			tail = temp;
		}
		fclose(fp);
		head = head->next->next;
	}
	if ((fp = fopen("books.txt", "r")) == NULL)
	{
		fp = fopen("books.txt", "r");
		fclose(fp);
	}
	else
	{
		NODE * p1, * p2;
		int flag = 0,flag_=0;
		NODE* tmp;
		tmp = new(NODE);
		p1 = new(NODE);
		p2 = new(NODE);
		tmp = head;
		for (int i = 0; i < linenum; i++)
		{
			if (no == tmp->data->No)
				flag = i + 1;
			tmp = tmp->next;
		}
		tmp = head;
		for (int i = 0; i < flag-1; i++)
			tmp = tmp->next;
		p1 = head;
		p2 = tmp->next;
		if (flag != 0)
		{
			fp = fopen("books.txt", "w");
			for(;;)
			{
				if (p1->data->No == tmp->data->No)
					break;
					fprintf(fp, "%d %s %s %s %d %.2f %d\n", p1->data->No, p1->data->name.c_str(), p1->data->author.c_str(), p1->data->press.c_str(), p1->data->printdate, p1->data->price, p1->data->storednum);
					p1 = p1->next;
			}
			for(int i=0;i<linenum-flag;i++)
			{
				fprintf(fp, "%d %s %s %s %d %.2f %d\n", p2->data->No, p2->data->name.c_str(), p2->data->author.c_str(), p2->data->press.c_str(), p2->data->printdate, p2->data->price, p2->data->storednum);
				p2 = p2->next;
			} 
			printf("ɾ���ɹ�\n");
		}
		else
			printf("���޴��飡\n");
	}
	fclose(fp);
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
	NODE* tmp,*p1;
	tmp = new(NODE);
	tmp = head;
	p1 = new(NODE);
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
		if (info == tmp->data->press.c_str() || info == tmp->data->author.c_str() || info == tmp->data->name.c_str())
			flag = i;
	for (int i = 0; i < flag-1; i++)
		tmp = tmp->next;
	p1 = head;
	switch (x)
	{
	case 2://name
		tmp->next->data->name = info;
		break;
	case 3://author
		tmp->next->data->author= info;
		break;
	case 4://press
		tmp->next->data->press = info;
		break;
	}
	fp = fopen("books.txt", "w");
	for(int i=0;i<linenum;i++)
	{
		fprintf(fp, "%d %s %s %s %d %.2f %d\n", p1->data->No, p1->data->name.c_str(), p1->data->author.c_str(), p1->data->press.c_str(), p1->data->printdate, p1->data->price, p1->data->storednum);
		p1 = p1->next;
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
	NODE* tmp, * p1;
	tmp = new(NODE);
	tmp = head;
	p1 = new(NODE);
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
		if (no==tmp->data->No)
			flag = i;
	for (int i = 0; i < flag - 1; i++)
		tmp = tmp->next;
	p1 = head;
	tmp->next->data->No = no;
	fp = fopen("books.txt", "w");
	for (int i = 0; i < linenum; i++)
	{
		fprintf(fp, "%d %s %s %s %d %.2f %d\n", p1->data->No, p1->data->name.c_str(), p1->data->author.c_str(), p1->data->press.c_str(), p1->data->printdate, p1->data->price, p1->data->storednum);
		p1 = p1->next;
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
	head = new(NODE);
	tail = new(NODE);
	tail->next = NULL;
	head->next = tail;//create linklist
	char account[20],passwd[20], c,ch;
	int n,flag=0,flag1=0;
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
		char book_name_tmp[50], book_author_tmp[50], book_press_tmp[50];
		NODE* temp;
		for(int k=0;k<linenum;k++)
		{
			temp = new(NODE);
			fscanf(fp, "%d %s %s %s %d %f %d", &Book_info[k].No, book_name_tmp, book_author_tmp, book_press_tmp, &Book_info[k].printdate,&Book_info[k].price, &Book_info[k].storednum);
			Book_info[k].name = book_name_tmp;
			Book_info[k].author = book_author_tmp;
			Book_info[k].press = book_press_tmp;
			*(temp->data) = Book_info[k];
			tail->next = temp;
			tail = temp;
		}
		fclose(fp);
			head = head->next->next;
		//all books info visit from head
	}
	for (;;)
	{

		printf("��ѡ�������\n");
		printf("1.��¼\n");
		printf("2.�˳�\n");
		scanf("%d", &n);
		int i = 0;
		switch (n)
		{
		case 1:
			printf("�������˺ţ�\n");
			getchar();
			gets_s(account);
			printf("���������룺\n");
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
			flag1 = login(account, passwd);
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