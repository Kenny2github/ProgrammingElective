#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bt5_main()
{
	float a, b, result = 0;
	char op;
	int ret = 0;

	printf("Enter a simple math expression with two operands (Example: 3 + 2)\nSeparate them with a space\n");
	printf("(Operator supported: +  -  *  / ^)\n\n");
	scanf("%f %c %f", &a, &op, &b);
	switch (op) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	case '^':
		result = pow(a, b);
		break;
	default:
		ret = 1;
		break;
	}
	printf("Result: %.2f %c %.2f = ", a, op, b);
	printf(ret ? "Error! operator is not correct\n" : "%.2f\n", result);
	system("pause");
	return ret;
}