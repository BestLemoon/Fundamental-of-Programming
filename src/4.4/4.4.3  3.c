#include<stdio.h>
int main()
{
	double e = 1, temp;
	for (int n = 1;; n++)
	{
		temp = 1.000 / fac(n);
		if (temp >= 1e-6)
			e += temp;
		else
			break;
	}
	printf("%lf", e);
	return 0;
}
int fac(n)
{
	int i, sum = 1;
	for (i = 1; i <= n; i++)
		sum *= i;
	return sum;
}
