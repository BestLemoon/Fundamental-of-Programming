#include<stdio.h>

int main()
{
	char a, b, c, d, e;
	a = getchar();
	b = getchar();
	c = getchar();
	d = getchar();
	e = getchar();
	if (a >= 87 && a <= 90 || a >= 119 && a <= 122)
	{
		a -= 22;
	}
	else
	{
		a += 4;
	}
	if (b >= 87 && b <= 90 || b >= 119 && b <= 122)
	{
		b -= 22;
	}
	else
	{
		b += 4;
	}
	if (c >= 87 && c <= 90 || c >= 119 && c <= 122)
	{
		c -= 22;
	}
	else
	{
		c += 4;
	}
	if (d >= 87 && d <= 90 || d >= 119 && d <= 122)
	{
		d -= 22;
	}
	else
	{
		d += 4;
	}
	if (e >= 87 && e <= 90 || e >= 119 && e <= 122)
	{
		e -= 22;
	}
	else
	{
		e += 4;
	}
	printf("%c%c%c%c%c", a, b, c, d, e);
	return 0;
}