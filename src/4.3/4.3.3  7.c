#include<stdio.h>
int main()
{
	int x, y,n,sum;
	printf(" 1 ���ӷ�\n 2 ������\n 3 ���˷�\n 4 ������\n ��ѡ��\n");
	scanf_s("%d", &n);
	scanf_s("%d%d", &x, &y);
	switch (n)
	{
	case 1:
		sum = x + y;
		printf("%d", sum);
		break;
	case 2:
		sum = x - y;
		printf("%d", sum);
		break;
	case 3:
		sum = x * y;
		printf("%d", sum);
		break;
	case 4:
		if (y != 0)
		{
			sum = x / y;
			printf("%d", sum);
		}
		else
			printf("Error!");
		break;
	}
	return 0;
}