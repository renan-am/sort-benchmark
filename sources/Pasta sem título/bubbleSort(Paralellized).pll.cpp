#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include <chrono>
#include <thread>
#include <atomic>
using namespace std::chrono;

#define BILLION 1E9

void bubble_sort_iteration(int size, int *vecA, int *vecB, int i) 
{
	int cont = 0;
	for (int k = 0; k < size; k++){
		if ( vecA[i] > vecA[k] ){
			cont++;
		}
	}
	vecB[cont] = vecA[i];
}

void bubble_sort_thread(int size, int *vec, int *vecB, std::atomic<int> *count){
	int i;
	while ( (i = count->fetch_add(1)) < size ){
		bubble_sort_iteration(size, vec, vecB, i);
	}
}

const int nThreads = 8;

void bubble_sort_m(int size, int *&vec) 
{
	int *vecB = new int[size];
	std::thread *threads = new std::thread[nThreads];
	std::atomic<int> *count = new std::atomic<int>(0);
	for (int i = 0; i < nThreads; i++){
		threads[i] = std::thread( bubble_sort_thread, size, vec, vecB, count );
	}
	for (int i = 0; i < nThreads; i++){
		threads[i].join();
	}
	delete vec;
	vec = vecB;
}


int main(){

	struct timespec requestStart, requestEnd;
	int size, aux;

	scanf("%d",&size);

	int *vector = new int[size];

	for(int i = 0; i < size; i++){
		scanf("%d",&aux);
		vector[i] = aux;
	}

	clock_gettime(CLOCK_REALTIME, &requestStart);

	bubble_sort_m(size, vector);

  	clock_gettime(CLOCK_REALTIME, &requestEnd);

	double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
		+ ( requestEnd.tv_nsec - requestStart.tv_nsec )
		/ BILLION;

		printf( "%.9lf\n", accum );

		free(vector);
}

