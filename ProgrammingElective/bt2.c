#include <stdlib.h>
#include <stdio.h>
#define PI 3.141592654

int bt2_main() {
	double radius;
	printf("Radius?\t");
	scanf("%lf", &radius);
	printf("Area:\t%.4f\n", radius * radius * PI);
	system("pause");
	return 0;
}