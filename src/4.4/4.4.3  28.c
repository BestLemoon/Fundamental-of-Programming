#include<stdio.h>
int main()
{
	char c;
	int x=0, y=0, z=0,space=0;
	for (int n = 1;; n++)
	{
		scanf_s("%c", &c);
		if (c == '#')
			break;
		else if (c >= 65 && c <= 91 || c >= 97 && c <= 123)
			x++;
		else if (c >= 48 && c <= 57)
			y++;
		else if (c == 32)
			space++;
		else
			z++;
	}
	printf("%d %d %d %d", space, x, y, z);
	return 0;
}