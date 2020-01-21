#include<stdio.h>
int main()
{
	int a[6],x;
	a[5] = 0;
	for (int i = 0; i <= 4; i++)
		scanf_s("%d", &a[i]);
	for (int j = 0; j <= 4; j++)
	{
		for (int i = 0; i <= 4 - j; i++)
		{
			int temp;
			if (a[i] > a[i + 1])
			{
				temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
			}
		}
	}
	scanf_s("%d", &x);
	for (int i = 0; i <= 4; i++)
	{
		if (x >= a[i] && x <= a[i + 1])
		{
			for (int k = 0; k <=i; k++)
				a[k] = a[k+1];
			a[i] = x;
		}
	}
	for (int i = 0; i <= 5; i++)
		printf("%d ", a[i]);
	return 0;
}