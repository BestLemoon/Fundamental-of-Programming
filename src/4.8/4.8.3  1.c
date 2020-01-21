#include<stdio.h>
int findmax(int n1, int n2, int n3)
{	
	int max;
	max = n1 > n2 ? n1 : n2;
	max = n2 > n3 ? n2 : n3;
}
int main()
{
	int n1, n2, n3;
	scanf("%d%d%d", &n1, &n2, &n3);
	printf("%d", findmax(n1, n2, n3));
}