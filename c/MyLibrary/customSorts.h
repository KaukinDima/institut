
void printArr(double *arr, int n) ;
void swap( double *first, double *second );

void InsertionSort( double *arr, int *n );
void BubbleSort( double *arr, int n );
void SelectionSort( double *arr, int n);

void RecursiveInsertionSort(double *arr, int n ); 

void merge(double arr[], int l, int m, int r);
void mergeSort(double arr[], int *params);

// void CountingSort(double *arr, int n );

void QuickSort(double *arr, int n );
// void ShellSort(double *arr, int n );



struct SortResults {
   double spentTime;
   double sqr;
};


struct SortResults TimeDecorator( void (*func)(double*, int*), double *arr, int *params );
