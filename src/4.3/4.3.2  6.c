#include<stdio.h>
int main()
{
	int a;
	scanf_s("%d", &a);
	if (a % 2 == 0 && a % 3 == 0 && a % 5 == 0)
		printf("It can be devided by 2,3,5");
	else
		printf("It can\'t be devided by 2,3,5");
	return 0;
}