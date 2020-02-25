#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
#include<string.h>
#define N 1001
#define MAX 2002
int Add(char *a, char *b)
{
	/*hjggggggggggg
	ljkkjjlk
	lkjlkjk*/
	char c[N];
	int alen, blen, i, aa, sign=0, d[N + 1] = { 0 },tmp;
	alen = strlen(a);
	blen = strlen(b);
	if (alen > blen)//a较大 swap,总长度为a的长度
	{
		c[alen] = '\0';
		for (i = 0; i < alen; i++)
		{
			c[i] = a[i];
			a[i] = b[i];
			b[i] = c[i];
		}
		b[i] = '\0';
	}
	alen = strlen(a);
	blen = strlen(b);
	aa = alen;
	//a is smaller num while b is larger
	for (int j = blen; j >= blen - alen; j--)
		a[j] = a[aa--];
	for (int j = 0; j <= blen - alen-1; j++)
		a[j] = '0';
	a[blen] = '\0';
	//对齐a和b
	for (int i = blen-1; i >0 ; i--)
	{
		if ((a[i] + b[i]+d[i]- '0'*2) >= 10)
		{
			d[i] = (a[i] + b[i]+d[i] - '0' * 2)%10;
			sign = 1;
			d[i - 1]++;
		}
		else
			d[i] += a[i] + b[i]-'0'*2;
	}
	if (alen != blen)
	{
		for (int i = 0; i < blen - alen; i++)
		{
			if ((b[i] + d[i] - '0') >= 10)
			{
				tmp = (b[i] + d[i] - '0') / 10;
				d[i] = (b[i] + d[i] - '0') % 10;
				sign = 2;
			}
			else
				d[i] += b[i] - '0';
		}
	}
	else
	{
		if ((b[0] + d[0]+a[0] - 2*'0') >= 10)
		{
			tmp = (b[0] + d[0] + a[0] - 2 * '0') / 10;
			d[0] = (b[0] + d[0] + a[0] - 2 * '0') % 10;
			sign = 2;
		}
		else
			d[0] += a[0]+b[0] - 2*'0';
		
	}
	if (sign == 2)
		printf("%d", tmp);
	for (int i = 0; i < blen; i++)
		printf("%d", d[i]);
	printf("\n");
	return 0;
}

int Minus(char* a, char* b)
{
	char c[N];
	int alen, blen, i, k=0,aa, sign = 0, d[N + 1] = { 0 },flag=0;
	alen = strlen(a);
	blen = strlen(b);
	if (strcmp(a,b)>=0)//a较大 swap,总长度为a的长度
	{
		flag = 1;
		c[alen] = '\0';
		for (i = 0; i < alen; i++)
		{
			c[i] = a[i];
			a[i] = b[i];
			b[i] = c[i];
		}
		b[i] = '\0';
	}
	alen = strlen(a);
	blen = strlen(b);
	aa = alen;
	//a is smaller num while b is larger
	for (int j = blen; j >= blen - alen; j--)
		a[j] = a[aa--];
	for (int j = 0; j <= blen - alen - 1; j++)
		a[j] = '0';
	a[blen] = '\0';
	//对齐a和b
	for (int i = blen - 1; i >= 0; i--)
	{
		if (b[i] < a[i]&&b[i-1]!=-52)
		{
			b[i - 1]--;
			d[i] = b[i] - '0' + 10 - (a[i] - '0');
		}
		else if(b[i]>=a[i])
			d[i] = b[i] - '0' - (a[i] - '0');
		else
		{
			d[i] = b[i] - '0' - (a[i] - '0');
		}
	}
	k = blen-1;
	for (int i = 0; i < blen; i++)
		if (d[i] != 0)
		{
			k = i;
			break;
		}
	if (flag == 0)
		printf("-");
	for(int i=k;i<blen;i++)
		printf("%d", d[i]);
	printf("\n");
	return 0;
}


int main()
{
	char a[N], b[N],str[MAX];//a为较小数
	int k,x=0,y=0,flag=0;
	printf("请输入表达式：");
	scanf("%s", str);
	for (k = 0; k < strlen(str); k++)
	{
		if (str[k] >= '0' && str[k] <= '9')
			a[x++] = str[k];
		else if (str[k] == '+')
			flag = 1;
		else if (str[k] == '-')
			flag = 2;
		if (flag != 0)
			break;
	}
	for (int n = k+1; n < strlen(str); n++)
	{
		b[y++] = str[n];
	}
	a[x] = '\0';
	b[y] = '\0';
	if (flag == 1)
		Add(a, b);
	else if (flag == 2)
		Minus(a, b);
	return 0;
}