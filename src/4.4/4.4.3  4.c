#include<stdio.h>
int main()
{
	for (int n=1;n<=35;n++)
	{
		int i;
		long double sum = 1;
		for (i = 1; i <= n; i++)
			sum *= i;
		printf("%llf\n", sum);
	}
	return 0;
}