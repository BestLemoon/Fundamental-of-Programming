#include<stdio.h>
int main()
{
	int n, k, sum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		scanf("%d", &k);
		for (int j = 1; j <k; j++)
		{
			if (k%j == 0)
				sum += j;
		}
		if (sum == k)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}