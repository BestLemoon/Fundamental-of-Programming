#include<iostream>
#include<stdlib.h>
int x[8]= { -1 };
int sum; 
int check(int k) 
{ 
    for (int i = 0; i < k; i++)
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k)) 
            return 1;
    return 0;
}
void queen() 
{
    int k = 0;            
    sum = 0;
    while (k >= 0)  // k为行数，x[k]为列数
    {
        x[k]++;           
        while (x[k] < 8 && check(k))     //这一列不能放下，放下一列
            x[k]++;    
        if (x[k] < 8 && k == 7)//最后一行的时候，此时这一行已经放置，输出一种情况
        {
            for (int i = 0; i < 8; i++)
                printf("%d ", x[i] + 1);
            printf("\n");
            sum++;
        }
        if (x[k] < 8 && k < 7) //此时，x[k]<8表示这一行已经放置了，进入下一行    
            k++;
        else      //x[k]>=8，说明这一行放不下了，回溯上一行              
        {
            x[k] = -1;
            k--;
        }
    }
}
int main() 
{
    queen();
    printf("解的个数:%d",sum);
    return 0;
}