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
    sum = 0;//k��������x[k]Ϊ����
    while (k >= 0)
    {
        x[k]++;//��0
        while (x[k] < 8 && check(k))//��ֹ���ó��磬������������Ƿ��ͻ
            x[k]++;
        if (x[k] < 8 && k == 7)//���һ�з��ú��ˣ����
        {
            for (int i = 0; i < 8; i++)
                printf("%d", x[i] + 1);
            printf("\n");
            sum++;
        }
        if (x[k] < 8 && k < 7)//��ʱ��x[k]<8��ʾ��һ���Ѿ������ˣ�������һ��
            k++;
        else
        {
            x[k] = -1;//��ԭ��һ�е�״̬������һ�������������㷨
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