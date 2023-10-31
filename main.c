#include <stdio.h>
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
int main()
{
  int n = 10000;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = ra
  }

    int na = sizeof(arr) / sizeof(arr[0]);

  printf("Given array is \n");
  printArray(arr, n);

  bubbleSort(arr, n);
  // heapSort(arr, n);
  // insertionSort(arr, n);
  // mergeSort(arr, 0, n - 1);
  // quickSort(arr, 0, n - 1);
  // selectionSort(arr, n);

  printf("\nSorted array is \n");
  printArray(arr, n);
  return 0;
}
