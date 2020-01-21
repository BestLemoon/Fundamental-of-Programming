#include<stdio.h>
#define N 5
int main()
{
	int a[N][N],row,col,max,min=0;
	for (int i = 0; i <= 4; i++)
		scanf_s("%d %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
	for (row = 0; row < N; row++)
	{
		for (max = a[row][0], col = 1; col < N; col++)
			if (a[row][col] > max)
				max = a[row][col];
		if (row == 0)
			min = max;
		else if (min > max)
			min = max;
	}

	printf("%d", min);
	return 0;
}