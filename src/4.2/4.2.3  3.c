#include<stdio.h>
int main()
{
	int a, b, c, d;
	scanf_s("%d%d%d", &a, &b, &c);
	d = 100 * a + 10 * b + c;
	printf("%d", d);
	return 0;

}