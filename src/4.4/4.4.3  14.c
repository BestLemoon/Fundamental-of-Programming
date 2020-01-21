#include<stdio.h>
int main()
{
	int x ,i;
	scanf_s("%d",&x);
	for (int  n = 2; n <= x; n++)
	{
		for ( i = 2; i <= n; i++)
		{
			if (n%i == 0)
				break;
		}
			if (n == i)
				printf("%d ", n);
	}
	return 0;
}