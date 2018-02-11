#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../../../MyLibrary/customSorts.h"

#define DATA_FILE	"DataFile.txt"
#define INPUT_SIZE	512		// reasonably large for a line containing one double


double *read_file(const char *file_name, size_t *size);


int main(void)
{
    size_t num;
	int i;
	double *array = read_file(DATA_FILE, &num);

	double test[1000];
	srand(time(NULL));

	for(i=0; i < 1000; i++)
		test[i] = (double) rand();

	int length = sizeof(test) / sizeof(double);

	struct SortResults res = TimeDecorator(InsertionSort, test, (int[]) { length } ); 
	struct SortResults res1 = TimeDecorator(mergeSort, test, (int[]) { 0, length - 1 } ); 
	struct SortResults res2 = TimeDecorator(InsertionSort, array, (int[]) { num } ); 
	struct SortResults res3 = TimeDecorator(mergeSort, array, (int[]) { 0, num - 1 } ); 

	printf("InsertionSort time : %lf (1000) | MergeSort time : %lf (1000) |\n", res.spentTime, res1.spentTime );
	printf("InsertionSort time : %lf (~15) | MergeSort time : %lf (~15) |\n", res2.spentTime, res3.spentTime );

    free(array);
}

double *read_file(const char *file_name, size_t *size)
{
	FILE *fp = fopen(file_name, "r");
	if (fp == NULL) {
		fprintf(stderr, "Unable to open %s for reading\n", file_name);
		return NULL;
	}

	char input[INPUT_SIZE];		
	int num = 0;				

	while(fgets(input, INPUT_SIZE, fp) != NULL) {
		num ++;
	}
	rewind(fp);	

	*size = num;

	double *array = (double *)malloc(num * sizeof(double));
	if(!array) {
		fprintf(stderr, "Unable to allocate %ld bytes for file buffer\n", (long) num);
		return NULL;
	}

	int i;
	bool have_error = false;
	for (i=0; i<num && !have_error; i++) {
		if(fgets(input, INPUT_SIZE, fp) == NULL) {
			fprintf(stderr, "Unable to read values from %s\n", DATA_FILE);
			have_error = true;
		}
		if(sscanf(input, "%lf", &array[i]) != 1) {
			fprintf(stderr, "Line %d of %s does not contain a valid floating point number\n", i+1, DATA_FILE);
			have_error = true;
		}
	}

	fclose(fp);

	if (have_error) {
		free(array);
		array = NULL;
		*size = 0;
	}

    return array;
}

