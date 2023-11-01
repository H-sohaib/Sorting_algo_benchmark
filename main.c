#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortAlgorithm.h"

void printArray(int A[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

// doit n=10,000 ---> n=1,000,000
/*

* 1 initialize array with n
* 2 fill array with element
// -------------------------------------
* 3 - make copy of array
* 5 ---- start the chrono
* 4 - pass the copy to sort function
* 3 sort the array with one of sort alg
* 4 ---- end chrono
* 5 save the chrono time in array

*/
void main()
{
  int n = 10000;
  int n_max = 510000;
  int arr[n_max];
  // int bubbleResult[n_max - n + 1];
  time_t t1;

  printf("started \n");

  srand(time(&t1)); // to get random number in each execution of the programe

  // for()
  // initialize the array & fill it
  for (int i = 0; i < n_max; i++)
  {
    arr[i] = rand() % 1000;
  }
  //* -----------------------------------------------------------------------

  clock_t start = clock(); // Record the starting time
  bubbleSort(arr, n);
  // heapSort(arr, n);
  // insertionSort(arr, n);
  // mergeSort(arr, 0, n - 1);
  // quickSort(arr, 0, n - 1);
  // selectionSort(arr, n);

  clock_t end = clock();                                        // Record the ending time
  double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the time taken in seconds

  printf("Time taken: %f seconds\n", time_taken);

  // printf("\nSorted array is \n");
  // printf("\nSorted array is \n");
  // printArray(arr, n);
}

// printf("Given array is \n");
// printArray(arr, n);