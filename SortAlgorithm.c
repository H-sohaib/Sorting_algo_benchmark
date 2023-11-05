#include "SortAlgorithm.h"
#include <stdbool.h>

// base
void swap(int *a, int *b)
{

  int temp = *a;
  *a = *b;
  *b = temp;
}

//* bubble sort *******************************************
void bubbleSort(int arr[], int n)
{
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++)
  {
    swapped = false;
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
      }
    }

    // If no two elements were swapped by inner loop,
    // then break
    if (swapped == false)
      break;
  }
}

//* heap sort ********************************************
void heapify(int arr[], int N, int i)
{
  // Find largest among root,
  // left child and right child

  // Initialize largest as root
  int largest = i;

  // left = 2*i + 1
  int left = 2 * i + 1;

  // right = 2*i + 2
  int right = 2 * i + 2;

  // If left child is larger than root
  if (left < N && arr[left] > arr[largest])

    largest = left;

  // If right child is larger than largest
  // so far
  if (right < N && arr[right] > arr[largest])

    largest = right;

  // Swap and continue heapifying
  // if root is not largest
  // If largest is not root
  if (largest != i)
  {

    swap(&arr[i], &arr[largest]);

    // Recursively heapify the affected
    // sub-tree
    heapify(arr, N, largest);
  }
}
void heapSort(int arr[], int N)
{

  // Build max heap
  for (int i = N / 2 - 1; i >= 0; i--)

    heapify(arr, N, i);

  // Heap sort
  for (int i = N - 1; i >= 0; i--)
  {

    swap(&arr[0], &arr[i]);

    // Heapify root element
    // to get highest element at
    // root again
    heapify(arr, i, 0);
  }
}

//* Insertion Sort  **************************************
void insertionSort(int arr[], int n)
{
  long int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

//* Merge Sort *******************************************
void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temp arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  // Merge the temp arrays back into arr[l..r
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[],
  // if there are any
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[],
  // if there are any
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}
//* Quick Sort *******************************************
int partition(int array[], int low, int high)
{

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  if (low < high)
  {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

//* Selection Sort ****************************************
void selectionSort(int arr[], int n)
{
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++)
  {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    // Swap the found minimum element with the first element
    if (min_idx != i)
      swap(&arr[min_idx], &arr[i]);
  }
}

//* Redix Sort *****************************************************
int getMax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
void countingSort_radix(int array[], int size, int place)
{
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++)
  {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--)
  {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radixSort(int array[], int size)
{
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort_radix(array, size, place);
}

//* Counting Sort ******************************************
void countingSort(int array[], int size)
{
  int output[10];

  // Find the largest element of the array
  int max = array[0];
  for (int i = 1; i < size; i++)
  {
    if (array[i] > max)
      max = array[i];
  }

  // The size of count must be at least (max+1) but
  // we cannot declare it as int count(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int count[10];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i)
  {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++)
  {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++)
  {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--)
  {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++)
  {
    array[i] = output[i];
  }
}

//* Cycle Sort **********************************************************
void cycleSort(int a[], int n)
{
  int start, element, pos, temp, i;

  /*Loop to traverse the array elements and place them on the correct position*/
  for (start = 0; start <= n - 2; start++)
  {
    element = a[start];

    /*position to place the element*/
    pos = start;

    for (i = start + 1; i < n; i++)
      if (a[i] < element)
        pos++;
    if (pos == start) /*if the element is at exact position*/
      continue;
    while (element == a[pos])
      pos += 1;
    if (pos != start) /*put element at its exact position*/
    {
      // swap(element, a[pos]);
      temp = element;
      element = a[pos];
      a[pos] = temp;
    }
    /*Rotate rest of the elements*/
    while (pos != start)
    {
      pos = start;
      /*find position to put the element*/
      for (i = start + 1; i < n; i++)
        if (a[i] < element)
          pos += 1;

      /*Ignore duplicate elements*/
      while (element == a[pos])
        pos += 1;

      /*put element to its correct position*/
      if (element != a[pos])
      {
        temp = element;
        element = a[pos];
        a[pos] = temp;
      }
    }
  }
}