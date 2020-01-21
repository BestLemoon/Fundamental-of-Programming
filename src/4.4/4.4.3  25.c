#include<stdio.h>
int main()
{
	int a, b, c,i=0;
	for (int n = 100; n <= 300; n++)
	{
		a = n / 100;
		b = (n / 10) % 10;
		c = n % 100;
		if ((a + b + c) % 5 == 0)
			i++;
	}
	printf("%d", i);


	return 0;
}