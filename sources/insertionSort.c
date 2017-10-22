#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define BILLION 1E9

void insertionSort(int original[], int length);

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

	insertionSort(vector, size);

  clock_gettime(CLOCK_REALTIME, &requestEnd);

	double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
		+ ( requestEnd.tv_nsec - requestStart.tv_nsec )
		/ BILLION;

		printf( "%.9lf\n", accum );
}

void insertionSort(int original[], int length){
	int i, j, atual;

	for (i = 1; i < length; i++) {
		atual = original[i];


		for (j = i - 1; (j >= 0) && (atual < original[j]); j--) {
			original[j + 1] = original[j];
        }

		original[j+1] = atual;
	}

}
