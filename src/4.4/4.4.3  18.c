#include<stdio.h>
int main()
{
	int x, y, z,sum=100,a=0;
	for (x = 0; x <= 100; x++)
	{
		for (y = 0; y <= 100; y++)
		{
			for (z = 0; z <= 100; z++)
			{
				if (3 * x + y + z / 3 == 100)
					a++;
			}
		}
	}
	printf("%d", a);
	return 0;
}