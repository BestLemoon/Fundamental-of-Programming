#include<stdio.h>
#include<iostream>
using namespace std;
#include<string.h>
#include<conio.h>
#include<Windows.h>
#define N 10000
int linenum = 0;
struct songs
{
	string No;
	string song_name;
	string singer_name;
	string tag;
}Songs_info[N];
int login(char account[], char passwd[])
{
	if (strcmp(account, "admin") == 0 && strcmp(passwd, "password") == 0)
		return 1;//Right 
	return 0;//Wrong
}
int add(songs song_info)
{
	int flag = 0;
	for (int i = 0; i < linenum; i++)
	{
		if (Songs_info[i].No==song_info.No)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("添加失败！此书已存在\n");
		return 0;
	}
	Songs_info[linenum].No = song_info.No.c_str();
	Songs_info[linenum].song_name = song_info.song_name.c_str();
	Songs_info[linenum].singer_name = song_info.singer_name.c_str();
	Songs_info[linenum].tag = song_info.tag.c_str();
	linenum++;
	printf("添加成功！记得存盘！按回车以继续\n");
	return 0;
}
int search(string info)
{
	int flag = 0;
	for (int i = 0; i < linenum; i++)
	{
		if (Songs_info[i].singer_name == info || Songs_info[i].song_name == info || Songs_info[i].tag == info)
		{
			printf("%s %s %s %s\n", Songs_info[i].No.c_str(), Songs_info[i].song_name.c_str(), Songs_info[i].singer_name.c_str(), Songs_info[i].tag.c_str());
			flag = 1;
		}
	}
	if (flag == 0)
		printf("查无此歌\n");
	printf("按回车以继续\n");
	getchar();
	getchar();
	return 0;
}
int search_guest(string info)
{
	int flag = 0,i;
	for (i = 0; i < linenum; i++)
	{
		if (Songs_info[i].singer_name == info || Songs_info[i].song_name == info || Songs_info[i].tag == info||Songs_info[i].No==info)
		{
			printf("%s %s %s %s\n", Songs_info[i].No.c_str(), Songs_info[i].song_name.c_str(), Songs_info[i].singer_name.c_str(), Songs_info[i].tag.c_str());
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("查无此歌\n");
	printf("按回车以继续\n");
	getchar();
	getchar();
	system("cls");
	return i;
}
int fix(int x, string info)
{
	int flag=0;
	for (int i = 0; i < linenum; i++)
		if (info == Songs_info[i].No || Songs_info[i].singer_name == info || Songs_info[i].song_name == info || Songs_info[i].tag == info)
			flag = i;
	switch (x)
	{
	case 1:
		Songs_info[flag].No = info;
		break;
	case 2:
		Songs_info[flag].song_name = info;
		break;
	case 3:
		Songs_info[flag].singer_name = info;
		break;
	case 4:
		Songs_info[flag].tag = info;
		break;
	}
	printf("修改成功！记得存盘！\n");
	printf("按回车以继续\n");
	getchar();
	getchar();
	//Search first then choose what infomation to change then change the information
	return 0;
}

void store()
{
	FILE* fp = NULL;
	int flag=0, c;
	fp = fopen("songs.txt", "w");
	for (int i = 0; i < linenum; i++)
		fprintf(fp, "%s %s %s %s\n", Songs_info[i].No.c_str(), Songs_info[i].song_name.c_str(), Songs_info[i].singer_name.c_str(), Songs_info[i].tag.c_str());
	fclose(fp);
}
void view()
{
	FILE* fp;
	int flag = 0, c;
	fp = fopen("songs.txt", "r");
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
	if ((fp = fopen("songs.txt", "r")) == NULL)
	{
		fp = fopen("songs.txt", "r");
		fclose(fp);
	}
	else
	{
		fp = fopen("songs.txt", "r");
		char songs_name_tmp[50], singer_name_tmp[50], songs_tag_tmp[50], songs_no[50];
		for (int k = 0; k < linenum; k++)
		{
			fscanf(fp, "%s %s %s %s", songs_no, songs_name_tmp, singer_name_tmp, songs_tag_tmp);
			Songs_info[k].No = songs_no;
			Songs_info[k].song_name = songs_name_tmp;
			Songs_info[k].singer_name = singer_name_tmp;
			Songs_info[k].tag = songs_tag_tmp;
		}
		fclose(fp);
	}//store all infos into list
	for (int i = 0; i < linenum; i++)
		printf("%s %s %s %s\n", Songs_info[i].No.c_str(), Songs_info[i].song_name.c_str(), Songs_info[i].singer_name.c_str(), Songs_info[i].tag.c_str());
	printf("按回车以继续\n");
	getchar();
	getchar();
}
void del(string info)
{
	int flag = 0;
	for (int i = 0; i < linenum; i++)
		if (Songs_info[i].song_name == info)
			flag = i;
	for (int i = flag; i < linenum; i++)
		Songs_info[i] = Songs_info[i + 1];
	linenum--;
	printf("删除成功！记得存盘！\n");
	printf("按回车以继续\n");
	getchar();
}
int main()
{
	int a, b, flag1=0, flag = 0, c,d,e,n=0,m=0,num;
	char account[20], passwd[20], ch, i = 0;
	FILE* fp = NULL;
	i = 0;
	while (1)
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
		printf("	Designed By Lemoon		   `:.:'\n");
		printf("\n");
		printf("\n               欢迎登录              \n");
		printf("          点歌台歌曲管理系统           \n");
		printf("\n");
		printf("\n");
		printf("请选择身份：\n");
		printf("1.用户\n");
		printf("2.管理员\n");
		printf("0.退出\n");
		scanf("%d", &a);
		system("cls");
		switch (a)
		{
		case 1://guest
			fp = fopen("songs.txt", "r");
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
			fclose(fp);//get lines
			if ((fp = fopen("songs.txt", "r")) == NULL)
			{
				fp = fopen("songs.txt", "r");
				fclose(fp);
			}
			else
			{
				fp = fopen("songs.txt", "r");
				char songs_name_tmp[50], singer_name_tmp[50], songs_tag_tmp[50], songs_no[50];
				for (int k = 0; k < linenum; k++)
				{
					fscanf(fp, "%s %s %s %s", songs_no, songs_name_tmp, singer_name_tmp, songs_tag_tmp);
					Songs_info[k].No = songs_no;
					Songs_info[k].song_name = songs_name_tmp;
					Songs_info[k].singer_name = singer_name_tmp;
					Songs_info[k].tag = songs_tag_tmp;
				}
				fclose(fp);
			}//store all infos into list
			for (;;)
			{
				system("cls");
				printf("\n请选择要进行的操作：\n");
				printf("1.查询歌曲信息\n");
				printf("2.浏览歌曲信息\n");
				printf("3.点歌系统\n");
				printf("0.退出\n");
				scanf("%d", &c);
				system("cls");
				songs songs_tmp;
				songs play[100];
				switch (c)
				{
				case 1://search
					char tmpc[50],no[50];
					int x;
					printf("请选择查询方式\n");
					printf("1.歌曲名\n");
					printf("2.歌手名\n");
					printf("3.歌曲类别\n");
					printf("0.返回\n");
					printf("请输入\n");
					scanf("%d", &x);
					switch (x)
					{
					case 1:
					case 2:
					case 3:
						printf("请输入\n");
						scanf("%s", tmpc);
						search(tmpc);
						break;
					case 0:
						break;
					}
					break;
				case 2://view
					printf("             歌曲列表         \n");
					printf("编号   歌曲名   歌手名   歌曲类别\n");
					view();
					break;
				case 3:
					while (1)
					{
						while (1)
						{
							printf("请输入要点的歌曲编号,输入0开始播放\n");
							scanf("%s", no);
							if (strcmp(no,"0")!=0)
							{
								m = search_guest(no);
								play[n].No = Songs_info[m].No.c_str();
								play[n].song_name = Songs_info[m].song_name.c_str();
								play[n].singer_name = Songs_info[m].singer_name.c_str();
								n++;
								if (n > 99)
									break;
							}
							else
								break;
						}
						system("cls");
						num = n;
						while (num > 0)
						{
							system("cls");
							for (int i = 0; i < num; i++)
								printf("%s %s %s %s\n", play[i].No.c_str(), play[i].song_name.c_str(), play[i].singer_name.c_str(), play[i].tag.c_str());
							Sleep(60000);
							for (int i = 0; i <num; i++)
							{
								play[i].No = play[i + 1].No.c_str();
								play[i].song_name = play[i + 1].song_name.c_str();
								play[i].singer_name = play[i + 1].singer_name.c_str();
								play[i].tag = play[i + 1].tag.c_str();
							}
							num--;
						}
						system("cls");
						printf("点播歌曲已经播完，请继续点播,按0退出\n");
						scanf("%d", &e);
						if (e == 0)
							break;
					}
					break;
				case 0:
					printf("再见，欢迎下次使用\n");
					exit(0);
				default:
					getchar();
					printf("输入错误，请重新选择\n");
					printf("请选择要进行的操作：\n");
					printf("1.添加图书信息\n");
					printf("2.按出版社查询图书信息\n");
					printf("3.删除图书\n");
					printf("4.修改图书信息\n");
					printf("0.退出\n");
					break;
				}
			}
		case 2://admin
			printf("请输入账号：\n");
			getchar();
			gets_s(account);
			printf("请输入密码：\n");
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
					flag1 = login(account, passwd);
					if (flag1 == 1)
						break;
				}
			}
			break;
		case 0:exit(0);
		default:
			printf("输入错误，请重新选择\n");
			getchar();
			break;
		}
		if (flag1 == 1)
			break;
	}
	//read files
		fp = fopen("songs.txt", "r");
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
		fclose(fp);//get lines
		if ((fp = fopen("songs.txt", "r")) == NULL)
		{
			fp = fopen("songs.txt", "r");
			fclose(fp);
		}
		else
		{
			fp = fopen("songs.txt", "r");
			char songs_name_tmp[50], singer_name_tmp[50], songs_tag_tmp[50], songs_no[50];
			for (int k = 0; k < linenum; k++)
			{
				fscanf(fp, "%s %s %s %s", songs_no, songs_name_tmp, singer_name_tmp, songs_tag_tmp);
				Songs_info[k].No = songs_no;
				Songs_info[k].song_name = songs_name_tmp;
				Songs_info[k].singer_name = singer_name_tmp;
				Songs_info[k].tag = songs_tag_tmp;
			}
			fclose(fp);
		}//store all infos into list
		while(1)
		{
			system("cls");
			printf("\n请选择要进行的操作：\n");
			printf("1.添加歌曲信息\n");
			printf("2.查询歌曲信息\n");
			printf("3.修改歌曲信息\n");
			printf("4.删除歌曲信息\n");
			printf("5.存盘\n");
			printf("6.浏览歌曲信息\n");
			printf("0.退出\n");
			scanf("%d", &c);
			system("cls");
			songs songs_tmp;
			switch (c)
			{
			case 1://add
				printf("请按如下格式输入信息\n");
				printf("编号 歌曲名 歌手名 歌曲类别\n");
				scanf("%s %s %s %s",songs_tmp.No.c_str(),songs_tmp.song_name.c_str(),songs_tmp.singer_name.c_str(),songs_tmp.tag.c_str());
				add(songs_tmp);
				getchar();
				getchar();
				break;
			case 2://search
				char tmpc[50];
				int x;
				printf("请选择查询方式\n");
				printf("1.歌曲名\n");
				printf("2.歌手名\n");
				printf("3.歌曲类别\n");
				printf("0.返回\n");
				printf("请输入\n");
				scanf("%d", &x);
				switch (x)
				{
				case 1:
				case 2:
				case 3:
					printf("请输入\n");
					scanf("%s", tmpc);
					search(tmpc);
					break;
				case 0:
					break;
				}
				break;
			case 3://fix
				char name[50];
				printf("请输入要修改的歌曲名\n");
				scanf("%s", name);
				search(name);
				printf("请选择要修改的信息\n");
				printf("1.编号\n");
				printf("2.歌曲名\n");
				printf("3.歌手名\n");
				printf("4.歌曲类别\n");
				printf("0.返回\n");
				scanf("%d", &x);
				printf("请输入\n");
				switch (x)
				{
				case 1:
				case 2:
				case 3:
				case 4:
					scanf("%s", tmpc);
					fix(x, tmpc);
					break;
				case 0:
					break;
				}
				break;
			case 4://delete
				printf("请输入要删除的歌曲名\n");
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
				printf("             歌曲列表         \n");
				printf("编号   歌曲名   歌手名   歌曲类别\n");
				view();
				break;
			case 0:
				printf("再见，欢迎下次使用\n");
				exit(0);
			default:
				getchar();
				printf("输入错误，请重新选择\n");
				printf("请选择要进行的操作：\n");
				printf("1.添加图书信息\n");
				printf("2.按出版社查询图书信息\n");
				printf("3.删除图书\n");
				printf("4.修改图书信息\n");
				printf("0.退出\n");
				break;
			}
		}





		
	

}