#include<stdio.h>
int main()
{
	int a, b, c;
	scanf_s("%d%d%d", &a, &b, &c);
	if (a + b > c || b + c > a || a + c > b)
	{
		printf("Triangle!\n");
		if (a*a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
			printf("Right Triangle\n");
		else	
			if (a == b || b == c || a == c)
				printf("Isoceles triangle\n");
		
	}
	else
		printf("Not Triangle\n");
	return 0;
}