#include<stdio.h>
int main()
{
	int j;
	for (int i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			if (i <= j)
			{
				printf("%d*%d=%d  ", i, j,i*j);
			}
		}
		printf("\n");
	}


	return 0;
}