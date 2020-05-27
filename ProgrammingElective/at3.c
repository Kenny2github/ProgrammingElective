#include <stdio.h>

int binarySearch(int arrv[], int arrc, int query) {
	int idx = arrc / 2;
	int lo = 0, hi = arrc - 1;
	while (arrv[idx] != query) {
		if (arrv[idx] > query) {
			hi = idx;
		}
		else if (arrv[idx] < query) {
			lo = idx;
		}
		if ((hi + lo) / 2 == idx) {
			return -1;
		}
		idx = (hi + lo) / 2;
	}
	return idx;
}

int at3_main() {
	int arr[] = { 0, 1, 8, 12, 12, 18, 18, 45, 55, 99 };
	int n = 45;
	printf("%d is found at index %d\n", n, binarySearch(arr, sizeof(arr) / sizeof(int), n));
	return 0;
}