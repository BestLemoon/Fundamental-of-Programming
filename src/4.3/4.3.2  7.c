#include<stdio.h>
int main()
{
	char a;
	scanf_s("%c", &a);
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
	{
		if (a >= 65 && a <= 90)
			printf("%c", a + 32);
		else
		{
			if (a >= 97 && a <= 122)
				printf("%c", a - 32);
		}
	}
	else
		printf("The character need not to be changed");
	return 0;
}