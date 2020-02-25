#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int leap_months[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int other_months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int is_leap_year(int year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int maxDay(int year, int month) 
{
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; 
	if (is_leap_year(year))
		a[1] = 29; 
	return a[month - 1];
}
int eachyeartotal(int year, int month, int day) 
{
	int i, sum = 0;
	for (i = 1; i < month; i++)
		sum += maxDay(year, i);
	sum += day;
	return sum;
}
int week(int year, int month, int day) 
{
	int number = (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400
		+ eachyeartotal(year, month, day);
	number = number % 7;
	return number;
}
void print_month(int year, int month)
{
	int num, i,max;
	num = week(year, month, 1);
	printf("                 %d 年  %d 月 \n\n", year, month);
	printf("   %4s  %4s  %4s  %4s  %4s  %4s  %4s\n","Sun","Mon", "Tue", "Wen", "Thu", "Fri", "Sat");
	for (i = 0; i < num; i++)
		printf("      ");
	if (is_leap_year(year))
		max = leap_months[month - 1];
	else
		max = other_months[month - 1];
	for (int j = 1; j <= max; j++)
	{
		printf("%6d", j);
		if (i % 7 == 6)
			printf("\n");
		i++;
	}
}
void print_year(int year)
{
	for (int i = 1; i <= 12; i++)
	{
		printf("\n");
		print_month(year, i);
	}
}
void whichday(int year, int month, int day) //判断是星期几
{
	int number;
	number = (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + eachyeartotal(year, month, day);
	number = number % 7;
	switch (number)
	{
	case 0:
		printf("\n %d 年%d 月%d 日是星期日", year, month, day); break;
	case 1:
		printf("\n %d 年%d 月%d 日是星期一", year, month, day); break;
	case 2:
		printf("\n %d 年%d 月%d 日是星期二", year, month, day); break;
	case 3:
		printf("\n %d 年%d 月%d 日是星期三", year, month, day); break;
	case 4:
		printf("\n %d 年%d 月%d 日是星期四", year, month, day); break;
	case 5:
		printf("\n %d 年%d 月%d 日是星期五", year, month, day); break;
	case 6:
		printf("\n %d 年%d 月%d 日是星期六", year, month, day); break;
	default:
		system("cls");
		printf(" 出现错误!\n");
	}
}
void specialday(int month, int day) //判断是否公历节日
{
	if (month == 1)
		switch (day)
		{
		case 1:
			printf(", 这天是元旦");
		}
	if (month == 2)
		switch (day)
		{
		case 14:
			printf(", 这天是情人节");
		}
	if (month == 3)
		switch (day)
		{
		case 8:
			printf(", 这天是妇女节");
			break;
		case 12:
			printf(", 这天是植树节");
		}
	if (month == 4)
		switch (day)
		{
		case 1:
			printf(", 这天是愚人节");
		}
	if (month == 5)
		switch (day)
		{
		case 1:
			printf(", 这天是劳动节");
			break;
		case 4:
			printf(", 这天是青年节");
		}
	if (month == 6)
		switch (day)
		{
		case 1:
			printf(", 这天是儿童节");
		}
	if (month == 7)
		switch (day)
		{
		case 1:
			printf(", 这天是建党节");
		}
	if (month == 8)
		switch (day)
		{
		case 1:
			printf(", 这天是建军节");
		}
	if (month == 9)
		switch (day)
		{
		case 10:
			printf(", 这天是教师节");
		}
	if (month == 10)
		switch (day)
		{
		case 1:
			printf(", 这天是国庆节");
		}
}
int counterdays(int year, int month, int day) 
{
	int year1, days0, days1, month1, days, day1;
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	year1 = (1900 + p->tm_year);
	month1 = (1 + p->tm_mon);
	day1 = (p->tm_mday); 
	days0 = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + eachyeartotal(year, month,day);
	days1 = (year1 - 1) * 365 + (year1 - 1) / 4 - (year1 - 1) / 100 + (year1 - 1) / 400 + eachyeartotal(year1,month1, day1);
	days = days0 - days1; //计算出两个日期之间的时间差
	printf("\n 今天距%d 年%d 月%d 日还有%d 天",year,month,day,days);
	return days;
}
int main()
{
	int a,y,m,d;
	printf("  万年历  \n");
	printf("请选择：\n");
	printf("1.年历\n");
	printf("2.月历\n");
	printf("3.计算日期间距\n");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("请输入年份：\n");
		scanf("%d", &y);
		system("cls");
		print_year(y);
		break;
	case 2:
		printf("请输入年份：\n");
		scanf("%d", &y);
		printf("请输入月份：\n");
		scanf("%d", &m);
		system("cls");
		print_month(y, m);
		break;
	case 3:
		printf("请输入年份：\n");
		scanf("%d", &y);
		printf("请输入月份：\n");
		scanf("%d", &m);
		printf("请输入日：\n");
		scanf("%d", &d);
		system("cls");
		counterdays(y, m, d);
		whichday(y, m, d);
		specialday(m, d);
		break;
	}
	return 0;
}