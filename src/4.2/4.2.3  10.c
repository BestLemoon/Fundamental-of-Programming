#include<stdio.h>
int main()
{
	int days, week, leftday;
	scanf_s("%d", &days);
	week = days / 7;
	leftday = days - week * 7;
	printf("%dweek%dday", week,leftday);
	return 0;
}