#include<stdio.h>
#include<math.h>

double distance(int x1, int x2, int y1, int y2)
{
	int dis;
	dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return dis;
}
int main()
{
	int x1, x2, y1, y2;
	scanf("(%d,%d)(%d,%d)", &x1, &y1, &x2, &y2);
	printf("%lf", distance(x1,x2,y1,y2));
	return 0;

}