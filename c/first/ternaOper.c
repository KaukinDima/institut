#include <stdio.h>
#include <math.h>


int main()
{
    int a;
    int b;
    int c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    printf("max elem = %d \n", (a > b && a > c ) ? a : (b > c) ? b : c ); 

    return 0;
}
