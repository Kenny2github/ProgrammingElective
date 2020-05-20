#include <stdio.h>
#include <stdbool.h>
#define SIZE 15

char circular_queue[SIZE];
// position to the left of the item
int circular_start = 0, circular_end = 0, circular_count = 0;

bool circular_isEmpty() {
	return circular_count == 0;
}
bool circular_isFull() {
	return circular_count == SIZE;
}
void circular_enQueue(char ch) {
	if (circular_isFull()) return;
	circular_queue[circular_end] = ch;
	circular_end = (circular_end + 1) % SIZE;
	++circular_count;
}
char circular_deQueue() {
	if (circular_isEmpty()) return '\0';
	char ret = circular_queue[circular_start];
	circular_start = (circular_start + 1) % SIZE;
	--circular_count;
	return ret;
}

void circular_printQueue() {
	for (register int i = 0; i < circular_count; ++i) {
		printf("%c", circular_queue[(circular_start + i) % SIZE]);
	}
	printf("\n");
}

int circular_at2_main() {
	char action, pushed;
	do {
		printf("Enter your action.\no - print out the queue\np - push an item onto the queue\nr - pop and print an item from the queue\ne - check if the queue is empty\nf - check if the queue is full\nq - quit\nAction: ");
		scanf(" %c", &action);
		printf("\n");
		switch (action) {
		case 'o':
			circular_printQueue();
			break;
		case 'p':
			printf("Character to push: ");
			scanf(" %c", &pushed);
			circular_enQueue(pushed);
			break;
		case 'r':
			printf("Character popped: %c\n", circular_deQueue());
			break;
		case 'e':
			printf(circular_isEmpty() ? "Empty\n" : "Not empty\n");
			break;
		case 'f':
			printf(circular_isFull() ? "Full\n" : "Not full\n");
			break;
		}
		printf("\n");
	} while (action != 'q' && action != 'Q');
	return 0;
}