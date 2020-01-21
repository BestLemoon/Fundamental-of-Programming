#include<stdio.h>
int main()
{
	int  class_num;
	scanf_s("%d", &class_num);
	switch (class_num)
	{
		case 91:
		case 94:
		case 93:printf("30"); break;
		case 92:
		case 95:printf("32"); break;
		default:printf("No such class");
	}
	return 0;
}