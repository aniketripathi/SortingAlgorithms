/*
 * sort.c
 *
 *  Created on: 29-Sep-2016
 *      Author: Aniket
 */


#include "../inc/sort.h"


long int linearSearch(long int *arr, long int len, long int key){
	long int i;
	for( i = 0; i < len; i++){
		if(arr[i] == key)		return i;
	}
	return -1;
}



long int binarySearch(long int *arr, long int len, long int key){
	long int lower = 0, upper = len-1;
	while( lower <= upper){
		long int mid = (lower + upper)/2;
		if(arr[mid] == key)			return mid;
		else if( key < arr[mid])	upper = mid-1;
		else						lower = mid+1;
	}

	return -1;

}



void bubbleSort(long int *arr, long int len){
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


void selectionSort(long int *arr, long int len){
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



void insertionSort(long int *arr, long int len){
	long int i;

	for(i = 1; i < len-1; i++){
		long int key = arr[i];
		long int j = i-1;
		while( j >= 0 && key > arr[j] )			arr[i] = arr[j--];
		arr[j+1] = key;
	}
}





static void merge(long int *arr, long int p, long int q, long int r ){

	long int n1 = q - p + 1, n2 = r - q, i;
	long int subArr1[n1+1], subArr2[n2+1];

	/** copying subarrays **/
	for( i = 0; i < n1; i++)		subArr1[i] = arr[p+i];
	for( i = 0; i < n2; i++)		subArr2[i] = arr[q+1+i];
	subArr1[n1] = subArr2[n2] = LONG_MAX;

	long int j = 0, k = 0;
	for(i = p; i <= r; i++){
		if(j >= n1 || subArr1[j] > subArr2[k])	arr[i] = subArr2[k++];
else 	if(k >= n2 || subArr1[j] < subArr2[k])	arr[i] = subArr1[j++];
	}
}


void mergeSort(long int *arr, long int p, long int q){

if(p < q){
 long int mid = (p+q)/2;
	mergeSort(arr, p, mid);
	mergeSort(arr, mid+1, q);
	merge(arr, p, mid, q);
}
}





void maxHeapify(long int *arr, long int index, long int heapSize){
	long int leftIndex = (2 * index), rightIndex = ( 2 * index + 1);

	long int largestIndex;
	if(leftIndex < heapSize && arr[leftIndex] > arr[index])		largestIndex = leftIndex;
	else														largestIndex = index;

	if(rightIndex < heapSize && arr[rightIndex] > arr[largestIndex])	largestIndex = rightIndex;

	if(largestIndex != index){
		long int temp 		= arr[index];
		arr[index] 			= arr[largestIndex];
		arr[largestIndex] 	= temp;
		maxHeapify(arr, largestIndex, heapSize);
	}
}


void heapSort(long int *arr, long int heapSize){}


