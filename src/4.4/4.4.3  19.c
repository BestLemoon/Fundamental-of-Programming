#include<stdio.h>
int main()
{
	int x, y, z;
	for (x = 0; x <= 100; x++)
	{
		for (y = 0; y <= 100; y++)
		{
			for (z = 0; z <= 100; z++)
			{
				if (3 * x + 2 * y + 0.5*z == 100)
					printf("����:%d,����:%d,С��:%d\n", x, y, z);
			}
		}
	}
	return 0;
}