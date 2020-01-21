#include<stdio.h>
int main()
{
	int a[10],flag=1,temp;
	for (int i = 0; i <= 9; i++)
		scanf_s("%d", &a[i]);
	for (int i = 1; i < 10 && flag; ++i) {
		flag = 0;
		for (int j = 0; j < 10 - i; ++j) {
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}