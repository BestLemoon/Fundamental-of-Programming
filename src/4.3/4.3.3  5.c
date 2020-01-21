#include<stdio.h>
int main()
{
	int y, m, d;
	printf("请输入日期如(2019-10-25)");
	scanf_s("%d-%d-%d", &y, &m, &d);
	//判断是否为闰年
	if (y % 4 == 0 && y % 100 != 0)
	{//闰年
		switch (m)
		{
		case 1:
			printf("It's the %dth day of %d", d, y);
			break;
		case 2:
			d = d + 31;
			printf("It's the %dth day of %d", d, y);
			break;
		case 3:
			d = d + 60;
			printf("It's the %dth day of %d", d, y);
			break;
		case 4:
			d = d + 91;
			printf("It's the %dth day of %d", d, y);
			break;
		case 5:
			d = d + 121;
			printf("It's the %dth day of %d", d, y);
			break;
		case 6:
			d = d + 152;
			printf("It's the %dth day of %d", d, y);
			break;
		case 7:
			d = d + 182;
			printf("It's the %dth day of %d", d, y);
			break;
		case 8:
			d = d + 213;
			printf("It's the %dth day of %d", d, y);
			break;
		case 9:
			d = d +244;
			printf("It's the %dth day of %d", d, y);
			break;
		case 10:
			d = d + 274;
			printf("It's the %dth day of %d", d, y);
			break;
		case 11:
			d = d + 305;
			printf("It's the %dth day of %d", d, y);
			break;
		case 12:
			d = d + 335;
			printf("It's the %dth day of %d", d, y);
			break;
		}
	}
	else//平年
	{
		switch (m)
		{
		case 1:
			printf("It's the %dth day of %d", d, y);
			break;
		case 2:
			d = d + 31;
			printf("It's the %dth day of %d", d, y);
			break;
		case 3:
			d = d + 59;
			printf("It's the %dth day of %d", d, y);
			break;
		case 4:
			d = d + 90;
			printf("It's the %dth day of %d", d, y);
			break;
		case 5:
			d = d + 120;
			printf("It's the %dth day of %d", d, y);
			break;
		case 6:
			d = d + 151;
			printf("It's the %dth day of %d", d, y);
			break;
		case 7:
			d = d + 181;
			printf("It's the %dth day of %d", d, y);
			break;
		case 8:
			d = d + 212;
			printf("It's the %dth day of %d", d, y);
			break;
		case 9:
			d = d + 243;
			printf("It's the %dth day of %d", d, y);
			break;
		case 10:
			d = d + 273;
			printf("It's the %dth day of %d", d, y);
			break;
		case 11:
			d = d + 304;
			printf("It's the %dth day of %d", d, y);
			break;
		case 12:
			d = d + 334;
			printf("It's the %dth day of %d", d, y);
			break;
		}

	}
	return 0;
}