/*
 * sort.h
 *
 *  Created on: 29-Sep-2016
 *      Author: Aniket
 */

#ifndef SORT_H_
#define SORT_H_

#include <stdlib.h>
#include <limits.h>
#include <time.h>

/******************************************************** SEARCHING **********************************************************/


/**
 * @brief Linear search searches an element from any array.
 *
 * Linear Search returns the position of the given element from any array. If more than one given element is present, then
 * position of first element is returned. It works on both sorted and unsorted array. Time complexity is O(n).
 *
 * @param arr Array to be searched
 * @param len Length of the given array
 * @param key Element to be searched
 *
 * @return long int Position of the given element if found else -1.
 */
long int linearSearch(long int *arr, long int len, long int key);


/**
 * @brief Binary search searches an element from the sorted array.
 *
 * Binary Search returns the position of the given element from sorted array. If more than one given element is present, then
 * position of first element encountered is returned. It works only on sorted array. Time complexity is O(lgn).
 *
 * @param arr Array to be searched
 * @param len Length of the given array
 * @param key Element to be searched
 *
 *  @return long int Position of the given element if found else -1.
 */
long int binarySearch(long int *arr, long int len, long int key);


/**
 * @brief Random search searches an element from the sorted array.
 *
 * Random Search returns the position of the given element from sorted array. If more than one given element is present, then
 * position of first element encountered is returned. It works only on sorted array. It uses random number to jump the values to reach closer to
 * the required element.
 *
 * @param arr Array to be searched
 * @param len Length of the given array
 * @param key Element to be searched
 *
 *  @return long int Position of the given element if found else -1.
 */
long int randomSearch(long int *arr, long int len, long int key);









/**************************************************** SORTING *********************************************************************/


/**
 * @brief Bubble sort algorithm.
 *
 * Bubble sort takes two arguments array and length of array and returns the sorted array.Time complexity is O(n*n).
 *
 * @param arr Array to be sorted
 * @param len Length of the given array
 *
 * @return void. Returns nothing
 */
void bubbleSort(long int *arr, long int len);

/**
 * @brief Insertion sort algorithm.
 *
 * Insertion sort takes two arguments array and length of array and returns the sorted array. Efficient for almost sorted array. Best case
 * time complexity is O(n). Worst case time complexity is O(n*n).
 *
 * @param arr Array to be sorted
 * @param len Length of the given array
 * @return void. Returns nothing
 */
void insertionSort(long int *arr, long int len);


/**
 * @brief Selection sort algorithm.
 *
 * Selection sort takes two arguments array and length of array and returns the sorted array. Time complexity is O(n*n).
 *
 * @param arr Array to be sorted
 * @param len Length of the given array
 * @return void. Returns nothing
 */
void selectionSort(long int *arr, long int len);


/**
 * @brief Merge sort algorithm.
 *
 * Merge sort is based on Divide and Conquer approach. It takes three arguments - the array, the lower index and the upper index. The sorting
 * will be done on the sub-array from index lowerIndex to upperIndex. For complete sorting the lowerIndex should be 0 and upperIndex should be
 * len - 1 where len is the length of the array. Time complexity is O(nlgn).
 *
 * @param arr Array to be sorted
 * @param lowerIndex Beginning index of the sub-array to be sorted
 * @param upperIndex Last index of the sub-array to be sorted
 *
 * @return void. Returns nothing.
 */
void mergeSort(long int *arr, long int lowerIndex, long int upperIndex);

/**
 * @brief Heap sort algorithm.
 *
 * Heap sort is based on Heap data structure. It takes two arguments - the array and the length of the array.Time complexity is O(nlgn).
 *
 * @param arr Array to be sorted
 * @param len Length of the given array
 *
 * @return void. Returns nothing.
 */
void heapSort(long int *arr, long int len);


/**
 * @brief Quick sort algorithm.
 *
 * Quick sort is based on Divide and Conquer approach. It takes three arguments - the array, the lower index and the upper index. The sorting
 * will be done on the sub-array from index lowerIndex to upperIndex. For complete sorting the lowerIndex should be 0 and upperIndex should be
 * len - 1 where len is the length of the array. Time complexity is O(nlgn). The two partition method Lomuto's and Hoare's are present in the source
 * code. By default Hoare's partition is used.
 *
 * @param arr Array to be sorted
 * @param lowerIndex Beginning index of the sub-array to be sorted
 * @param upperIndex Last index of the sub-array to be sorted
 *
 * @return void. Returns nothing.
 */
void quickSort(long int *arr, long int lowerIndex, long int upperIndex);

/**
 * @brief Counting sort algorithm.
 *
 * Counting Sort is based on assumption that all elements are present between 1 to k where k = 1000. It takes two arguments the array and the length of
 * the array. It sorts in linear time complexity. The original array is not modified. A new array is created which stores the elements of original array
 * in sorted manner. It is the responsibility of the user to free the memory of sorted array after use.
 *
 * @param arr Array to be sorted
 * @param len Length of the array
 *
 * @return int* The sorted integer array.
 */
int* countingSort(int *arr, long int len);






/**
 * @brief Shell sort algorithm.
 *
 * The shell sort is a generalization algorithm of insertion sort. In this algorithm we take a gap sequence. A gap in a sequence is 
 * the difference between every two numbers in the array. The algorithms selects the largest gap, and then assumes that elements in the
 * array are located at distance of gap with respect to each other. It then sorts the the assumed array accordingly using insertion sort.
 * The above sorting is performed for every gap sequence, where the last gap is 1. If sequence contains only one element i.e. 1 then it is
 * an insertion sort.
 * Performance of the algorithm depends upon the gap sequence.
 *
 * @param arr Array to be sorted
 * @param len Length of the array
 * 
 * @return void. Returns nothing.
**/
void shellSort(long int *arr, long int len);





#endif /* SORT_H_ */
