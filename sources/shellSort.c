#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define BILLION 1E9

void shellSort(int *vet, int size) ;

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

	shellSort(vector, size);

  clock_gettime(CLOCK_REALTIME, &requestEnd);

	double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
		+ ( requestEnd.tv_nsec - requestStart.tv_nsec )
		/ BILLION;

		printf( "%.9lf\n", accum );
}

void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}
