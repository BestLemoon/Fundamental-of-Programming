#include<stdio.h>
#define pi 3.1415
double carea(double r);
int main()
{

	double r,area;
	scanf("%lf", &r);
	area = carea(r);
	printf("%lf",area);
	return 0;
}
double carea(double r)
{
	double a;
	a = pi * r*r;
	return a;
}