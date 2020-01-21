#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	double pi=1,temp;
	for (n = 1;; n++)
	{
		temp= pow(-1, n) *(1.0/ (2 * n + 1));
		if (fabs(temp) >= 1e-5)
			pi += temp;
		else
			break;
	}
	printf("%lf", 4 * pi);
	return 0;
}