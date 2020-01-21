#include<stdio.h>
int main()
{
	int a[20],sum=0;
	for (int i = 1; i <= 19; i++)
		scanf_s("%d", &a[i]);
	for (int j = 1; j <= 19; j++)
		sum += a[j];
	printf("%d", sum / 20);
	return 0;
}