#include<stdio.h>
int main()
{
	int a, b, c;
	scanf_s("%d%d%d", &a, &b, &c);
	if (a <= b && a <= c)//���a��С
	{
		printf("%d", a);
		if (b <= c)//�Ƚ�b��c
			printf(" %d %d", b,c);
		else
			printf(" %d %d", c,b);
	}
	else
	{
		if (b <= c)//���b��С
		{
			if (a <= c)//�Ƚ�a��c
				printf("%d %d %d", b, a, c);
			else
				printf("%d %d %d", b, c, a);
		}
		else//���c��С
		{
			if (b <= a)//�Ƚ�a��b
				printf("%d %d %d", c, b, a);
			else
				printf("%d %d %d", c, a, b);
		}
	}
	return 0;
}