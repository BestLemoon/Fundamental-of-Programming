#include<stdio.h>
int main()
{
	int sum = 4672;
	for (int year = 2013; year <= 2017; year++)
	{
		sum *= 1.1;
	}
	printf("%d", sum);
	return 0;
}