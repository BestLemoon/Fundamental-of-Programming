#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,x1,y1,x2,y2,count=0;
	double start,end;
	start = clock();
	printf("��ָ���������:\n");
	scanf("%d", &n);
	int** a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		a[i] = (int*)malloc(sizeof(int) * n);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10 + 1;
		}
	}
	while (count <= n * n / 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		int num = rand() % 18 + 2;
		printf("%d\n", num);
		printf("������Ҫɾ��������:(��(1 1))����(0 0)����\n");
		scanf("%d %d", &x1, &y1);
		if (x1 == 0 && y1 == 0)
		{
			system("cls");
			continue;
		}
		scanf("%d %d", &x2, &y2);
		printf("\n");
		if (a[x1 - 1][y1 - 1] + a[x2 - 1][y2 - 1] == num)
		{
			a[x1 - 1][y1 - 1] = 0;
			a[x2 - 1][y2 - 1] = 0;
			count++;
			printf("ɾ���ɹ�\n");
			printf("���س��Լ���\n");
			getchar();
			getchar();
		}
		else
			printf("ɾ��ʧ��\n");
		system("cls");
	}
	end = clock();
	printf("��Ϸ��������ʱΪ%f��\n", (end - start) / CLOCKS_PER_SEC);
	return 0;
}