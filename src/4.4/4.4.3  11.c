#include<stdio.h>
int main()
{
	int min, max;
	printf("���������½磨��3-5��");
	scanf_s("%d-%d", &min, &max);
	for (int n = min; n <= max; n++)
	{
		printf("%d %d %d\n", n, n*n, n*n*n);
	}
	return 0;
}