#include<stdio.h>
int isOE(int number)
{
	int temp;
	if (number % 2 == 0)
		temp = -1;
	else
		temp = 1;
	return temp;
}
int main()
{
	int num;
	scanf("%d", &num);
	printf("%d", isOE(num));
}