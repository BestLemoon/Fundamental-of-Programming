#include<stdio.h>
#define N 1024
int main()
{
	int n,c=0,b=0;
	char a[N];
	printf("pls enter thestring\n");
	gets(a);
	for (int j = 0; j < N; j++)
	{
		if (a[j] >= 'a' && a[j] <= 'z')
			b++;
		else if (a[j] >= 'A' && a[j] <= 'Z')
			c++;
	}
	printf("upper=%d,", c);
	printf("lower=%d\n", b);
	return 0;
}