#include<stdio.h>
int main()
{
	int n=1;
	for (int i = 7; i <= 100; i++)
	{
		if (i % 5 != 0)
		{
			printf("%d ", i);
			if (n == 5)
			{
				printf("\n");
				n = 1;
				continue;
			}

			n++;
		}
		
	}
	return 0;
}