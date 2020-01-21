#include<stdio.h>
#include<math.h>
int main()
{
	int a[20],n=0;
	for (int i = 0; i <= 19; i++)
		scanf_s("%d", &a[i]);
	for (int j = 0; j <= 19; j++)
	{
		int flag = 0;
		for (int k = 2; k <= sqrt(a[j]); k++)
		{
			if (a[j] % k == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			n++;
	}
	printf("%d", n);
	return 0;
}