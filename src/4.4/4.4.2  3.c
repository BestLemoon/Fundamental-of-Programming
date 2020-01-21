#include<stdio.h>
int main()
{
	int x, a, b, c;
	for (x = 100; x <= 999; x++)
	{
		a = x / 100;
		b = (x % 100) / 10;
		c = (x % 100) % 10;
		if (a*a*a + b * b*b + c * c*c == x)
			printf("%d\n", x);
	}
	return 0;
}