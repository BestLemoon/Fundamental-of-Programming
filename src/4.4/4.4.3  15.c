#include<stdio.h>
int main()
{
	int a,n=0,sum=0;
	for (int i = 1;; i++)
	{
		scanf_s("%d", &a);
		if (a == 0)
			break;
		if (a % 2 == 0)
		{
			n++;
			sum += a;
		}
	}
	printf("%d %d\n", n,sum/n);
	return 0;
}