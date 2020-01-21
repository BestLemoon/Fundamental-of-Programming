#include<stdio.h>
int main()
{
	double x;
	scanf_s("%lf", &x);
	if (x < 1)
		printf("%lf", x);
	else
	{
		if (x >= 1 && x < 15)
			printf("%lf", 2 * x - 1);
		else {
			if (x >= 15)
				printf("%lf", 6 * x + x * x);
		}
	}
	return 0;
}