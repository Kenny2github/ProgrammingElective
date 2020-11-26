#include <stdio.h>
#include <stdlib.h>

#define COUNT 1000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int array[COUNT];

int d_linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; ++i)
        if (arr[i] == search)
            return i;
    return -1;
}

int d_binarySearch(int arr[], int n, int search) {
    int b, m, t;
    b = 0, t = n;
    while (b != t) {
        m = (b + t) / 2;
        if (arr[m] == search) return m;
        if (arr[m] > search) t = m;
        if (arr[m] < search) b = m+1;
    }
    return -1;
}

int d_swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void d_bubbleSort(int arr[], int n) {
    int swapped = 1;
    int i, j;
    for (i = n-1; i > 0 && swapped; --i) {
        swapped = 0;
        for (j = 0; j < i; ++j) {
            if (arr[j] > arr[j+1]) {
                d_swap(arr+j, arr+j+1);
                swapped = 1;
            }
        }
    }
}

void d_insertionSort(int arr[], int n) {
    int i, j;
    for (i = 1; i < n; ++i) {
        for (j = i; j > 0 && arr[j] < arr[j-1]; --j) {
            d_swap(arr+j, arr+j-1);
        }
    }
}

void d_mergeSortR(int arr[], int out[], int a, int b) {
    // range [a, b)
    if (b <= a+1) return;
    int i, m = (a+b)/2;
    for (i = a; i < b; ++i) out[i] = arr[i];
    // recursively sort each half by magic
    d_mergeSortR(arr, out, a, m);
    d_mergeSortR(arr, out, m, b);
    i = a;
    int j = a, k = m;
    while (j < m && k < b) {
        if (out[j] <= out[k]) {
            arr[i++] = out[j++];
        } else {
            arr[i++] = out[k++];
        }
    }
    while (j < m) arr[i++] = out[j++];
    while (k < b) arr[i++] = out[k++];
    for (i = a; i < b; ++i) out[i] = arr[i];
}

void d_mergeSort(int arr[], int n) {
    int out[n];
    d_mergeSortR(arr, out, 0, n);
}

void d_testsearch(int arr[], int n, int func(int*, int, int)) {
    int idx = n/3;
    int val = arr[idx];
    printf("%d should be present in arr, most likely at %d:\n", val, idx);
    idx = func(arr, n, val);
    if (idx < 0) {
        printf("BAD: %d is not present in arr!\n", val);
    } else {
        printf("%d was found at index %d.\n", val, idx);
    }
}

void d_sorted(int arr[], int n) {
    int sorted = 1, i;
    for (i = 0; i < n-1; ++i){
        if (arr[i] > arr[i+1]) {
            sorted = 0;
            break;
        }
    }
    if (sorted) {
        printf("The array is sorted.\n");
    } else {
        printf("The array is not sorted. Surrounding values:\n");
        for (int j = max(i-5, 0); j < min(i+5, n); ++j)
            printf("%d ", arr[j]);
        printf("\n");
    }
}

void d_loadarr(int arr[], int n) {
    FILE *fp = fopen("numbers.txt", "r");
    if (!fp)
        exit(1);
    register int i;
    for (i = 0; i < n; ++i) {
        fscanf(fp, "%d", arr + i);
    }
    fclose(fp);
}

void d_printarr(int arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%d\t", arr[i]);
    printf("\n");
}

#ifdef __VSCODE
int main() {
#else
int dictation_main() {
#endif
    char choice;
    d_loadarr(array, COUNT);
    do {
        printf("1. Linear search\n2. Binary search\n3. Bubble sort\n4. Insertion sort\n5. Merge sort\n6. Print array\nq. Quit\nEnter choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                d_testsearch(array, COUNT, d_linearSearch);
                break;
            case '2':
                d_mergeSort(array, COUNT);
                d_testsearch(array, COUNT, d_binarySearch);
                break;
            case '3':
                d_loadarr(array, COUNT);
                d_bubbleSort(array, COUNT);
                d_sorted(array, COUNT);
                break;
            case '4':
                d_loadarr(array, COUNT);
                d_insertionSort(array, COUNT);
                d_sorted(array, COUNT);
                break;
            case '5':
                d_loadarr(array, COUNT);
                d_mergeSort(array, COUNT);
                d_sorted(array, COUNT);
                break;
            case '6':
                d_printarr(array, COUNT);
                break;
            case 'q':
                break;
            default:
                printf("bruh what\n");
        }
    } while (choice != 'q');
    return 0;
}