#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define BILLION 1E9

 void mergeSort(int vetor[], int comeco, int fim);
 void merge(int vetor[], int comeco, int meio, int fim);

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

	mergeSort(vector,0 , size -1);

  clock_gettime(CLOCK_REALTIME, &requestEnd);

	double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
		+ ( requestEnd.tv_nsec - requestStart.tv_nsec )
		/ BILLION;

		printf( "%.9lf\n", accum );

}

void merge(int vetor[], int comeco, int meio, int fim) {
     int com1 = comeco, com2 = meio+1, comAux = 0;
     int vetAux[fim-comeco+1];

    while(com1<=meio && com2<=fim){
         if(vetor[com1] <= vetor[com2]){
             vetAux[comAux] = vetor[com1];
             com1++;
         }else{
             vetAux[comAux] = vetor[com2];
             com2++;
         }
         comAux++;
     }

     while(com1<=meio){  //Caso ainda haja elementos na primeira metade
         vetAux[comAux] = vetor[com1];
         comAux++;com1++;
     }

     while(com2<=fim){   //Caso ainda haja elementos na segunda metade
         vetAux[comAux] = vetor[com2];
         comAux++;com2++;
     }

     for(comAux=comeco;comAux<=fim;comAux++){    //Move os elementos de volta para o vetor original
         vetor[comAux] = vetAux[comAux-comeco];
     }
 }

 void mergeSort(int vetor[], int comeco, int fim){
     if (comeco < fim) {
         int meio = (fim+comeco)/2;

         mergeSort(vetor, comeco, meio);
         mergeSort(vetor, meio+1, fim);
         merge(vetor, comeco, meio, fim);
     }
 }
