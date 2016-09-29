/*
 * sort.c
 *
 *  Created on: 29-Sep-2016
 *      Author: Aniket
 */


#include "../inc/sort.h"


void bubbleSort(long int *arr, int len){
	long int i, j;
	for(i = 0; i < len - 1; i++){
		for(j = 0; j < len - 1 - i; j++){
			if(arr[j] > arr[j+1]){
				long int temp = arr[j];
				arr[j]	 = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}// end of outer loop
}


void selectionSort(long int *arr, int len){
	long int i, j;
	for(i = 0; i < len-1; i++){
		long int smallestPos = i;
		for(j = i+1; j < len; j++){
			if(arr[smallestPos] > arr[j])		smallestPos = j;
		}
		long int smallest = arr[smallestPos];
		arr[smallestPos] =  arr[i];
		arr[i] = smallest;
	}

}



void insertionSort(long int *arr, int len){
	long int i;

	for(i = 1; i < len-1; i++){
		long int key = arr[i];
		long int j = i-1;
		while( j >= 0 && key > arr[j] )			arr[i] = arr[j--];
		arr[j+1] = key;
	}
}
