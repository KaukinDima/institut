#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool simpleNum( int a ) {

    int i;
    for( i=2; i < a; i++ ) {
        if( a % i == 0 ) 
            return false;
    }

    return true;
}

int main() {

    int a;
    int b;

    printf("prime numbers between range, write two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("\n Prime numbers between %d - %d are :", a, b);

    for(a; a <= b; a++) {
        if(simpleNum(a))
            printf("%d ,", a);        
    }

    return 0;
}