#include<stdio.h>
int main()
{
	int a[6][6];
	a[0][0] = 1;
	for (int line = 1; line <= 6; line++)
	{
		a[line-1][0] = 1;
		for (int m = line; m <= 5; m++)
		{
			a[line-1][m] = 0;
		}
		if (line >= 2)
		{
			for (int i = 1; i <= 5; i++)
			{
				a[line-1][i] = a[line - 2][i - 1] + a[line - 2][i];
			}
		}

	}
	for (int j = 0; j <= 5; j++)
	{
		for (int k = 0; k <= 5; k++)
		{
			if (a[j][k] == 0)
				printf(" ");
			else
				printf("%d ", a[j][k]);
		}
		printf("\n");
	}
	return 0;
} 