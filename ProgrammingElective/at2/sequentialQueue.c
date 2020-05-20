#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 15

char sequential_queue[SIZE];
// position to the left of the item
int sequential_start = 0, sequential_end = 0;

bool sequential_isEmpty() {
	return sequential_start == sequential_end;
}
bool sequential_isFull() {
	return sequential_end == SIZE;
}
void sequential_enQueue(char ch) {
	if (sequential_isFull()) return;
	sequential_queue[sequential_end++] = ch;
}
char sequential_deQueue() {
	if (sequential_isEmpty()) return '\0';
	return sequential_queue[sequential_start++];
}

void sequential_printQueue() {
	for (register int i = sequential_start; i < SIZE; ++i) {
		printf("%c", sequential_queue[i]);
	}
	printf("\n");
}

int sequential_at2_main() {
	char action, pushed;
	do {
		printf("Enter your action.\no - print out the queue\np - push an item onto the queue\nr - pop and print an item from the queue\ne - check if the queue is empty\nf - check if the queue is full\nq - quit\nAction: ");
		scanf(" %c", &action);
		printf("\n");
		switch (action) {
		case 'o':
			sequential_printQueue();
			break;
		case 'p':
			printf("Character to push: ");
			scanf(" %c", &pushed);
			sequential_enQueue(pushed);
			break;
		case 'r':
			printf("Character popped: %c\n", sequential_deQueue());
			break;
		case 'e':
			printf(sequential_isEmpty() ? "Empty\n" : "Not empty\n");
			break;
		case 'f':
			printf(sequential_isFull() ? "Full\n" : "Not full\n");
			break;
		}
		printf("\n");
	} while (action != 'q' && action != 'Q');
	return 0;
}