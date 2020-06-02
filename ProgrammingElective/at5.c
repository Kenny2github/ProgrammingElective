void insertionSort(int* arrv, int arrc) {
	register int i, j, tmp, hold;
	for (i = 1; i < arrc; ++i) {
		for (j = i - 1; arrv[j + 1] < arrv[j]; --j) {
			// swap
			tmp = arrv[j];
			arrv[j] = arrv[j + 1];
			arrv[j + 1] = tmp;
		}
	}
}