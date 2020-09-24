#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __VSCODE
int main() {
#else
int bt4_main() {
#endif
	double a, b, c, delta;
	int ret = 0;
	printf("Solving quadratic equation: ax^2 +bx +c\na?\t");
	scanf("%lf", &a);
	printf("b?\t");
	scanf("%lf", &b);
	printf("c?\t");
	scanf("%lf", &c);
	// end input

	if (a == 0) {
		printf("a=0, not quadratic!\n");
		ret = 1; // mark as error
		goto end; // pause and done
	}
	delta = b*b - 4*a*c; // formula for discriminant
	if (delta < 0) {
		printf("No real roots!\n");
		goto end;
	}
	if (delta == 0) {
		printf("Double roots:\n%.4f\n", -b / (2*a)); // sqrt(0) = 0
		goto end;
	}
	printf("Two real roots:\n%.4f and %.4f\n", (-b + sqrt(delta)) / (2*a), (-b - sqrt(delta)) / (2*a)); // print +- roots
	end: // comes from three places
	system("pause");
	return ret;
}
