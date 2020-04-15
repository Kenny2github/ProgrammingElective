#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bt4_main() {
	double a, b, c, delta;
	int ret = 0;
	printf("Solving quadratic equation: ax^2 +bx +c\na?\t");
	scanf("%lf", &a);
	printf("b?\t");
	scanf("%lf", &b);
	printf("c?\t");
	scanf("%lf", &c);

	if (a == 0) {
		printf("a=0, not quadratic!\n");
		ret = 1;
		goto end;
	}
	delta = b*b - 4*a*c;
	if (delta < 0) {
		printf("No real roots!\n");
		goto end;
	}
	if (delta == 0) {
		printf("Double roots:\n%.4f\n", (-b + sqrt(delta)) / (2*a));
		goto end;
	}
	printf("Two real roots:\n%.4f and %.4f\n", (-b + sqrt(delta)) / (2*a), (-b - sqrt(delta)) / (2*a));
	end:
	system("pause");
	return ret;
}
