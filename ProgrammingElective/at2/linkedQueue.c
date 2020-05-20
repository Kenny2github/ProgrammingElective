#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linked_item {
	char value;
	struct linked_item* next;
	struct linked_item* prev;
} linked_item;

struct {
	linked_item* start;
	linked_item* end;
} linked_queue = { NULL, NULL };

bool linked_isEmpty() {
	return linked_queue.start == NULL;
}
bool linked_isFull() {
	return false; // queue length limited only by memory
}
void linked_enQueue(char ch) {
	linked_item* item = malloc(sizeof(linked_item));
	item->prev = linked_queue.end;
	item->next = NULL;
	item->value = ch;
	if (linked_queue.end) linked_queue.end->next = item;
	if (!linked_queue.start) linked_queue.start = item;
	linked_queue.end = item;
}
char linked_deQueue() {
	if (linked_isEmpty()) return '\0';
	linked_item* item = linked_queue.start;
	char val = item->value;
	linked_queue.start = item->next;
	if (linked_queue.start) linked_queue.start->prev = NULL;
	free(item);
	return val;
}

void linked_printQueue() {
	linked_item* item = linked_queue.start;
	while (item) {
		printf("%c", item->value);
		item = item->next;
	}
	printf("\n");
}

int linked_at2_main() {
	char action, pushed;
	do {
		printf("Enter your action.\no - print out the queue\np - push an item onto the queue\nr - pop and print an item from the queue\ne - check if the queue is empty\nf - check if the queue is full\nq - quit\nAction: ");
		scanf(" %c", &action);
		printf("\n");
		switch (action) {
		case 'o':
			linked_printQueue();
			break;
		case 'p':
			printf("Character to push: ");
			scanf(" %c", &pushed);
			linked_enQueue(pushed);
			break;
		case 'r':
			printf("Character popped: %c\n", linked_deQueue());
			break;
		case 'e':
			printf(linked_isEmpty() ? "Empty\n" : "Not empty\n");
			break;
		case 'f':
			printf(linked_isFull() ? "Full\n" : "Not full\n");
			break;
		}
		printf("\n");
	} while (action != 'q' && action != 'Q');
	return 0;
}