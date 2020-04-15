#include <stdlib.h>
#include <stdio.h>
#define PI 3.141592654

int bt2_main() {
	double radius; // radius of circle
	printf("Radius?\t"); // prompt
	scanf("%lf", &radius); // set radius to inputted number
	printf("Area:\t%.4f\n", radius * radius * PI); // pi r**2, to 4 d.p.
	system("pause"); // pause before returning
	return 0;
}