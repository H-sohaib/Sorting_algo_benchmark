#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortAlgorithm.h"

void copyArray(int *original, int *copy, int size)
{
    for (int i = 0; i < size; i++)
    {
        copy[i] = original[i];
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Bubble Sort
//* void bubbleSort(int arr[], int n);
// InertionSort
//* void insertionSort(int arr[], int n);
// Selection Sort
//* void selectionSort(int arr[], int n);
// Quick Sort
//* void quickSort(int array[], int low, int high);
// Merge Sort
//* void mergeSort(int arr[], int l, int r);
// Heap Sort
//* void heapSort(int arr[], int N);

// Cocktail Sort (Improved Bubble Sort)

// Counting Sort

// Radix Sort

// Driver code
int main()
{
    int step = 10000;
    int n = 10000;
    int n_max = 100000;
    int it = 0;
    clock_t start, end;
    double tim1[10], tim2[10], tim3[10];

    // initiialize a dynam array
    int *array = malloc(n * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Done --> Initilize vars \n");

    FILE *data_file = fopen("./sorting_times.txt", "w");
    fprintf(data_file, "A_size Bubble Insertion Selection v2\n");

    printf("Start benchmark ... \n");
    printf("%-12s%-12s%-12s%-12s\n", "Array n", "Bubble", "Insert", "Selection");

    for (int i = n; i <= n_max; i += step)
    {
        int *new_array = (int *)realloc(array, i * sizeof(int));
        if (new_array != NULL)
        {
            array = new_array;
        }
        else
        {
            printf("Failf to realloc ! Exiting ...");
            return 1;
        }

        // option 1 : refill all the array random number ------------------------------------------------------------------
        // fill the array with random number 0 --> 1000
        for (int j = 0; j < i; j++)
        {
            array[j] = rand() % 1000 + 1;
        }

        //* Bubble sort ----
        int *bubbleArr = malloc(i * sizeof(int));
        copyArray(array, bubbleArr, i);

        start = clock();
        bubbleSort(bubbleArr, i);
        end = clock();
        tim1[it] = ((double)(end - start));

        //* Insertion sort
        int *inserArr = malloc(i * sizeof(int));
        copyArray(array, inserArr, i);

        start = clock();
        insertionSort(inserArr, i);
        end = clock();
        tim2[it] = ((double)(end - start));

        //* Selection sort ---
        int *selectArr = malloc(i * sizeof(int));
        copyArray(array, selectArr, i);
        start = clock();
        selectionSort(selectArr, i);
        end = clock();
        tim3[it] = ((double)(end - start));

        printf("%-12li%-12li%-12li%-12li\n",
               i,
               (long int)tim1[it],
               (long int)tim2[it],
               (long int)tim3[it]);
        fprintf(data_file, "%li %li %li %li\n", i, (long int)tim1[it], (long int)tim2[it], (long int)tim3[it]);
    }
    /*   FILE* data_file = fopen("C:\\Users\\Hp\\Desktop\\\Faissal\\\miniProjetPerformTriAlgo\\sorting_times.txt", "w");

      // Output the data to the file
      fprintf(data_file, "A_size Bubble Insertion Selection\n");
      for (int it = 0; it < 10; it++) {
          fprintf(data_file, "%li %li %li %li\n", n, (long int)tim1[it], (long int)tim2[it], (long int)tim3[it]);
          n += 10000;
      }
  */
    fclose(data_file);
    return 0;
}
