#include<stdio.h>
#include<math.h>
int main() 
{
	int i = 2, k = 1;
	double x;
	double temp, result = 0, num;
	scanf_s("%lf", &x);
	do 
	{
		num = 1;
		for (long j = 1; j <= k; j++) 
		{
			num = num * j;
		}
		temp = pow(-1, i)*pow(x, k) / num;
		result = result + temp;
		i++;
		k = k + 2;
	} 
	while (fabs(temp) >= 1e-5);
	printf("%lf", result);
	return 0;
}