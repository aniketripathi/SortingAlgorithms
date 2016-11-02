/*
 * sort.c
 *
 *  Created on: 29-Sep-2016
 *      Author: Aniket
 */


#include "../inc/sort.h"


/**
 * Linear Search is based concept of searching every element through array and comparing it to the key.
 * If element is found then its position is returned else -1 is returned.
 */
long int linearSearch(long int *arr, long int len, long int key){
	long int i;
	for( i = 0; i < len; i++){
		if(arr[i] == key)		return i;
	}
	return -1;
}


/**
 * Binary Search algorithm is only applicable on sorted arrays. The search range is reduced to half every time if it is known that the key cannot be present in
 * any one half of the sub-array. This comparison takes place of value of key and of the arrays elements/
 */
long int binarySearch(long int *arr, long int len, long int key){
	long int lower = 0, upper = len-1;
	while( lower <= upper){

		long int mid = (lower + upper)/2;
		if(arr[mid] == key)			return mid;
		else if( key < arr[mid])	upper = mid-1;	/* reduce range if not present in second half*/
		else						lower = mid+1;	/* reduce range if not present in first half */
	}

	return -1;

}


/** random function generates a random number between min and max **/
static long int random(long int min, long int max){
	static int isSeeded = 0;
	if(!isSeeded){
		srand(time(NULL));
		isSeeded = 1;

	}
	return (long int) ( ((double)(max - min)/RAND_MAX )* rand() + min);
}

/**
 * Random Search involves randomly generating a number which behaves as an index greater than present index which is used to make
 * leaps of indexes while moving forward linearly in a sorted array. If the number at random index is lesser than key then it sets
 * current index to random index.
 */
long int randomSearch(long int *arr, long int len, long int key){
	long int i = 0, j;
	while(i < len){
		if( arr[i] == key)			return i;
		j = random(i, len);
		if(j > i && arr[j] <= key)	i = j;
		else	++i;
	}
	return -1;
}




/**
 * Bubble Sort involves shifting the largest element to the last position, second largest to second last
 * position and so on. This is done by comparing the adjacent elements and swapping them according to their value.
 */
void bubbleSort(long int *arr, long int len){
	long int i, j;
	for(i = 0; i < len - 1; i++){		/** shifting ith largest element **/
		for(j = 0; j < len - 1 - i; j++){	/** shifting from begining to to last - shifted positions **/
			if(arr[j] > arr[j+1]){
				long int temp = arr[j];
				arr[j]	 = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}// end of outer loop
}



/** Selection Sort involves finding the smallest, second smallest ... elements in the array and placing them
 * at the initial position of 0, 1, 2 ... and so on.
 */
void selectionSort(long int *arr, long int len){
	long int i, j;
	for(i = 0; i < len-1; i++){
		long int smallestPos = i;
		for(j = i+1; j < len; j++){					/** finding ith smallest element **/
			if(arr[smallestPos] > arr[j])		smallestPos = j;
		}

		/** placing the smallest element at ith position **/
		long int smallest = arr[smallestPos];
		arr[smallestPos] =  arr[i];
		arr[i] = smallest;
	}

}


/** Insertion Sort involves picking up the elements from the start and placing them at their correct position in the sub-array
 * formed by beginning of original array to that element's position in original array. The sub-array elements are adjusted when the
 * key element is placed in that array.
 */
void insertionSort(long int *arr, long int len){
	long int i;

	for(i = 1; i < len; i++){
		long int key = arr[i];			/* pick up element**/
		long int j = i-1;
		/** shifting of adjacent elements only if they are larger **/
		while( j >= 0 && key < arr[j] )		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;
	}
}




/**
 * This is a sub-process of merge sort algorithms. This involves copying of the two halves of the original array into new array,
 *  comparing their each elements and placing them in sorted order in main array.
 */
static void merge(long int *arr, long int p, long int q, long int r ){

	long int n1 = q - p + 1, n2 = r - q, i;
	long int subArr1[n1+1], subArr2[n2+1];

	/** copying subarrays **/
	for( i = 0; i < n1; i++)		subArr1[i] = arr[p+i];
	for( i = 0; i < n2; i++)		subArr2[i] = arr[q+1+i];
	subArr1[n1] = subArr2[n2] = LONG_MAX;

	/** comparing and inserting into array using sentinels **/
	long int j = 0, k = 0;
	for(i = p; i <= r; i++){
		if(subArr1[j] > subArr2[k])	arr[i] = subArr2[k++];
else 								arr[i] = subArr1[j++];
	}
}

/** Merge sort works on divide and conquer technique. It breaks the array into two sub-arrays, compares them and then
 * places them into the original array into sorted order. The breaking takes places in this function while comparison and merging
 * takes place in merge function
 */
void mergeSort(long int *arr, long int p, long int q){

if(p < q){
 long int mid = (p+q)/2;
	mergeSort(arr, p, mid);
	mergeSort(arr, mid+1, q);
	merge(arr, p, mid, q);
}
}


/**
 * This function is sub-algorithm of heap sort. It is used to maintain the max-heap property at
 * a particular node. If the node is not consistent, then it is corrected and by replacing it with child and
 * the sub-tree starting from its child is again checked for maintenance of this property.
 */
void maxHeapify(long int *arr, long int index, long int heapSize){

	/** heap according to zero index, here element at index = root of sub-heap **/
	long int leftIndex = (index << 1) + 1, rightIndex =  (index << 1 ) + 2;
	long int largestIndex;

	/** search largest among parent, right and left **/
	if(leftIndex < heapSize && arr[leftIndex] > arr[index])		largestIndex = leftIndex;
	else														largestIndex = index;

	if(rightIndex < heapSize && arr[rightIndex] > arr[largestIndex])	largestIndex = rightIndex;

	/** exchange larger with root and heapify sub-heap **/
	if(largestIndex != index){
		long int temp 		= arr[index];
		arr[index] 			= arr[largestIndex];
		arr[largestIndex] 	= temp;
		maxHeapify(arr, largestIndex, heapSize);
	}
}

/**
 * Heap Sort builds a heap, and then replaces the largest element present at the root of heap with the last element of
 * the array. Then it heapifies the array validating and correcting the max-heap property. It reduces the heap size by 1 o that
 * the last element which is in its correct position is no longer considered part of heap.
 * The final array obtained is sorted array.
 */
void heapSort(long int *arr, long int heapSize){
	long int i;
	/** build max heap **/

	/** (heapSize - 2 )/ 2 is last parent node for zero indexing**/
	for(i = (heapSize-2)/2; i >= 0; i--){
		maxHeapify(arr, i, heapSize);
	}

	/** exchanging the first node with heapSize -1th node **/
	for(i = heapSize-1; i > 0; i-- ){
		long int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		maxHeapify(arr, 0, --heapSize);
	}

}


/**
 * This function partition the sub-array using Hoare Partition technique. It returns the
 * pivot element.
 */
static long int hoarePartition(long int *arr, long int p, long int r){
	long int x = arr[p], i = p+1, j = r;

	while(1){
	/** check for contiguous sub-arrays greater or smaller to pivot **/
		while(arr[j] > x)	--j;
		while(arr[i] < x && i <= r)		++i;
	/** if any element doesn't fit into the sub-array swap them with element
	 * of other sub-array
	 */
		if(i < j){
			long int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		 }

	/** swap the pivot element to its correct position**/
		else {
		long int temp = arr[p];
		arr[p] = arr[j];
		arr[j] = temp;
		return j;
		}
	}


}


/**
 * This function partitions the sub-array and returns the pivot. The partition scheme
 * used is Lomuto partition scheme.
 */
static long int lumotuPartition(long int *arr, long int p, long int r){
	long int i = p - 1, j, x = arr[r];

	for( j = p; j < r; j++){
		if( (arr[j] < x) || ( arr[j] == x && j < (p+r)/2) ){
			long int temp  = arr[++i];
					arr[i] = arr[j];
					arr[j] = temp;
		}
	}
		 arr[r] = arr[i + 1];
		 arr[i + 1]	  = x;
		 return (i+1);
}


/**
 * Quick sorts works on divide and conquer technique. The arrays( or sub-arrays) are partitioned in
 * such a way that it contains all smaller elements to the left of pivot element and all larger element
 * to the right of pivot.
 */
void quickSort(long int *arr, long int begIndex, long int endIndex){

if(begIndex < endIndex){
	long int pivot = hoarePartition(arr, begIndex, endIndex);
	quickSort(arr, begIndex, pivot - 1);
	quickSort(arr, pivot + 1, endIndex);
}
}




/**
 * Counting Sort works on the assumption that the range of numbers is between 1 to k. This algorithms is made
 * according to the value k = 1000. It calculates the frequency of each number and stores them directly using their index.
 * The sorted elements are stored in new array and this new array is returned.
 */
int* countingSort(int *arr, long int len){
	const int K = 1000;
	int frequency[K], j;
	long int i;
	/** clear out array **/
	for(j = 0; j < K; j++)			frequency[j] = 0;

	for(i = 0; i < len; i++)		++ frequency[arr[i] - 1] ;

	/** find cumulative frequency, acts as position of elements in new array **/
	for(j = 1; j < K; j++)			frequency[j] += frequency[j-1];

	int *sortedarr = malloc(sizeof(int)*len);

	for(i = 0; i < len; i++){
		sortedarr[--frequency[arr[i] - 1]] = arr[i];
	}
	return sortedarr;
}
