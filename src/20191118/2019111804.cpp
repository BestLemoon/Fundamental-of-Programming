#include<stdio.h>
int main()
{
	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		for (int k = x; k <= y; k++)
		{
			int flag = 0;
			for (int j = 2; j < k; j++)
			{
				if (k%j == 0)
					flag = 1;
			}
			if (flag == 0)
				printf("%d ", k);
		}
		printf("\n");
	}
	return 0;
}