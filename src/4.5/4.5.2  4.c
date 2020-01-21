#include<stdio.h>
int main()
{
	int a[5], b[5], c[5];
	for (int i = 0; i <= 4; i++)
		scanf_s("%d", &a[i]);
	for (int j = 0; j <= 4; j++)
		scanf_s("%d", &b[j]);
	for (int k = 0; k <= 4; k++)
	{
		c[k] = a[k] + b[k];
		printf("%d", c[k]);
	}


	return 0;
}