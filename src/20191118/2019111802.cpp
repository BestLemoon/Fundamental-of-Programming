#include<stdio.h>
int main()
{
	int n, lines;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &lines);
		for (int j = 1; j <= lines; j++)
		{
			for (int m = lines; m > j; m--)
				printf(" ");
			for (int k = 1; k < j; k++)
				printf("%c", k + 64);
			for (int n = j; n >= 1; n--)
				printf("%c", n + 64);
			printf("\n");
		}
	}
	return 0;
}