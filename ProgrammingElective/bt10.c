#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 10000

int bt10_main() {
	short* numv = malloc(MAX_SIZE * sizeof(short)); // short numv[MAX_SIZE];
	if (numv == NULL) return 2; // memory failed to initialize
	char line[8];
	int numc, i;
	int freqc = (int)pow(2, sizeof(short) * 8); // as many elements as possible short values
	FILE* fp = fopen("numbers.txt", "r");
	if (fp == NULL) return 1; // file failed to open
	for (i = 0; i < MAX_SIZE; ++i) {
		if (fgets(line, 8, fp) != NULL) {
			numv[i] = atoi(line);
		} else {
			break; // end of file, end prematurely
		}
	}
	fclose(fp); // close file as soon as we're done with it
	numc = i;
	float minim, maxim, summus, avg;
	int* freqs = calloc(freqc, sizeof(int)); // int freqs[freqc]; and zero
	if (freqs == NULL) return 2; // memory failed to initialize
	minim = INFINITY;
	maxim = -INFINITY;
	summus = 0;
	for (i = 0; i < numc; ++i) {
		if (numv[i] > maxim) {
			maxim = numv[i];
		}
		if (numv[i] < minim) {
			minim = numv[i];
		}
		summus += numv[i];
		freqs[numv[i]]++;
	}
	avg = summus / numc;
	printf("Mean:\t%.2f\n", avg);
	printf("Max:\t%d\n", (int)maxim);
	printf("Min:\t%d\n", (int)minim);
	free(numv); // free as soon as we're done with it
	printf("writing to frequency.txt... ");
	fp = fopen("frequency.txt", "w");
	if (fp == NULL) return 1; // file failed to open
	for (i = 0; i < freqc; ++i) {
		if (!freqs[i]) continue;
		fprintf(fp, "%d: %d\n", i, freqs[i]);
	}
	fclose(fp); // close file as soon as possible
	free(freqs); // likewise free memory
	printf("done.\n");
	system("pause");
	return 0;
}