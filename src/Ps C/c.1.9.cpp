#include<string.h>
#include<string>
#include<stdio.h>
#include<math.h>
void Dec2Num(int num)
{
	int sum[1024], i,tag, b,tmp,flag[4] = { 2,8,10,16 };
	for (int m = 0; m < 4; m++)
	{
		b = num;
		i = 0;
		tag = 0;
		do
		{
			sum[i++] = b % flag[m];
			b /= flag[m];
		} while (b != 0);
		for (int j = 0; j < i / 2; j++)
		{
			if (sum[j] != sum[i - 1 - j])
				tag = 1;
		}
		if (tag == 0)
		{
			printf("%d����,", flag[m]);
			for (int n = 0; n < i; n++)
			{
				if (sum[n] >= 10)
					printf("%c", sum[n] - 10 + 'A');
				else
					printf("%d", sum[n]);
			}
			printf("\n");
		}
	}
}
int main()
{
	int a;
	while (1)
	{
		printf("����Ҫ�жϵ�����:\n");
		printf("��0�˳�\n");
		scanf("%d", &a);
		if (a == 0)
			exit(0);
		else
			Dec2Num(a);
		printf("���س��Լ���\n");
		getchar();
		getchar();
		system("cls");
	}
	return 0;
}