#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int len,n1,n2,n3,n4,n5;
	scanf_s("%d", &n);
	len = log10(n) + 1;
	printf("%d\n", len);
	if (n >= 10000)
	{
		n5 = n % 10;
		n4 = (n % 100) / 10;
		n3 = (n / 100) % 10;
		n2 = (n / 1000) % 10;
		n1 = n / 10000;
		printf("%d", n1 + n2 * 10 + n3 * 100 + n4 * 1000 + n5 * 10000);
	}
	else
	{
		if (n >= 1000)
		{
			n5 = n % 10;
			n4 = (n % 100) / 10;
			n3 = (n / 100) % 10;
			n2 = (n / 1000) % 10;
			printf("%d", n2 + n3 * 10 + n4 * 100 + n5 * 1000);
		}
		else
		{
			if (n >= 100)
			{
				n5 = n % 10;
				n4 = (n % 100) / 10;
				n3 = (n / 100) % 10;
				printf("%d", n3 + n4 * 10 + n5 * 100);
			}
			else
			{
				if (n >= 10)
				{
					n5 = n % 10;
					n4 = n / 10;
					printf("%d", n4 + n5 * 10);
				}
				else
					printf("%d", n);
			}
		}
	}
	return 0;
}