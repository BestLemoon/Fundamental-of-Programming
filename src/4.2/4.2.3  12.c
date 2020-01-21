#include<stdio.h>
int main()
{
	int n, nn,a,b;
	scanf_s("%d", &n);
	nn = n * n;
	b = (nn % 100) / 10;
	a = (nn % 100)%10;
	printf("%d", a+10*b);
	return 0;
}