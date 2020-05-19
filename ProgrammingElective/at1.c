#include <stdio.h>
#include <stdlib.h>

char stack[500];
int top = -1;

char isEmpty() {
	return top == -1;
}

void push(char ch) {
	stack[++top] = ch;
}

char pop() {
	if (top < 0) return '\0';
	return stack[top--];
}

void printStack() {
	for (int i = 0; i <= top; ++i) {
		printf("%c", stack[i]);
	}
	printf("\n");
}

int at1_main() {
	char action, pushed;
	do {
		printf("Enter your action.\no - print out the stack\np - push an item onto the stack\nr - pop and print an item from the stack\ne - check if the stack is empty\nq - quit\nAction: ");
		scanf(" %c", &action);
		printf("\n");
		switch (action) {
		case 'o':
			printStack();
			break;
		case 'p':
			printf("Character to push: ");
			scanf(" %c", &pushed);
			push(pushed);
			break;
		case 'r':
			printf("Character popped: %c\n", pop());
			break;
		case 'e':
			printf(isEmpty() ? "Empty\n" : "Not empty\n");
			break;
		}
		printf("\n");
	} while (action != 'q' && action != 'Q');
	return 0;
}