#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,x1,y1,x2,y2,count=0;
	double start,end;
	start = clock();
	printf("请指定矩阵阶数:\n");
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
		printf("请输入要删除的坐标:(如(1 1))输入(0 0)跳过\n");
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
			printf("删除成功\n");
			printf("按回车以继续\n");
			getchar();
			getchar();
		}
		else
			printf("删除失败\n");
		system("cls");
	}
	end = clock();
	printf("游戏结束，用时为%f秒\n", (end - start) / CLOCKS_PER_SEC);
	return 0;
}