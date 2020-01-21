#include<stdio.h>
int main()
{
	int a[3][3] = { {1,2,3}, {2,3,4},{4,5,6} };
	printf("%d", a[0][0] + a[1][1] + a[2][0] + a[0][2] + a[2][2]);
	return 0;
}