#include<stdio.h>
#include<string.h>
#define N 1024
int main()
{
	char temp;
	char a[N];
	gets(a);
	for (int i = 0; i <strlen(a)-1 ; i++)
	{
		for (int j = 0; j <strlen(a) - i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	puts(a);
	return 0;
}