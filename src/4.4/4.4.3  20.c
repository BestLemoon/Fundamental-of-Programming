#include<stdio.h>
int main()
{
	int a[100];
	a[0] = 0;
	a[1] = 1;
	for(int n=2;n<=99;n++)
	{
		if (n % 2 == 0)
			a[n] = a[n - 1] + a[n - 2];
		else
			a[n] = a[n - 2] - a[n - 1];
	}
	for (int i = 0; i <= 99; i++)
		printf("%d ", a[i]);
	return 0;
}