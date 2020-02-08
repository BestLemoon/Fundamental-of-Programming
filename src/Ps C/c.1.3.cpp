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
		printf("*********菜单**********\n");
		printf("***********************\n");
		printf("请输入要转换的数字的类型,输入0退出\n");
		printf("*********2.二进制*******\n");
		printf("*********8.八进制********\n");
		printf("*********10.十进制********\n");
		printf("*********16.十六进制******\n");
		scanf("%d", &flag1);
		if (flag1 == 0)
			break;
		printf("***请输入要转换的数字**\n");
		getchar();
		gets_s(str);
		printf("********请选择*********\n");
		printf("*****2.转换为二进制*****\n");
		printf("*****8.转换为八进制*****\n");
		printf("*****10.转换为十进制*****\n");
		printf("*****16.转换为十六进制***\n");
		scanf("%d", &flag2);
		num = Num2Dec(str, flag1);
		Dec2Num(num, flag2);
	}
	return 0;
}