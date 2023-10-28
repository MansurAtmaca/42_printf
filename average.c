#include <stdarg.h>
#include <stdio.h>
void average(int num, ...)
{
    va_list args;
    va_start(args,num);
    int i= 0;
    int sum = 0;
    while (i<num)
    {
        int x = va_arg(args,int);
        sum +=x;
        i++;
    }
    printf("Result: %d", sum/num);
   va_end(args); 
}
int main()
{
    average(4,80,21,313,13);
}