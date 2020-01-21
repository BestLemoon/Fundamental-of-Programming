#include<stdio.h>
int main()
{
	int a[2][3], b[2][3], c[2][3];
	for (int i = 0; i <= 1; i++)
		scanf_s("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	for (int j = 0; j <= 1; j++)
		scanf_s("%d %d %d", &b[j][0], &b[j][1], &b[j][2]);
	for (int k = 0; k <= 1; k++)
		for (int m = 0; m <= 2; m++)
			c[k][m] = a[k][m] + b[k][m];
	for (int k = 0; k <= 1; k++)
	{
		for (int m = 0; m <= 2; m++)
			printf("%d ", c[k][m]);
		printf("\n");
	}
	return 0;
}