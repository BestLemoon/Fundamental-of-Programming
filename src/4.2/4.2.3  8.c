#define pi 3.14
#include<stdio.h>
int main()
{
	float r=1.5, c, s, v;
	int h = 3;
	c = 2 * pi*r;
	s = 2 * pi*r*r + c * h;
	v = pi * r*r * 1 / 3 * h;
	printf("%f\n%f\n%f\n", c, s, v);
	return 0;
}