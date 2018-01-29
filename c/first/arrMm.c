#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}



int main() {

    char str[100];
    char** arr;

    printf("Напишите числа через запятую без пробелов");
    scanf("%s", str);

    arr = str_split(str, ',');

    int min = atoi(arr[0]);
    int max = atoi(arr[0]);

    if (arr)
    {
        int i;
        for (i = 0; *(arr + i); i++)
        {
            if( atoi(arr[i]) > max ) {
                max = atoi(arr[i]);
            }
            if ( atoi(arr[i]) < min ) {
                min = atoi(arr[i]);
            }

        }
        printf("\n min - %d \n max - %d \n", min, max);
    }

    return 0;
}