#include <stdio.h>
#include <math.h>


int main()
{

    int a;
    int b;
    int c = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    for(a; a <= b; a++) {
        c += a;
        printf("c : %d \n", c);
    }

    printf("sum element = %d \n", c); 

    return 0;
}
