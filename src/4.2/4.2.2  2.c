#include<stdio.h>
int main()
{
	int a[10],j,k,max;
	for (j = 0; j <= 9; j++)
		scanf_s("%d", &a[j]);
	max = a[0];
	for (k = 0; k <= 9; k++)
		if (a[k] >= max)
			max = a[k];
	printf("%d", max);
	return 0;
}