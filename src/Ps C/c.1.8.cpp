#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int num1, num2,num3, flag1,flag2,flag3=0,tmp, k = 0, result, result_usr, n, score = 0, right_num = 0, wrong_num = 0, done_num[101][3];
	srand((unsigned)time(NULL));
	printf("请输入题目数量\n");
	scanf("%d", &n);
	for (int i = 0; i < 101; i++)
		for (int m = 0; m < 3; m++)
			done_num[i][m] = 0;
	for (int i = 0; i < n; i++)
	{
		num1 = rand() % 102 + 1;
		num2 = rand() % 102 + 1;
		num3 = rand() % 102 + 1;
		flag1 = rand() % 2;
		flag2 = rand() % 2;
		if (num1 > num2)
		{
			tmp = num2;
			num2 = num1;
			num1 = tmp;
		}
		if (num2 > num3)
		{
			tmp = num3;
			num3 = num2;
			num2 = tmp;
		}//num1<num2<num3
		for (int a = 0; a < 100; a++)
			if (done_num[a][0] == num1 && done_num[a][1] == num2 && done_num[a][2] == num3)
				flag3 = 1;
	
	
			if (flag3 != 1)，
			{
				result = num1;
				printf("%d", num1);
				if (flag1)
				{
					printf("+");
					result += num2;
				}
				else
				{
					printf("-");
					result -= num2;
				}
				if (result > 100 || result < 0)
				{
					n++;
					system("cls");
					continue;
				}
				printf("%d", num2);
				if (flag2)
				{
					printf("+");
					result += num3;
				}
				else
				{
					printf("-");
					result -= num3;
				}
				if (result > 100 || result < 0)
				{
					n++;
					system("cls");
					continue;
				}
				printf("%d=\n", num3);
				scanf("%d", &result_usr);
				if (result == result_usr)
				{
					score += 10;
					right_num++;
				}
				else
					wrong_num++;

			}
		

	}
	printf("答对%d题，答错%d题，得分%d\n", right_num, wrong_num, score);
	return 0;
}