#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[]) 
{
	FILE* fp;
	char lit[10000], note[10000],name[50];
	int n = 0, m = 0;
	printf("������Ҫɾȥע�͵��ļ���:(Ĭ�Ϻ�׺.cpp)\n");
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
						m -= 2;//ɾȥд���*/
					}
				}
				break;
			default: 
				{
					if (last == '/') 
					{
						if (current == '/') 
						{
							mode = single;//�жϽ��뵥��ע��
						}
						else if (current == '*') 
						{
							mode = multiple;//�жϽ������ע��
						}
						else 
						{
							lit[n++]=last;//����д��lit
							lit[n++]=current;
						}
					}
					else if (current != '/') //����ע��δ����
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
	printf("������Դ�ļ���Ϊ���ļ���:(Ĭ�Ϻ�׺.cpp)\n");//������ļ�
	scanf("%s", name);
	strcat(name, ".cpp");
	fp = fopen(name, "w");
	fprintf(fp,"%s", lit);
	fclose(fp);
	printf("������ע�ʹ�Ϊ���ļ���:(Ĭ�Ϻ�׺.txt)\n");
	scanf("%s", name);
	strcat(name, ".txt");
	fp = fopen(name, "w");
	fprintf(fp, "%s", note);
	fclose(fp);
	return 0;
}