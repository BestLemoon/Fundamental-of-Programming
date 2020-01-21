#include<stdio.h>
int main()
{
	float score;
	scanf_s("%f", &score);
	if (score <= 0 || score >= 100)
		printf("Wrong Input");
	else
	{
		if (score < 60)
			printf("\'E\'");
		else
		{
			if (score <= 69)
				printf("\'D\'");
			else
			{
				if (score <= 79)
					printf("\'C\'");
				else
				{
					if (score <= 89)
						printf("\'B\'");
					else
						printf("\'A\'");
				}
			}
		}
	}
	return 0;
}