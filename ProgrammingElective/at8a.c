#include <stdlib.h>
#include <stdio.h>

int* arr;
int* sort;

void merge(int l, int m, int r) {
	int n1, n2, i;
	for (n1 = l, n2 = m, i = l; n1 < m && n2 < r; ++i) {
		if (arr[n1] < arr[n2]) {
			sort[i] = arr[n1++];
		} else {
			sort[i] = arr[n2++];
		}
	}
	while (n1 < m) {
		sort[i++] = arr[n1++];
	}
	while (n2 < r) {
		sort[i++] = arr[n2++];
	}
	for (i = l; i < r; ++i) {
		arr[i] = sort[i];
	}
}

void mergeSort(int l, int r) {
	if (r == l+1 || r == l) return;
	int m = (l + r) / 2;
	mergeSort(l, m);
	mergeSort(m, r);
	merge(l, m, r);
}

#ifdef __VSCODE
int sortMain(int* arrv, int arrc) {
#else
int mergeMain(int* arrv, int arrc) {
#endif
	arr = arrv;
	sort = malloc(sizeof(int) * arrc);
	mergeSort(0, arrc);
	free(sort);
	printf("Sorted\n");
	return 0;
}

#ifdef __VSCODE
#include "sorting.c"
#endif