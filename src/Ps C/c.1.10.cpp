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
    sum = 0;//k是行数，x[k]为列数
    while (k >= 0)
    {
        x[k]++;//归0
        while (x[k] < 8 && check(k))//防止放置出界，检查与其他行是否冲突
            x[k]++;
        if (x[k] < 8 && k == 7)//最后一行放置好了，输出
        {
            for (int i = 0; i < 8; i++)
                printf("%d", x[i] + 1);
            printf("\n");
            sum++;
        }
        if (x[k] < 8 && k < 7)//此时，x[k]<8表示这一行已经放置了，进入下一行
            k++;
        else
        {
            x[k] = -1;//复原这一列的状态，回上一列重来，回溯算法
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