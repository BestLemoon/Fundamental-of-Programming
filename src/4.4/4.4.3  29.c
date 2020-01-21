#include<stdio.h>
#include<math.h>
int main()
{
	int x,n,a,b,c,d;
	scanf_s("%d", &x);
	n = log10(x);
	switch (n)
	{
	case 1:
		a = x / 10;
		b = x % 10;
		if (b == 0)
			printf("0%d", a);
		else
		printf("%d", b * 10 + a);
		break;
	case 2:
		a = x / 100;
		b = (x / 10) % 10;
		c = (x % 100)%10;
		if (c == 0&&b!=0)
		{
			printf("0%d%d", b, a);
		}
		else if (c == 0 && b == 0)
		{
			printf("00%d", a);
		}
		else
			printf("%d", c * 100 + b * 10 + a);
		break;
	case 3:
		a = x / 1000;
		b = (x / 100) % 10;
		c = (x / 10) % 10;
		d = x % 10;
		if (d == 0 && c != 0)
			printf("0%d%d%d", c, b, a);
		else if (d == 0 && c == 0 && b != 0)
			printf("00%d%d", b, a);
		else if (d == 0 && c == 0 && b == 0)
			printf("000%d", a);
		else
			printf("%d", d * 1000 + c * 100 + b * 10 + a);
		break;
	}

	return 0;
}