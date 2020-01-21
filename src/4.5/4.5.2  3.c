#include<stdio.h>
int main()
{
	int a[5],max,min;
	for (int i = 0; i <= 4; i++)
		scanf_s("%d", &a[i]);
	max = a[0];
	for (int j = 1; j <= 4; j++)
	{
		if (a[j] > max)
			max = a[j];
	}
	min = a[0];
	for (int k = 1; k <= 4; k++)
	{
		if (a[k] < min)
			min = a[k];
	}
	printf("%d", max - min);
	return 0;
}