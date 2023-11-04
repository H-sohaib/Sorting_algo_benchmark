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

int main()
{
    int step = 10000;
    int n = 10000;
    int n_max = 100000;
    int n_algo = 7;
    clock_t start, end;
    double time_records[n_algo];

    // initiialize a dynam array
    int *array = malloc(n * sizeof(int));
    int *alg_array = malloc(i * sizeof(int));
    if (array == NULL || alg_array == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Done --> Initilize vars \n");

    FILE *data_file = fopen("./sorting_times.txt", "w");
    // fprintf(data_file, "A_size Bubble Insertion Selection v2\n");

    printf("Start benchmark ... \n");
    printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "Array n", "Bubble", "Heap", "Insert", "Merge", "Quick", "Selection", "Redix");

    for (int i = n; i <= n_max; i += step)
    {
        int *new_array = (int *)realloc(array, i * sizeof(int));
        int *new_alg_array = (int *)realloc(array, i * sizeof(int));

        if (new_array != NULL || new_alg_array != NULL)
        {
            array = new_array;
            alg_array = new_alg_array;
        }
        else
        {
            printf("Fail to realloc ! Exiting ...");
            return 1;
        }

        // option 1 : refill all the array random number ------------------------------------------------------------------
        // fill the array with random number 0 --> 1000
        for (int j = 0; j < i; j++)
        {
            array[j] = rand() % 1000 + 1;
        }

        //* Bubble sort ----
        copyArray(array, alg_array, i);
        start = clock();
        bubbleSort(alg_array, i);
        end = clock();
        time_records[0] = ((double)(end - start));

        //* Heap sort ----
        copyArray(array, alg_array, i);
        start = clock();
        heapSort(alg_array, i);
        end = clock();
        time_records[1] = ((double)(end - start));

        //* Insertion sort
        copyArray(array, alg_array, i);
        start = clock();
        insertionSort(alg_array, i);
        end = clock();
        time_records[2] = ((double)(end - start));

        //* merge sort
        copyArray(array, alg_array, i);
        start = clock();
        mergeSort(alg_array, 0, i);
        end = clock();
        time_records[3] = ((double)(end - start));

        //* Quick sort
        copyArray(array, alg_array, i);
        start = clock();
        quickSort(alg_array, 0, i);
        end = clock();
        time_records[4] = ((double)(end - start));

        //* Selection sort -----
        copyArray(array, alg_array, i);
        start = clock();
        selectionSort(alg_array, i);
        end = clock();
        time_records[5] = ((double)(end - start));

        //* Redix sort -----
        copyArray(array, alg_array, i);
        start = clock();
        radixSort(alg_array, i);
        end = clock();
        time_records[6] = ((double)(end - start));

        //*---- show results in console
        printf("%-12li", i);
        for (int i = 0; i < n_algo; i++)
        {
            printf("%-12li",
                   (long int)time_records[i]);
        }
        printf("\n");
        //*---- write result in GNUplot file
        fprintf(data_file, "%li ", i);
        for (int i = 0; i < n_algo; i++)
        {
            fprintf(data_file, "%li ", (long int)time_records[i]);
        }
        fprintf(data_file, "\n");
    }

    fclose(data_file);
    system("gnuplot -persist plot_script.gnuplot");
    return 0;
}
