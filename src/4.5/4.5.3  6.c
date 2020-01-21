#include<stdio.h>
int main()
{
	int a[5][5],b[5][5];
	for (int i = 0; i <= 4; i++)
		scanf_s("%d %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
	printf("\n");
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
			printf("%-d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
	for (int j = 0; j <= 4; j++)
	{
		int temp;
		temp = a[1][j];
		a[1][j] = a[4][j];
		a[4][j] = temp;
	}
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
			printf("%-d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			b[i][j] = a[i][j] / a[i][i];
		}
	}
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
			printf("%-d ", b[i][j]);
		printf("\n");
	}


	return 0;
}