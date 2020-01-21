#include<stdio.h>
int main()
{
	int n, k;
	double sum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		sum = 1;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
			sum *= j;
		printf("%.0lf\n", sum);
	}
	return 0;
}