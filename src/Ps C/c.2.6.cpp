#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	FILE* fp;
	float count=0;
	char word[100],tmp[100];
	double start, end;
	srand((unsigned)time(NULL));
	printf("\t��ӭ������Ӣ�Ĵ���ѵ������\n");
	printf("\t\t���س��Կ�ʼ\n");
	getchar();
	start = clock();
	fp = fopen("c.2.6_ans.txt", "w");
	for (int i = 0; i < 100; i++)
	{
		word[i] = 'a'+rand() % 26;
		printf("%c",word[i]);
		fprintf(fp, "%c",word[i]);
	}//random char saved in file and print in terminal
	fclose(fp);
	printf("\n");
	fp = fopen("c.2.6_usr.txt", "w");
	for (int i = 0; i < 100; i++)
	{
		scanf("%c", &tmp[i]);
		if (tmp[i] == word[i])
			count++;
		fprintf(fp, "%c", tmp[i]);
	}//read usr input and save into file
	fclose(fp);
	end = clock();
	printf("\n������\n");
	printf("��ȷ��:%f,��ʱ:%fs\n", count / 100.0, (end - start) / CLOCKS_PER_SEC);
	return 0;
}