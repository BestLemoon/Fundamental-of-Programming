#include<stdio.h>
int main()
{
	int a[5][3];
	int sum,n=0;
	float ave;
	for (int i = 0; i <= 4; i++)
		scanf_s("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	for (int i = 0; i <= 4; i++)
	{
		sum = 0;
		for (int j = 0; j <= 2; j++)
			sum += a[i][j];
		ave = sum / 3.0;
		printf("%d %f\n",sum,ave);
		if (ave < 60)
			n++;
	}
	printf("%d", n);
	return 0;
}