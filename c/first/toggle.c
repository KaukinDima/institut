#include <stdio.h>
// #include <curses.h>

int main()
{
    char str[100];
    int i;

    printf("Please, Enter the String \n");

    scanf("%s", str);

    for(i=0; str[i] != '\0' ;i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
        else if(str[i]>='a' && str[i]<='z')
            str[i]-=32;
    }

    printf("\nThe toggle case string is = %s \n \n",str);

    return 0;

}
