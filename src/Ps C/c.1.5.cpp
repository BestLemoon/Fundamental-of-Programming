#include <stdio.h>
#include <malloc.h>
int* pn;
int num;
void output()
{
	int i = 1;
	if (pn[0] != num)
	{
		printf("%d=%d", num, pn[0]);
		while (pn[i] != 0 && i < num)
			printf("+%d", pn[i++]);
		printf("\n");
	}
}
void decompose(int num, int* pn, int max)
{
	int i;
	if (num <= max)
	{
		pn[0] = num;
		output();
	}
	for (i = (max < num ? max : num - 1); i > 0; i--)
	{
		pn[0] = i;
		decompose(num - i, &pn[1], i);
	}
	pn[0] = 0;
}
void main()
{
	int i;
	scanf("%d", &num);
	pn = (int*)malloc(sizeof(int) * num);
	for (i = 0; i < num; i++) 
		pn[i] = 0;
	decompose(num, pn, num);
}
