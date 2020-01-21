#include<stdio.h>
int main()
{
	int a[3][3],x;
	for (int i = 0; i <= 2; i++)
			scanf_s("%d %d %d", &a[i][0],&a[i][1],&a[i][2]);
	for (int m = 0; m <= 2; m++)
	{
		for (int n = 0; n <= 2; n++)
		{
			if (n > m)
			{
				x = a[m][n];
				a[m][n] = a[n][m];
				a[n][m] = x;
			}
		}
	}
	for (int p = 0; p <= 2; p++)
	{
		for (int q = 0; q <= 2; q++)
			printf("%d ", a[p][q]);
			printf("\n");
	}

	return 0;
}
