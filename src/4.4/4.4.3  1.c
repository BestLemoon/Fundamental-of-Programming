#include<stdio.h>
int main()
{
	double a[10],temp=0;
	for(int i=0;i<=9;i++)
		scanf_s("%lf", &a[i]);
	for (int j = 0; j <= 9; j++)
	{
		temp += a[j];
	}
	printf("%lf\n", temp);

	for (int j = 0; j <= 9; j++)
	{
		temp = 1;
		temp *= a[j];
	}
	printf("%lf\n", temp);

	for (int j = 0; j <= 9; j++)
	{
		temp =temp+a[j]*a[j];
	}
	printf("%lf\n", temp);	

	for (int j = 0; j <= 9; j++)
	{
		temp += a[j];
	}
	printf("%lf\n", temp*temp);
	return 0;
}