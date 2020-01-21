#include<stdio.h>
int main()
{
	char X;
	int line,k;
	scanf_s("%c", &X);
	line = X - 64;
	for (int i = 1; i <= line; i++)
	{
		for (int j = 1; j <= line-i; j++)
			printf(" ");
		for (k=1; k <= i-1; k++)
		{
			printf("%c", 64 + k);
		}
		if (64 + k >= 65)
		{
			for (int m = 64 + k; m >= 65; m--)
				printf("%c%", m);
		}
		printf("\n");
	}
	return 0;
}