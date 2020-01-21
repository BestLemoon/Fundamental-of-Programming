#include<stdio.h>
int main()
{
	int n, sum1=0, sum2=0, j=0, k=0;
	for (;;)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		if (n % 2 == 0)
		{
			j++;
			sum1 += n * n*n;
		}
		else
		{
			k++;
			sum2 += n * n*n;
		}
	}
	printf("%d %d\n", j, sum1);
	printf("%d %d\n", k, sum2);

	return 0;
}