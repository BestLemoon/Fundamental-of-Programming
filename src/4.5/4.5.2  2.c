#include<stdio.h>
int main()
{
	float a[5],max;
	int n;
	for (int j = 0; j <= 4; j++)
	{
		scanf_s("%f", &a[j]);
	}	
	max = a[0];
	for (int i = 0; i <= 4; i++)
	{
		if (a[i] > max)
			n = i;
	}
	printf("%d", n);
	return 0;
}