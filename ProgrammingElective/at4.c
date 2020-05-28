#include <stdio.h>
#include <stdbool.h>
#define COUNT 10000

// declare statically to not fill up stack
int numbers[COUNT];

void bubbleSort(int* arrv, int arrc) {
	register int i, j, tmp;
	bool sorted = false;
	// if sorted is still true by the end of the iteration,
	// the sorting is complete
	for (j = arrc - 1; j > 0 && !sorted; --j) {
		sorted = true;
		// every loop, at least one more element is finished
		for (i = 0; i < j; ++i) {
			// loop until before last finished element
			if (arrv[i + 1] < arrv[i]) {
				// swap
				tmp = arrv[i];
				arrv[i] = arrv[i + 1];
				arrv[i + 1] = tmp;
				sorted = false; // turn off flag
			}
		}
	}
}

bool checkSorted(int* arrv, int arrc) {
	for (register int i = 0; i < arrc - 1; ++i) {
		if (arrv[i + 1] < arrv[i]) {
			return false;
		}
	}
	return true;
}

int at4_main() {
	FILE* fp = fopen("numbers.txt", "r");
	if (!fp) return 1;
	register int i;
	for (i = 0; i < COUNT; ++i) {
		fscanf(fp, "%d", numbers + i);
	}
	fclose(fp);
	bubbleSort(numbers, COUNT);
	// output
	for (i = 0; i < COUNT; ++i) {
		printf("%d\t", numbers[i]);
	}
	if (checkSorted(numbers, COUNT)) {
		fprintf(stderr, "Sorted!\n");
	}
	else {
		fprintf(stderr, "I am a fool. A blongus. An absolute utter clampongus.\n");
	}
	return 0;
}