#include<stdio.h>
int main()
{
	int lines;
	scanf_s("%d", &lines);
	for (int n = 1; n <= lines; n++)
	{
		for (int i = 1; i <= n; i++)
			printf("$");
		printf("\n");
	}

	return 0;
}