#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bt5_main()
{
	float a, b; // input numbers
	char op; // operator
	float result = 0; // have default value to suppress warnings
	int ret = 0; // terminal return value

	// prompt
	printf("Enter a simple math expression with two operands (Example: 3 + 2)\nSeparate them with a space\n");
	printf("(Operator supported: +  -  *  / ^)\n\n");
	scanf("%f %c %f", &a, &op, &b); // format specified in prompt
	switch (op) {
		// implement operators
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
		result = pow(a, b); // C has no exponent operator
		break;
	default:
		ret = 1; // if none match, that's an error
		break;
	}
	printf("Result: %.2f %c %.2f = ", a, op, b); // echo back input
	// if ret != 0, then there was an error; otherwise print result to 2 d.p.
	printf(ret ? "Error! operator is not correct\n" : "%.2f\n", result);
	system("pause");
	return ret;
}