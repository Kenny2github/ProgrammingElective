#include <stdbool.h>

#ifdef __VSCODE
void sortMain(int* arrv, int arrc) {
#else
void bubbleSort(int* arrv, int arrc) {
#endif
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

#ifdef __VSCODE
#include "sorting.c"
#endif