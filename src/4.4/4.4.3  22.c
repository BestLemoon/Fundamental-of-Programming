#include<stdio.h>
int main()
{
	int b,flag;
	for (int n = 2; n <= 100; n++)
	{
		flag = 0;
		b = 0;
		for (int i = 2; i <=n/2; i++)
		{
			if (n%i == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("%d ", n);

	}
	

	return 0;
}