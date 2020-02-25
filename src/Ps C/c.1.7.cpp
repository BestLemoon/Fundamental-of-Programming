#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int num1, num2, flag,k=0,flag1=0, result, result_usr, n, score = 0, right_num = 0, wrong_num = 0, done_num[100][2];
	srand((unsigned)time(NULL));
	printf("请输入题目数量\n");
	scanf("%d", &n);
	for (int i = 0; i < 100; i++)
	{
		for (int m = 0; m < 2; m++)
			done_num[i][m] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		num1 = rand() % 102+1;
		num2 = rand() % 102+1;
		flag = rand() % 2;
		for (int n = 0; n < 100; n++)
			if (done_num[n][0] == num2 && done_num[n][1] == num1)
				flag1 = 1;
		if (flag1==0&&flag==1&&num1 * num2 <= 100||flag==0&&num1%num2==0&&num1>=num2)
		{
			done_num[k][0] = num2;
			done_num[k++][1] = num1;
			printf("%d", num1);
			if (flag)
			{
				printf("*");
				result = num1 * num2;
			}
			else
			{
				printf("/");
				result = num1 /  num2;
			}
			printf("%d=\n", num2);
			printf("请输入答案\n");
			scanf("%d", &result_usr);
			if (result_usr == result)
			{
				score += 10;
				right_num++;
			}
			else
				wrong_num++;
		}
		else
			n++;
	}
	printf("答对%d题，答错%d题，得分%d\n", right_num, wrong_num, score);
	return 0;
}