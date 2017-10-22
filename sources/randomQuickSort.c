#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define BILLION 1E9

void random_quick_sort(int arr[], int p, int q);
int partion(int arr[], int p, int r);
void swap(int *a, int *b);

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

	random_quick_sort(vector, 0, size-1);

  clock_gettime(CLOCK_REALTIME, &requestEnd);

	double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
		+ ( requestEnd.tv_nsec - requestStart.tv_nsec )
		/ BILLION;

		printf( "%.9lf\n", accum );

}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partion(int arr[], int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
    int pivot;
    int i = p - 1;
    int j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }

    }
    swap(&arr[i+1], &arr[r]);
    return i + 1;
}

void random_quick_sort(int arr[], int p, int q)
{
    int j;
    if (p < q)
    {
        j = partion(arr, p, q);
        random_quick_sort(arr, p, j-1);
        random_quick_sort(arr, j+1, q);
    }
}
