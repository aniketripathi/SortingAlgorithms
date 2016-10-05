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

/** searching **/
long int linearSearch(long int *arr, long int len, long int key);
long int binarySearch(long int *arr, long int len, long int key);


void bubbleSort(long int *arr, long int len);
void insertionSort(long int *arr, long int len);
void selectionSort(long int *arr, long int len);
void mergeSort(long int *arr, long int lowerIndex, long int upperIndex);

#endif /* SORT_H_ */
