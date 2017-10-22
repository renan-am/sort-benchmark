#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define BILLION 1E9

void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);

int main(){

	struct timespec requestStart, requestEnd;
	int *vector = NULL;
	int size, aux;

	scanf("%d",&size);

	vector = malloc(size*sizeof(int));

	for(int i = 0; i < size; i++){
		scanf("%d",&aux);
		vector[i] = aux;
	}

	clock_gettime(CLOCK_REALTIME, &requestStart);

	bubbleSort(vector, size);

  clock_gettime(CLOCK_REALTIME, &requestEnd);

	double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
		+ ( requestEnd.tv_nsec - requestStart.tv_nsec )
		/ BILLION;

		printf( "%.9lf\n", accum );

		free(vector);
}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
