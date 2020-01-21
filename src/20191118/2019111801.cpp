#include<stdio.h>
int main()
{
	int n, x, y, yueshu;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		int min = x < y ? x : y;
		for (int j = 1; j <= min; j++)
		{
			if (x%j == 0 && y%j == 0)
			{
				yueshu = j;
			}
		}
		printf("%d\n", yueshu);
	}
	return 0;
}