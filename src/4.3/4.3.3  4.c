#include<stdio.h>
int main()
{
	int x, y,a,b;
	scanf_s("%d%d", &x, &y);
	a = x / y;
	b = x % y;
	if (y = 0)
		printf("Error");
	else
		printf("%d\n", a);
	printf("%d\n", b);
	return 0;
}