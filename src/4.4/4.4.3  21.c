#include<stdio.h>
int main()
{
	int i=0;
	for (int n = 1; n <= 100; n++)
	{
		if (n % 2 != 0 && n*n % 8 == 1)
			i++;
	}
	if (i == 50)
		printf("YES");
	else
		printf("NO");

	return 0;
}