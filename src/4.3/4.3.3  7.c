#include<stdio.h>
int main()
{
	int x, y,n,sum;
	printf(" 1 做加法\n 2 做减法\n 3 做乘法\n 4 做除法\n 请选择\n");
	scanf_s("%d", &n);
	scanf_s("%d%d", &x, &y);
	switch (n)
	{
	case 1:
		sum = x + y;
		printf("%d", sum);
		break;
	case 2:
		sum = x - y;
		printf("%d", sum);
		break;
	case 3:
		sum = x * y;
		printf("%d", sum);
		break;
	case 4:
		if (y != 0)
		{
			sum = x / y;
			printf("%d", sum);
		}
		else
			printf("Error!");
		break;
	}
	return 0;
}