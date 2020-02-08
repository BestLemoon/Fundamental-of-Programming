#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int num,n;
	long  nn,npow;
	while (1)
	{
		printf("***************************\n");
		printf("判断是否为自守数，按0退出\n");
		printf("***************************\n");
		scanf("%d", &num);
		if (num == 0)
			exit(0);
		else
		{
			nn = num * num;
			n = log10(num) + 1;//判断位数
			npow = pow(10, n);
			if (nn % npow == num)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}