#include "array_merge.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mergesort/mergesort.c"

int* array_merge(int num_arrays, int* sizes, int** values){
	//set up variable for lengths
	int lengths=0;
	//determine final length of the array 
	for( int i = 0; i < num_arrays; i++) {
		lengths = lengths + sizes[i]; 
	}
	//array pounter positions the values while inserting into the combined array
	int arrayPositioner = 0;
	//allowcating space
	int* mergedarray = (int*)calloc(lengths, sizeof(int));
	//taking elements from the given arrays and putting them into the final array
	//at position arrayPositioner
	for(int i = 0; i < num_arrays; i++) {
		for(int j = 0; j < sizes[i]; j++){ 
			mergedarray[arrayPositioner] = values[i][j];
			arrayPositioner++;
		}
	}


	//call merge sort on the newly combined array
	mergesort(lengths, mergedarray);

	//return sorted array

	return mergedarray;
	//free the allocation
	free(mergedarray);
}
