#include<iostream>
using namespace std;
#include<string.h>
#include<string>
#include<stdio.h>
#include<math.h>
int Num2Dec(char* str,int flag)
{
	int sum=0,j=0;
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			sum+=(str[i]-'A'+10) * pow(flag, j++);
		}
		else
			sum += (str[i]-'0') * pow(flag,j++);
	}
	return sum;
}
void Dec2Num(int num,int flag)
{
	int sum[1024], i = 0;
	do
	{
		sum[i++] = num % flag;
		num /= flag;
	} while (num!=0);
	for (int j = i - 1; j >= 0; j--)
		if (sum[j] >= 10)
			printf("%c", sum[j] - 10 + 'A');
		else
		printf("%d", sum[j]);
	printf("\n");
}
int main()
{
	char str[1024];
	int flag1 = 0,flag2=0,num;
	while (1)
	{
		printf("***********************\n");
		printf("*********�˵�**********\n");
		printf("***********************\n");
		printf("������Ҫת�������ֵ�����,����0�˳�\n");
		printf("*********2.������*******\n");
		printf("*********8.�˽���********\n");
		printf("*********10.ʮ����********\n");
		printf("*********16.ʮ������******\n");
		scanf("%d", &flag1);
		if (flag1 == 0)
			break;
		printf("***������Ҫת��������**\n");
		getchar();
		gets_s(str);
		printf("********��ѡ��*********\n");
		printf("*****2.ת��Ϊ������*****\n");
		printf("*****8.ת��Ϊ�˽���*****\n");
		printf("*****10.ת��Ϊʮ����*****\n");
		printf("*****16.ת��Ϊʮ������***\n");
		scanf("%d", &flag2);
		num = Num2Dec(str, flag1);
		Dec2Num(num, flag2);
	}
	return 0;
}