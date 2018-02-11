#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "customSorts.h"


void swap( double *first, double *second ) 
{
	double temp = *first;
	*first = *second;
	*second = temp;
}


void printArr(double *arr, int n) {
	int i;
	printf("Array \n");
	for(i=0; i < n; i++) {
		printf("%.2lf | ", arr[i]);
	}
	printf("\n");
}

void RecursiveInsertionSort(double *arr, int n ) 
{
	if(n <= 1)
		return;
	
	RecursiveInsertionSort( arr, n-1 );

	double last = *(arr + (n-1));
	int j = n-2;
	while( j >= 0 && *(arr + j) > last ) {
		*(arr + (j+1)) = *(arr + j);
		j--;
	}
	*(arr + (j+1)) = last;
}


void merge(double arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	double L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(double arr[], int *params)
{
	int l = *(params);
	int r = *(params + 1);

	if (l < r)
	{
		int m = l+(r-l)/2;

		mergeSort(arr, (int[]) {l, m} );
		mergeSort(arr, (int[]) {m+1, r} );

		merge(arr, l, m, r);
	}
}

void QuickSort(double *arr, int n ) 
{
	
}

// void ShellSort(double *arr, int n ) 
// {

// }

// void CountingSort(double *arr, int n ) 
// {

// }

void SelectionSort( double *arr, int n) 
{	
	int i, j, min_idx;
	j = n+1;
	for(i=0; i < n-1; i++)
	{
		min_idx = i;
		for( j = i+1; j < n; j++)
			if( *(arr + j) < *(arr + min_idx) )
				min_idx = j;
		
		swap( &*(arr + min_idx), &*(arr + i ));
	}
}


void BubbleSort( double *arr, int n )
{
	int i, j;
	for(i=0; i < n-1; i++) 
		for(j=0; j<n-i -1; j++ ) 
			if ( arr[j] > arr[j+1] ) 
				swap( &*(arr + j) , &*(arr + (j+1) ) );
}


void InsertionSort( double *arr, int *n ) {
	
	double key;
	int i, j;
	for (i = 1; i < *(n); i++)
   	{
		key = *(arr + i);
		j = i-1;


		while (j >= 0 && *(arr + j) > key)
    	{
			*(arr + (j+1)) = *(arr + j);
			j = j-1;
       	}

       	*(arr + (j+1)) = key;
   }

}

struct SortResults TimeDecorator( void (*func)(double*, int*), double *arr, int *params )
{
	struct SortResults res;
	double start = (double) clock();
	func(arr, params);
	res.spentTime = (clock() - start) / CLOCKS_PER_SEC;

	return res;
}