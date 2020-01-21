#include<stdio.h>
int main()
{
	int a=0, b=0, c=1, x, n;
	n = 4;
	printf("%d %d %d ", a, b, c);
	while (n <= 10)
	{
		x = a + b + c;
		a = b; 
		b = c;
		c = x;
		printf("%d ", x);
		n++;
	}
	printf("\n");
	return 0;
}