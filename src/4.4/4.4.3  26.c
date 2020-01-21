#include<stdio.h>
int main()
{
	int x, y,min,num1,x_n,y_n;
	scanf_s("%d%d", &x, &y);
	min = x < y?x : y;
	for (int i = 1; i <= min; i++)
	{
		if (x%i == 0 && y%i == 0)
			num1 = i;
	}
	printf("%d\n", num1);
	for (int n = 1; n <= y; n++)
	{
		x_n = x * n;
		for (int m = 1; m <= x; m++)
		{
			y_n = m * y;
			if (x_n == y_n)
			{
				printf("%d", x_n);
				break;
			}
		}
	}
	return 0;
}