#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMES 200

/* BT14 Me on the Guest List? */
int bt14_main()
{
    FILE* fp;
    fp = fopen("names.txt", "r");
    if (fp == NULL) return 1;
    char names[NAMES][25];
    char* p;

    /* Get each name into names[] and replace \n with \0 (NULL) */
    int i = 0;
    while ((fgets(names[i], sizeof(names[i]), fp)) != NULL) {
        if ((p = strchr(names[i], '\n')) != NULL) {
            *p = '\0';
        }
        ++i;
    }
    fclose(fp);

    /*read keyword from the keyboard and remove the line break at the end*/
    printf("Name? ");
    char keyword[25];
    if (fgets(keyword, sizeof(keyword), stdin) != NULL) {
        if ((p = strchr(keyword, '\n')) != NULL) {
            *p = '\0';
        }
    }

    /*perform a sequential search and output the line number if found*/

    int linev[NAMES];
    int linec = 0;
    for (i = 0; i < NAMES; ++i) {
        // strcmp returns 0 if equal
        if (strcmp(keyword, names[i]) == 0) {
            linev[linec++] = i + 1;
        }
    }

    if (linec == 0) {
        printf("'%s' not found\n", keyword);
    } else {
        printf("'%s' found in line: %d", keyword, linev[0]);
        for (i = 1; i < linec; ++i) {
            printf(", %d", linev[i]);
        }
        printf("\n");
    }

    //system("pause");
    return 0;
}