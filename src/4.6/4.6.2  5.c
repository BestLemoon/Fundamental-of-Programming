#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char s[1024];
	printf("Enter a string.\n");
	scanf("%s", s);
	while (i < strlen(s))
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
		i++;
	}
	printf("%s\n", s);
	return 0;
}