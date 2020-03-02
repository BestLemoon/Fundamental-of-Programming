#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[]) 
{
	FILE* fp;
	char lit[10000], note[10000],name[50];
	int n = 0, m = 0;
	printf("请输入要删去注释的文件名:(默认后缀.cpp)\n");
	scanf("%s", name);
	strcat(name, ".cpp");
	fp = fopen(name, "r");
	enum {
		literal, single, multiple
	}
	mode = literal;
	char last = 0, current;
	while ((current = fgetc(fp)) != EOF) 
	{
		switch (mode) 
		{
			case single: 
				{
					note[m++] = current;
					if (last != '\\' && (current == '\n' || current == '\r')) 
					{
						lit[n++]=current; 
						current = 0;
						mode = literal;
					}
				}
				break;
			case multiple: 
				{
					note[m++] = current;
					if (last == '*' && current == '/') 
					{
						current = 0;
						mode = literal;
						m -= 2;//删去写入的*/
					}
				}
				break;
			default: 
				{
					if (last == '/') 
					{
						if (current == '/') 
						{
							mode = single;//判断进入单行注释
						}
						else if (current == '*') 
						{
							mode = multiple;//判断进入多行注释
						}
						else 
						{
							lit[n++]=last;//否则写入lit
							lit[n++]=current;
						}
					}
					else if (current != '/') //单行注释未结束
					{
						lit[n++]=current;
					}
				}
				break;
		}
		last = current;
	}
	lit[n] = '\0';
	note[m] = '\0';
	//puts(lit);
	//puts(note);
	fclose(fp);
	printf("请输入源文件存为的文件名:(默认后缀.cpp)\n");//最后处理文件
	scanf("%s", name);
	strcat(name, ".cpp");
	fp = fopen(name, "w");
	fprintf(fp,"%s", lit);
	fclose(fp);
	printf("请输入注释存为的文件名:(默认后缀.txt)\n");
	scanf("%s", name);
	strcat(name, ".txt");
	fp = fopen(name, "w");
	fprintf(fp, "%s", note);
	fclose(fp);
	return 0;
}