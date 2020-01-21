#include<stdio.h>
int main()
{
	int U = 220, R1 = 10, R2 = 10, R3 = 200, R4 = 200;
	//R单位为千欧，U单位为伏特
	double R,i1,i2,i3,i4;
	//电流单位mA
	R = 1.0/(1.0 / R1 + 1.0/ R2 + 1.0 / R3 + 1.0 / R4);
	i1 = U / R1;
	i2 = U / R2;
	i3 = U / R3;
	i4 = U / R4;
	printf("R=%lf\ni1=%lf\ni2=%lf\ni3=%lf\ni4=%lf\n", R, i1, i2, i3, i4);
	return 0;
}