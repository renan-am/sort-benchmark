#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define BILLION 1E9

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {

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

      qsort(vector, size, sizeof(int), cmpfunc);

   clock_gettime(CLOCK_REALTIME, &requestEnd);

   double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
      + ( requestEnd.tv_nsec - requestStart.tv_nsec )
      / BILLION;

      printf( "%.9lf\n", accum );

      free(vector);
  
   return(0);
}