#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap utility
void swap(long int* a, long int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Bubble sort
void bubbleSort(long int a[], long int n)
{
    for (long int i = 0; i < n - 1; i++) {
        for (long int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

// Insertion sort
void insertionSort(long int arr[], long int n)
{
    long int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection sort
void selectionSort(long int arr[], long int n)
{
    long int i, j, midx;

    for (i = 0; i < n - 1; i++) {

        midx = i;

        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[midx])
                midx = j;
        swap(&arr[midx], &arr[i]);
    }
}

//Quick Sort

//Merge Sort

//Cocktail Sort (Improved Bubble Sort)

//Counting Sort

//Radix Sort

//Heap Sort






// Driver code
int main()
{
    long int n = 10000;
    int it = 0;

    double tim1[10], tim2[10], tim3[10];

    printf("A_size, Bubble, Insertion, Selection\n");

    FILE* data_file = fopen("./sorting_times.txt", "w");
        fprintf(data_file, "A_size Bubble Insertion Selection v2\n");

    while (it++ < 10) {
        long int a[n], b[n], c[n];

        for (int i = 0; i < n; i++) {
            long int no = rand() % n + 1;
            a[i] = no;
            b[i] = no;
            c[i] = no;
        }

        clock_t start, end;

        // Bubble sort
        start = clock();
        bubbleSort(a, n);
        end = clock();

        tim1[it] = ((double)(end - start));

        // Insertion sort
        start = clock();
        insertionSort(b, n);
        end = clock();

        tim2[it] = ((double)(end - start));

        // Selection sort
        start = clock();
        selectionSort(c, n);
        end = clock();

        tim3[it] = ((double)(end - start));


        printf("%li, %li, %li, %li\n",
               n,
               (long int)tim1[it],
               (long int)tim2[it],
               (long int)tim3[it]);
          fprintf(data_file, "%li %li %li %li\n", n, (long int)tim1[it], (long int)tim2[it], (long int)tim3[it]);

        n += 10000;
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
