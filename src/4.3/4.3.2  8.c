#include<stdio.h>
int main()
{
	int a,n;
	scanf_s("%d", &a);
	n = a % 2;
	if (n == 1)
		printf("����");
	else
		printf("ż��");
	return 0;
}