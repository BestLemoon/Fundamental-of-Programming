#include<stdio.h>
int main()
{
	int a[5],b[5],temp1,temp2;
	for (int i = 0; i <= 4; i++)
		scanf_s("%d", &a[i]);
	for (int i = 0; i <= 4; i++)
		b[i] = i + 1;
	for (int m = 0; m <= 3; m++)
	{
		for (int j = 0; j <= 3-m; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp1 = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp1;
				temp2 = b[j + 1];
				b[j + 1] = b[j];
				b[j] = temp2;
			}
		}
	}
	for (int k = 0; k <= 4; k++)
		printf("%d %d\n",a[k],b[k]);
	return 0;
}