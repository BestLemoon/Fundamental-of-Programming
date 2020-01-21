#include<stdio.h>
int main()
{
	int lines;
	scanf_s("%d", &lines);
	for (int n = 1; n <= lines; n++)
	{
		for (int i = 1; i <= lines-n; i++)
			printf("   ");
		for(int j=1;j<=(2*n-1);j++)
		printf("*  ");
		printf("\n");
	}
	for (int m = lines-1; m >=1; m--)
	{
		for (int b = lines; b >=m+1; b--)
			printf("   ");
		for (int a = 1; a <= (2 * m - 1); a++)
			printf("*  ");
		printf("\n");

	}
	
	return 0;
}