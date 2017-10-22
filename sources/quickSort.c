#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define BILLION 1E9


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
   	int size;
   	int *array = NULL;
   	scanf ("%d", &size);

   	array = malloc(size*sizeof(int));

   	for (int i = 0; i < size; i++){
   		scanf ("%d", &array[i]);
   	}

   	struct timespec requestStart, requestEnd;
      clock_gettime(CLOCK_REALTIME, &requestStart);
   	
   		quickSort(array, 0,  size-1);
   	
   	clock_gettime(CLOCK_REALTIME, &requestEnd);

   	
   // Calculate time it took
    double accum = ( requestEnd.tv_sec - requestStart.tv_sec ) + ( requestEnd.tv_nsec - requestStart.tv_nsec )  / BILLION;
    printf( "%.9lf\n", accum );

   	free (array);

    return 0;
}