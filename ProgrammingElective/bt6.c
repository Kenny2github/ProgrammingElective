#include <stdlib.h>
#include <stdio.h>

int bt6_main() {
	int start, cols, upto, row, col;
	printf("Starting from? [1-90] ");
	scanf("%d", &start);
	if (start < 1 || start > 90) return 1;
	printf("No. of columns? [1-10] ");
	scanf("%d", &cols);
	if (cols < 1 || cols > 10) return 1;
	printf("Multiples up to? [1-99] ");
	scanf("%d", &upto);
	if (upto < 1 || upto > 99) return 1;
	//end input
	for (row = 1; row <= upto; row++) {
		for (col = start; col <= (start + cols); col++) {
			printf(" %2dx%2d=%4d\t|", col, row, col * row);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}