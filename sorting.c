/*
This C code generates a random Array with ARRAYSIZE length
and sorts it according to given algorithm.
Nicholas Kim
(2016 May 12)
nicholaskim94@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define ARRAYSIZE 2000
#define MAXIMUM_VALUE_IN_ARRAY 1000
#define INPUTSIZE 20

char* receiveUserInput(void);
void createArray(int *arr);
void printArray(int *arr);
void bubbleSort(int *arr);
void selectionSort(int *arr);
void insertionSort(int *arr);
void swap(int *a, int *b);
void strupr(char *str);

int main(void){

		// INITIALIZE
		int *randomArr;
		clock_t begin, end;
		double time_spendt;
		randomArr = malloc(sizeof(int)*ARRAYSIZE);
		srand(time(NULL));

		while(1){

			// USER INPUT
			char* algorithm = receiveUserInput();
			createArray(randomArr);


			// BUBBLE
			if(strcmp(algorithm, "BUBBLE") == 0){
				begin = clock();
				printf("\n-------------BEFORE %s SORTING------------\n", algorithm);
				printArray(randomArr);
				bubbleSort(randomArr);
				printf("\n-------------AFTER %s SORTING------------\n", algorithm);
				printArray(randomArr);
				end = clock();
				printf("TIME CONSUMED IN %s SORT : %f", algorithm, (double)(end - begin) / CLOCKS_PER_SEC);
			}

			// SELECTION
			else if(strcmp(algorithm, "SELECTION") == 0){
				begin = clock();
				printf("\n-------------BEFORE %s SORTING------------\n", algorithm);
				printArray(randomArr);
				selectionSort(randomArr);
				printf("\n-------------AFTER %s SORTING------------\n", algorithm);
				printArray(randomArr);
				end = clock();
				printf("TIME CONSUMED IN %s SORT : %f", algorithm, (double)(end - begin) / CLOCKS_PER_SEC);
			}

			// INSERTION
			else if(strcmp(algorithm, "INSERTION") == 0){
				begin = clock();
				printf("\n-------------BEFORE %s SORTING------------\n", algorithm);
				printArray(randomArr);
				insertionSort(randomArr);
				printf("\n-------------AFTER %s SORTING------------\n", algorithm);
				printArray(randomArr);
				end = clock();
				printf("TIME CONSUMED IN %s SORT : %f", algorithm, (double)(end - begin) / CLOCKS_PER_SEC);
			}

			// QUIT
			else if(strcmp(algorithm, "QUIT") == 0){ break; }

			// WRONG INPUT EXCEPTION
			else{ printf("WRONG INPUT\n"); }

		}

		return 0;
}

// RECIEVE INPUT
char* receiveUserInput(){
	char *input = malloc(sizeof(char) * INPUTSIZE);
	printf("\n-------------------------------------------\n");
	printf("-            SORTING ALGORITHMS           -\n");
	printf("-           TYPE NAME OF ALGORITM         -\n");
	printf("-------------------------------------------\n");
	printf("[BUBBLE, SELECTION, INSERTION, QUIT] : ");
	scanf("%s", input);
	strupr(input);
	return input;
}


// PRINT ARRAY
void printArray(int *arr){
	for(int i=0 ; i<ARRAYSIZE ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// CREATE ARRAY
void createArray(int *arr){
	for(int i=0 ; i<ARRAYSIZE ; i++){
			arr[i] = rand() % MAXIMUM_VALUE_IN_ARRAY;
	}
}


// BUBBLESORT
void bubbleSort(int *arr){
	for(int i=0 ; i<ARRAYSIZE-1 ; i++){
			for(int j= ARRAYSIZE-1 ; j > i ; j--){
					if( arr[j-1] > arr[j] ){
						swap(&arr[j-1], &arr[j]);
					}
			}
	}
}

// SELECTIONSORT
void selectionSort(int *arr){
	for(int i=0 ; i<ARRAYSIZE; i++){
		for(int j = i + 1 ; j < ARRAYSIZE ; j++){
				if(arr[i] > arr[j]){ swap(&arr[j], &arr[i]); }
		}
	}
}

// INSERTIONSORT
void insertionSort(int *arr){
	for(int i=0 ; i<ARRAYSIZE; i++){
			int temp = arr[i];
			int j = i - 1;
			while(temp < arr[j] && j>= 0){
				arr[j+1] = arr[j];
				j -= 1;
			}
			arr[j+1] = temp;
	}
}

// SWAP TWO ELEMENTS
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// STRING TO UPPPERCASE
void strupr(char *string) {
	for(; *string; string++)
	 *string = toupper((unsigned char) *string);
}
