#include<stdio.h>
int main()
{
	int n=0;
	for (int i = 77; i <= 210; i++)
	{
		if (i % 2 == 0)
			n++;
	}
	printf("%d", n);
	return 0;
}