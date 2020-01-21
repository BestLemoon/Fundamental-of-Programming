#include<stdio.h>
#include<math.h>
int main()
{
	int x, y;
	scanf_s("%d%d", &x, &y);
	if (x > 0)
	{
		if (y > 0)
			printf("%lf", log(x) + log(y));
		else
			printf("%lf", tan(x+y));
	}
	else
	{
		if (y > 0)
			printf("%lf", sin(x) + sin(y));
		else
			printf("%lf", exp(2 * x) + exp(3 * x));
	}
	return 0;
}