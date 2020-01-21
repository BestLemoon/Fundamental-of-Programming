#include<stdio.h>
int main()
{
	int a[20],b=0,c=0,d=0,e=0;
	for (int i = 0; i <= 19; i++)
		scanf_s("%d", &a[i]);
	for (int j = 0; j <= 19; j++)
	{
		if (a[j] > 0)
			b++;
		else if (a[j] == 0)
			c++;
		else
			d++ ;
	}
	printf("%d  %d  %d", b,d,c);
	return 0;
}