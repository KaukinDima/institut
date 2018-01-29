#include <stdio.h>      
#include <math.h>      
 
int main()
{
    float a;
    float b;
    int res;

    printf("write number and ^^ \n");

    scanf("%fl", &a);
    scanf("%fl", &b);

    res = pow(a,b);
    printf("result %d \n", res);

}