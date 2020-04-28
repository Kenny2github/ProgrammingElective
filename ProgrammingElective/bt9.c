#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bt9_main()
{
    float num[5];
    int length_of_array = 0;

    /* Print basic information about the array */
    printf("---------------------------------------\n");
    printf("Size of array num[]:\t%2d bytes\n", sizeof(num));
    printf("Size of each element:\t%2d bytes\n", sizeof(num[0]));

    length_of_array = sizeof(num) / sizeof(num[0]);
    printf("The array num[] has %d elements\n", length_of_array);
    printf("---------------------------------------\n\n");


    /* Print basic information about the array */
    printf("Getting numbers into the array...\n\n");

    int i;
    for (i = 0; i < length_of_array; ++i) {
        printf("num[%d] = ", i);
        scanf("%f", &num[i]);
    }

    printf("\nContent stored in the array...\n");
    printf("---------------------------------------\n");

    for (i = 0; i < length_of_array; ++i) {
        printf("num[%d]\t", i);
    }
    printf("\n");
    for (i = 0; i < length_of_array; ++i) {
        printf("%.2f\t", num[i]);
    }

    printf("\n---------------------------------------\n");
    float minim, maxim, summus, avg;
    minim = INFINITY; // any value is smaller
    maxim = -INFINITY; // any value is larger
    summus = 0;
    for (i = 0; i < length_of_array; ++i) {
        if (num[i] > maxim) {
            maxim = num[i];
        }
        if (num[i] < minim) {
            minim = num[i];
        }
        summus += num[i];
    }
    avg = summus / length_of_array;
    printf("Max\t = %.2f\n", maxim);
    printf("Min\t = %.2f\n", minim);
    printf("Sum\t = %.2f\n", summus);
    printf("Average\t = %.2f\n", avg);

    system("pause");
    return 0;
}