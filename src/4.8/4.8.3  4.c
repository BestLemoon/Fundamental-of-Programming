#include<stdio.h>
int lcm(int x1, int x2)
{
	int min,max;
	int min_n, max_n,result=0;
	min = x1 < x2 ? x1 : x2;
	max = x1 > x2 ? x1 : x2;
	for (int i = 1;; i++)
	{
		int flag = 0;
		for (int j = 1;j<i; j++)
		{
			min_n = i * min;
			max_n = j * max;
			if (max_n == min_n)
			{
				flag = 1;
				result = max_n;
				break;
				
			}
		}
		if (flag == 1)
			break;
	}
	return result;
}
int main()
{
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	printf("%d", lcm(n1, n2));

	return 0;
}