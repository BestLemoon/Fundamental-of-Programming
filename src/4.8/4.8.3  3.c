#include<stdio.h>
#define pi 3.14
double cvolume(double r, double h)
{
	double v;
	v = h * pi*r*r;
	return v;
}
int main()
{
	int r, h;
	scanf("%d%d", &r, &h);
	printf("%lf", cvolume(r, h));
	return 0;
}