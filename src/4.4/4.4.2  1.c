#include<stdio.h>
int main()
{
	int a, k;
	scanf_s("%d", &a);
	if (a > 0)
	{
		printf("%d:", a);
		for (k = 1; k <= a; k++)		
			if (a % k == 0)
				printf("%d ", k);
	}
	printf("\n");
}