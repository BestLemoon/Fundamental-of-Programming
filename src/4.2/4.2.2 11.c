#include<stdio.h>
int main()
{
	float a, b, c;
	scanf_s("%f%f", &a, &b);
	c = a;
	a = b;
	b = c;
	printf("%f%f", a, b);
	return 0;
}