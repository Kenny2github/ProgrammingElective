#include <stdio.h>
#include <stdbool.h>
#define COUNT 1000

// declare statically to not fill up stack
int numbers[COUNT];
void recursiveBubble(int* arrv, int arrc);

bool checkSorted(int* arrv, int arrc) {
	for (register int i = 0; i < arrc - 1; ++i) {
		if (arrv[i + 1] < arrv[i]) {
			return false;
		}
	}
	return true;
}

int sorting_main() {
	FILE* fp = fopen("numbers.txt", "r");
	if (!fp) return 1;
	register int i;
	for (i = 0; i < COUNT; ++i) {
		fscanf(fp, "%d", numbers + i);
	}
	fclose(fp);
	// <CHANGED BETWEEN TASKS>
	recursiveBubble(numbers, COUNT);
	// </CHANGED BETWEEN TASKS>
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