#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	double pi=1;
	for (n = 1; n <= 100; n++)
		pi *= pow(2 * n, 2) / ((2 * n + 1)*(2 * n - 1));
	printf("%lf", 2 * pi);
	return 0;
}