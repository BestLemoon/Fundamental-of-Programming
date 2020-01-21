#include<stdio.h>
int main()
{
	int price;
	double tax;
	scanf_s("%d", &price);
	if (price >= 10000)
	{
		tax = price * 0.05;	
	}
	else
	{
		if (price >= 5000)
			tax = price * 0.03;
		else {
			if (price >= 1000)
				tax = price * 0.02;
			else
				tax = 0;
		}
	}
	printf("%lf", tax);
	return 0;
}