#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define BILLION 1E9

void selection_sort(int num[], int tam);

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

	selection_sort(vector, size);

  clock_gettime(CLOCK_REALTIME, &requestEnd);

	double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
		+ ( requestEnd.tv_nsec - requestStart.tv_nsec )
		/ BILLION;

		printf( "%.9lf\n", accum );

}

void selection_sort(int num[], int tam) {
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min])
         min = j;
     }
     if (num[i] != num[min]) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}
