#include <stdio.h>
#include <math.h>
#define SQR(__x) ((__x) * (__x))

struct Point {
	double x;
	double y;
};

struct Point midpoint(struct Point a, struct Point b) {
	struct Point result;
	result.x = (a.x + b.x) / 2;
	result.y = (a.y + b.y) / 2;
	return result;
}

double distance(struct Point a, struct Point b) {
	return sqrt(SQR(a.x - b.x) + SQR(a.y - b.y));
}

void formula(struct Point p1, struct Point p2) {
	double a, b, c; // coefficients of x, y, and 1 respectively
	a = p2.y - p1.y;
	b = p1.x - p2.x;
	c = p2.x * p1.y - p1.x * p2.y;
	if (a < 0) {
		// keep a positive
		a = -a, b = -b, c = -c;
	}
	if (fabs(a) == fabs(b)) {
		// reduce coefficients
		c /= a;
		b /= a;
		a /= a;
	}
	printf("The formula is %.2lfx%+.2lfy%+.2lf = 0\n", a, b, c);
}

void collinear(struct Point p1, struct Point p2, struct Point p3) {
	// If the area of a triangle formed by the three points is zero,
	// then the three points are collinear.
	// The area is not divided by 2 because we only check if it's zero;
	// 0/2 == 0.
	double area = p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
	if (area == 0) {
		printf("The three points are on the same line!\n");
		formula(p1, p2);
	}
}

int bt15_main() {
	struct Point p1, p2, p3, m;
	double dist;
	printf("Enter the coordinates of point 1: ");
	scanf("%lf %lf", &p1.x, &p1.y);
	printf("Enter the coordinates of point 2: ");
	scanf("%lf %lf", &p2.x, &p2.y);
	printf("Enter the coordinates of point 3: ");
	scanf("%lf %lf", &p3.x, &p3.y);
	// input done

	m = midpoint(p1, p2);
	printf("Midpoint of points 1 and 2: (%.2lf, %.2lf)\n", m.x, m.y);
	dist = distance(p1, p2);
	printf("Distance between points 1 and 2: %.2lf\n", dist);
	formula(p1, p2);
	collinear(p1, p2, p3);
	return 0;
}