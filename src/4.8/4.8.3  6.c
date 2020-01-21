#include<stdio.h>
#include<math.h>
double power(double n,int p)
{
	double result;
	result = pow(n, p);
	return result;
}
int main()
{
	int p;
	double n;
	scanf("%lf%d", &n, &p);
	printf("%lf", power(n, p));
	return 0;
}