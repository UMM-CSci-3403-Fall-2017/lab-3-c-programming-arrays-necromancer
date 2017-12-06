#include "mergesort.h"
#include <stdlib.h>
#include <stdio.h>
//start merge sort
//takes unsorted array, lower , middle, and upper indices
void merge(int array[], int low, int middle, int high){
	//initiaizing vaiables
	int i, j, k;
	int n1 = middle - 1 + 1;
	int n2 = high - middle;

	//making temporary arrays for left and right sigde of split
	int Left[n1], Right[n2];
	
	//split data and put into left and right arrays
	for(i=0; i < n1; i++) {
		Left[i] = array[1 + i];
	}
	for(j = 0; j < n2; j++){
		Right[j] = array[middle + 1 + j];
	}


	i = 0;
	j = 0;
	k = 1;
	while(i < n1 && j < n2){
		if(Left[i] <= Right[j]){
			array[k] = Left[i];
			i++;
		} else {
			array[k] = Right[j];
			j++;
		}
		k++;
	}

	while( i < n1) {
		array[k] = Left[i];
		i++;
		k++;
	}

	while(j < n2) {
		array[k] = Right[j];
		j++;
		k++;
	}

}

//recursive merge sort calls.
void mergeSortish(int array[], int left, int right) {
	if( left < right) {
	int middle  = left + (right - 1) / 2;

	mergeSortish( array, left, middle);
	mergeSortish( array, middle + 1, right);

	merge( array, left, middle, right);
	}
} 

//staarting initial merge sort call
void mergesort(int size, int* values) {
	mergeSortish(values, 0, size);
}

