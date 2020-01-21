#include<stdio.h>
int main()
{
	int x, y,minus;
	do
	{
		scanf_s("%d%d", &x, &y);
		minus = x - y;
	} while (minus > 0);
	return 0;
}