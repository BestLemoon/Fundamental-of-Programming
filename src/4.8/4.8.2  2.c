#include<stdio.h>
int gcd(int numa, int numb)
{
	int min, max,temp;
	min = numa > numb ? numb : numa;
	max = numa < numb ? numb : numa;
	for (int i = 1; i <= min; i++)
	{
		if (min%i == 0 && max%i == 0)
			temp = i;
	}
	return temp;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", gcd(a, b));

	return 0;
}