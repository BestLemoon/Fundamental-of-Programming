#include<stdio.h>
#define N 1024
int main()
{
	char a[N],max;
	gets(a);
	max = a[0];
	for (int i = 0; i < N; i++)
	{
		if (a[i]>max)
			max = a[i];
	}
	printf("%c", &max);


	return 0;
}