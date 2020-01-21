#include<stdio.h>
int main()
{
	int a[20],loc[20],temp,templ;
	for (int i = 0; i <= 19; i++)
	{
		scanf_s("%d", &a[i]);
		loc[i] = i + 1;
	}
	for (int j = 1; j <= 20; j++)
	{
		for (int k = 0; k <= 19-j; k++)
		{
			if (a[k] > a[k + 1])
			{
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
				templ = loc[k];
				loc[k] = loc[k + 1];
				loc[k + 1] = templ;
			}
		}
	}
	for (int m = 0; m <= 19; m++)
	{
		printf("%-d   %d\n", a[m], loc[m]);
	}



	return 0;
}