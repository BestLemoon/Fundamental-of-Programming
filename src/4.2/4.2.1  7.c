#include<stdio.h>
int main(void)
{
	int x, y, z, a;
	scanf_s("%d%d%d", &x, &y, &z);
	a = 100 * x + 10 * y + z;
	printf("%d", a);
	return 0;
}