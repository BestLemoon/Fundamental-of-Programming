#include<stdio.h>
int main()
{
	int a[5],b[5],temp;
	for (int i = 0; i <= 4; i++)
		scanf_s("%d", &a[i]);
	for (int i = 0; i <= 4; i++)
		b[i] = a[i];
	for (int i = 0; i <= 4; i++)
	{
		a[4 - i] = b[i];
	}
	for (int i = 0; i <= 4; i++)
		printf("%d ",b[i]);
	printf("\n");
	for (int i = 0; i <= 4; i++)
		printf("%d ", a[i]);



	return 0;
}