#include<stdio.h>
#include<string.h>
int cal(int x, int y, int op)
{		//x>y&&x%y==0
	switch (op)
	{
	case 1:
		return x + y;
	case 2:
		return x - y;
	case 3:
		return x * y;
	case 4:
		return x / y;
	}
}
int calc_model_1(int a, int b, int c,int d, int op1, int op2, int op3)
{//(A B)(C D)
	return cal(cal(a, b, op1), cal(c, d, op3), op2);
}
int calc_model_2(int a, int b, int c, int d, int op1, int op2, int op3)
{//(A (B C))D
	return cal(cal(cal(b,c,op2),a,op1),d, op3);
}
int calc_model_3(int a, int b, int c, int d, int op1, int op2, int op3)
{//A ((B C) D)
	return cal(a, cal(cal(b,c,op2), d, op3), op1);
}
int calc_model_4(int a, int b, int c, int d, int op1, int op2, int op3)
{//((A B) C) D
	return cal(cal(cal(a,b,op1), c, op2), d, op3);
}
int calc_model_5(int a, int b, int c, int d, int op1, int op2, int op3)
{//A (B (C D))
	return cal(a, cal(b, cal(c,d,op3), op2), op1);
}
int main()
{
	int x[4],sum=0,num1=0,num2=0,num3=0,num4=0,op1,op2,op3;
	char input[4][3],op[6] = {' ','+','-','*','/','\0' };
	for (int i = 0; i < 4; i++)
		scanf("%s", &input[i]);
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(input[i], "A") == 0)
			x[i] = 1;
		else if (strcmp(input[i], "J") == 0)
			x[i] = 11;
		else if (strcmp(input[i], "Q") == 0)
			x[i] = 12;
		else if (strcmp(input[i], "K") == 0)
			x[i] = 13;
		else if (strcmp(input[i], "10") == 0)
			x[i] = 10;
		else
			x[i] = input[i][0] - '0';
	}
	for (op1 = 1; op1 < 5; op1++)
	{
		for (op2 = 1; op2 < 5; op2++)
		{
			for (op3 = 1; op3 < 5; op3++)
			{
				for (int i = 0; i < 4; i++)
				{
					num1 = x[i];
					for (int j = 0; j < 4; j++)
					{
						if (x[j] != num1)
							num2 = x[j];
						for (int m = 0; m < 4; m++)
						{
							if (x[m] != num1 && x[m] != num2)
								num3 = x[m];
							for (int n = 0; n < 4; n++)
							{
								if (x[n] != num1 && x[n] != num2 && x[n] != num3)
									num4 = x[n];
								if (calc_model_1(num1,num2,num3,num4, op1, op2, op3) == 24)
									printf("(%d%c%d)%c(%d%c%d)\n", num1, op[op1], num2, op[op2], num3, op[op3], num4);
								if (calc_model_2(num1, num2, num3, num4, op1, op2, op3) == 24)
									printf("(%d%c(%d%c%d))%c%d\n", num1, op[op1], num2, op[op2], num3, op[op3], num4);
								if (calc_model_3(num1, num2, num3, num4, op1, op2, op3) == 24)
									printf("%d%c((%d%c%d)%c%d)\n", num1, op[op1], num2, op[op2], num3, op[op3], num4);
								if (calc_model_4(num1, num2, num3, num4, op1, op2, op3) == 24)
									printf("((%d%c%d)%c%d)%c%d\n", num1, op[op1], num2, op[op2], num3, op[op3], num4);
								if (calc_model_5(num1, num2, num3, num4, op1, op2, op3) == 24)
									printf("%d%c(%d%c(%d%c%d))\n", num1, op[op1], num2, op[op2], num3, op[op3], num4);
							}
						}
					}
				}

			}
		}
	}
	return 0;
}