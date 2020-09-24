#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

void pattern_1(int rows);
void pattern_2(int rows);
void pattern_3(int rows);
void pattern_4(int rows);
void pattern_5(int amplitude, int period, int length);

#ifdef __VSCODE
int main() {
#else
int bt8_main() {
#endif
	int rows, ampl, period, length;
	char cont = 'Y';
	do {
		system("cls");
		printf("Number of rows? (1-9)\t");
		scanf("%d", &rows);
		if (rows < 1 || rows > 9) continue;
		pattern_1(rows);
		pattern_2(rows);
		pattern_3(rows);
		pattern_4(rows);
		printf("\nEnter amplitude (in rows away from normal), period (in columns) and number of columns to generate, separated by spaces: ");
		scanf("%d %d %d", &ampl, &period, &length);
		pattern_5(ampl, period, length);
		printf("\nAgain? [Y/N] ");
		scanf(" %c", &cont);
	} while (cont == 'Y' || cont == 'y');
	return 0;
}

void pattern_1(int rows) {
	register int i, j;
	printf("\nPattern #1\n\n");
	for (i = 1; i <= rows; ++i) {
		for (j = rows; j >= 1; --j) {
			if (j > i) printf(" ");
			else printf("%d", j);
		}
		printf("\n");
	}
}

void pattern_2(int rows) {
	register int i, j;
	int current = 0;
	printf("\nPattern #2\n\n");
	for (i = 1; i <= rows; ++i) {
		for (j = 1; j <= i; ++j) {
			printf("%d ", ++current);
		}
		printf("\n");
	}
}

void pattern_3(int rows) {
	register int i, j;
	printf("\nPattern #3\n\n");
	for (i = 1; i <= rows; ++i) {
		for (j = 1; j <= rows; ++j) {
			if (j == i || j == (rows - i + 1)) printf("%d", j);
			else printf(" ");
		}
		printf("\n");
	}
}

void pattern_4(int rows) {
	register int i, j;
	printf("\nPattern #4\n\n");
	for (i = 1; i <= rows; ++i) {
		for (j = rows; j >= 1; --j) {
			if (j > i) printf(" ");
			else printf("%d", i - j + 1);
		}
		for (j = i - 1; j >= 1; --j) {
			printf("%d", j);
		}
		printf("\n");
	}
}

void pattern_5(int amplitude, int period, int length) {
	register int i, j;
	double value;
	printf("\nSine wave\n\n");
	for (i = amplitude; i >= -amplitude; --i) {
		for (j = 0; j < length; ++j) {
			value = sin(2 * M_PI * (double)j / (double)period) * amplitude;
			if (round(value) == i) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}