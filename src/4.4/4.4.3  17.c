#include <stdio.h>
int main()
{
	int sum1, sum2;	// 因子之和
	int i, j, k;

	for (i = 2; i <= 1000; i++)
	{
		sum1 = 0;
		sum2 = 0;
		for (j = 1; j < i; j++)	
		{
			if (i%j == 0)
				sum1 += j;
		}
		for (k = 1; k < sum1; k++)	
		{
			if (sum1%k == 0)
				sum2 += k;
		}
		if (i == sum2 && i < sum1)
			printf("%d %d\n", i, sum1);
	}
	return 0;
}