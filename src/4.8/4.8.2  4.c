#include<stdio.h>
double tempt(double temp, char ctype)
{
	double tempp;
	if (ctype == 'C')
	{
		tempp = temp * 1.8 + 32;
	}
	else
		tempp = (temp - 32) / 1.8;
	return tempp;

}
int main()
{
	double temp;
	char ctype;
	scanf("%lf,%c", &temp, &ctype);
	printf("%lf", tempt(temp, ctype));

}