#include<stdio.h>
#define N 1024
int main()
{
	char a[N], b[N];
	gets(a);
	for (int i = 0; i < N; i++)
	{
		b[i] = a[i];
	}
	puts(b);

	return 0;
}