#include<iostream>
int DigitalProductRoot(int num)
{
	int sum = 1, tmp;
	do
	{
		tmp = num % 10;
		if (tmp != 0)
			sum *= tmp;
		num /= 10;
	} while (num != 0);
	return sum;
}
int main()
{
	int num;
	scanf("%d", &num);
	do
	{
		num = DigitalProductRoot(num);
	} while (!(num>=1&&num<=9));
	printf("%d", num);
	return 0;
}