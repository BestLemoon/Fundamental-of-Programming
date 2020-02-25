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
    while (k >= 0)  // kΪ������x[k]Ϊ����
    {
        x[k]++;           
        while (x[k] < 8 && check(k))     //��һ�в��ܷ��£�����һ��
            x[k]++;    
        if (x[k] < 8 && k == 7)//���һ�е�ʱ�򣬴�ʱ��һ���Ѿ����ã����һ�����
        {
            for (int i = 0; i < 8; i++)
                printf("%d ", x[i] + 1);
            printf("\n");
            sum++;
        }
        if (x[k] < 8 && k < 7) //��ʱ��x[k]<8��ʾ��һ���Ѿ������ˣ�������һ��    
            k++;
        else      //x[k]>=8��˵����һ�зŲ����ˣ�������һ��              
        {
            x[k] = -1;
            k--;
        }
    }
}
int main() 
{
    queen();
    printf("��ĸ���:%d",sum);
    return 0;
}