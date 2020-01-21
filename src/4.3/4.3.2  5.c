#include<stdio.h>
int main()
{
	int a, b, c;
	scanf_s("%d%d%d", &a, &b, &c);
	if (a <= b && a <= c)//如果a最小
	{
		printf("%d", a);
		if (b <= c)//比较b和c
			printf(" %d %d", b,c);
		else
			printf(" %d %d", c,b);
	}
	else
	{
		if (b <= c)//如果b最小
		{
			if (a <= c)//比较a和c
				printf("%d %d %d", b, a, c);
			else
				printf("%d %d %d", b, c, a);
		}
		else//如果c最小
		{
			if (b <= a)//比较a和b
				printf("%d %d %d", c, b, a);
			else
				printf("%d %d %d", c, a, b);
		}
	}
	return 0;
}