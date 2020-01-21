//注意:代码模板中的代码将会被复制到任何新创建的文件中，编辑代码模板中的代码，让他帮你自动增加固定代码吧
#include <stdio.h> 
int main()
{
    float a,b,c,p,s;
    scanf("%f%f%f",&a,&b,&c);
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%f",s);
    return 0;
}