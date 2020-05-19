#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[10001];
int top = -1;

char isEmpty() {
	return top < 0;
}

void push(char ch) {
	stack[++top] = ch;
}

char pop() {
	if (isEmpty()) return '\0';
	return stack[top--];
}

void printStack() {
	for (int i = 0; i <= top; ++i) {
		printf("%c", stack[i]);
	}
	printf("\n");
}

char parenMatches(char open, char close) {
	switch (open) {
	case '{':
		return close == '}';
	case '[':
		return close == ']';
	case '(':
		return close == ')';
	default:
		// not a brace, so can't match
		return 0;
	}
}

int at1_main() {
	char inp[10001];
	char ch; // character being processed
	int leng; // actual length of inp
	if (fgets(inp, 10001, stdin) == NULL) {
		printf("Yes\n");
		return 0;
	}
	char* posq;
	if ((posq = strchr(inp, '\n')) != NULL) *posq = '\0';
	leng = strlen(inp);
	if (leng == 0) {
		printf("Yes\n");
		return 0;
	}
	for (register int i = 0; i < leng; ++i) {
		ch = inp[i];
		if (ch == '{' || ch == '[' || ch == '(') {
			push(ch);
		}
		else if (ch == '}' || ch == ']' || ch == ')') {
			if (!parenMatches(pop(), ch)) {
				printf("No\n");
				return 0;
			}
		}
	}
	if (!isEmpty()) {
		// opened braces that were never closed
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	return 0;
}