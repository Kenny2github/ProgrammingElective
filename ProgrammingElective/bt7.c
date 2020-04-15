#include <stdio.h>
#include <stdlib.h>

/**************************
Printing Pattern Demo
- To print a simple triangle pattern with n rows
**************************/

int bt7_main() {

    int i, j, n;
    char isContinue = 'N';

    do {
        system("cls"); // clear the screen, works on PC only, on Mac try: system("clear")

        printf("Number of rows (1-9)?\t");
        scanf("%d", &n);

        //------------------------------
        //generate the triangle pattern
        //------------------------------
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                printf("%d", j);
            }
            printf("\n");
        }


        printf("\nTry again? [Y/N] ");

        scanf(" %c", &isContinue);

    } while (isContinue == 'Y' || isContinue == 'y');
}