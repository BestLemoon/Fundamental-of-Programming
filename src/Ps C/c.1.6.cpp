#include<stdio.h>
int main()
{
	int a, b, c, d,result1,result2,num=0;
	printf("�������һ�������ķ���\n");
	scanf("%d", &a);
	printf("�������һ�������ķ�ĸ\n");
	scanf("%d", &b);
	printf("������ڶ��������ķ���\n");
	scanf("%d", &c);
	printf("������ڶ��������ķ�ĸ\n");
	scanf("%d", &d);
	result1 = (a * d + b * c);
	result2 = b * d;
	for (int i = 2; i <= result2; i++)
	{
		if (result1 % i == 0 && result2 % i == 0)
		{
			result1 %= i;
			result2 %= i;
		}
	}
	while (result1 > result2)
	{
		result1 -= result2;
		num++;
	}
	if(num)
		printf("%d ", num);
	printf("%d/%d", result1,result2);
	return 0;
}