#include<stdio.h>
int main()
{
	int n,k,sum,a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		scanf("%d", &k);
		while (k)
		{
			a = k % 10;
			k /= 10;
			sum += a;
		}
		if (sum % 5 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}