#include <stdlib.h>
#include <stdio.h>

int getPivot(int s, int m, int e) {
	if (s < m) {
		if (m < e) {
			// s < m < e
			return m;
		}
		// s < e < m
		return e;
	}
	// m > s
	if (m < e) {
		// e > m > s
		return m;
	}
	// m > s and m > e
	if (e > s) {
		// m > e > s
		return e;
	}
	// m > s > e
	return s;
}

void quickSort(int* arr, int L, int R, int lvl) {
	int j;
	if (R == L + 1 || R == L) return;
	int *left, *mid, *right;
	left = malloc(sizeof(int) * (R - L));
	mid = malloc(sizeof(int) * (R - L));
	right = malloc(sizeof(int) * (R - L));
	int pivot = getPivot(arr[L], arr[(L + R) / 2], arr[R - 1]);
	int i, l = 0, m = 0, r = 0, ll, ml, rl;
	for (i = L; i < R; ++i) {
		if (arr[i] < pivot) {
			left[l++] = arr[i];
		}
		else if (arr[i] > pivot) {
			right[r++] = arr[i];
		}
		else {
			mid[m++] = arr[i];
		}
	}
	ll = l, ml = m, rl = r, i = L;
	for (l = 0; l < ll; ++l) {
		arr[i++] = left[l];
	}
	for (m = 0; m < ml; ++m) {
		arr[i++] = mid[m];
	}
	for (r = 0; r < rl; ++r) {
		arr[i++] = right[r];
	}
	if (ll > 0) {
		quickSort(arr, L, L + ll, lvl + 1);
	}
	L += ll;
	L += ml;
	if (rl > 0) {
		quickSort(arr, L, L + rl, lvl + 1);
	}
	free(left);
	free(mid);
	free(right);
}

#ifdef __VSCODE
void sortMain(int* arrv, int arrc) {
#else
void quickMain(int* arrv, int arrc) {
#endif
	quickSort(arrv, 0, arrc, 0);
}

#ifdef __VSCODE
#include "sorting.c"
#endif