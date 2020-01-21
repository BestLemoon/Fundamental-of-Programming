#include<stdio.h>
int main()
{
	
	for (int i = 1; i <= 1000; i++)
	{
		int sum = 0;
		for (int n = 1; n <= i; n++)
		{
			if (i%n == 0&&i!=n)
				sum += n;
		}
		if (sum == i)
			printf("%d ", i);
	}
	return 0;
}