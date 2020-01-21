#include<stdio.h>
int main()
{
	int i, j;
	for (i = 1; i <=9;)
	{
		for (int k = 1; k <= i-1; k++)
			printf("       ");
		for (j = 1; j<=9; j++)
		{	

			if(j>=i)
			printf("%d*%d=%d  ", i, j,i*j);
		}
		printf("\n");
		i++;
	}
	return 0;
}