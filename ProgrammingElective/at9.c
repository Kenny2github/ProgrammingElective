#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct list_item {
	int value;
	struct list_item* next;
	struct list_item* prev;
} list_item;

typedef struct linked_list {
	list_item* start;
	list_item* end;
} linked_list;

list_item* create_item(int value) {
	list_item* item = malloc(sizeof(list_item));
	item->value = value;
	item->next = item->prev = NULL;
	return item;
}

linked_list* create_list() {
	linked_list* list = malloc(sizeof(linked_list));
	list->start = list->end = NULL;
	return list;
}

void delete_list(linked_list* list) {
	free(list);
}

void append(linked_list* list, int value) {
	list_item* item = create_item(value);
	if (list->end != NULL) {
		// link original end to appended item and put item at end
		item->prev = list->end;
		list->end->next = item;
	}
	else {
		// if end is null, then start must be too
		list->start = item;
	}
	list->end = item;
}

void prepend(linked_list* list, int value) {
	list_item* item = create_item(value);
	if (list->start != NULL) {
		// link original start to prepended item and put item at start
		item->next = list->start;
		list->start->prev = item;
	}
	else {
		// if start is null, then end must be too
		list->end = item;
	}
	list->start = item;
}

void remove_item(linked_list* list, list_item* item) {
	// update the start and end, if necessary
	// conveniently, if the item is at the start or end,
	// its next or end will already be null
	if (list->start == item) {
		list->start = item->next;
	}
	if (list->end == item) {
		list->end = item->prev;
	}
	// link the items on both sides to each other, instead of to item
	if (item->prev != NULL) {
		item->prev->next = item->next;
	}
	if (item->next != NULL) {
		item->next->prev = item->prev;
	}
	// free up memory taken by the item
	free(item);
}

bool contains(linked_list* list, int value) {
	list_item* item = list->start;
	while (item != NULL) {
		if (item->value == value) return true;
		item = item->next;
	}
	return false;
}

void print_list(linked_list* list) {
	printf("The list: ");
	list_item* item = list->start;
	while (item != NULL) {
		if (item->next != NULL) printf("%d <-> ", item->value);
		else printf("%d\n", item->value);
		item = item->next;
	}
}

#ifdef __VSCODE
int main() {
#else
int at9_main() {
#endif
	linked_list* list = create_list();
	FILE* fp = fopen("numbers.txt", "r");
	if (!fp) return 1;
	register int i;
	int num;
	for (i = 0; i < 10; ++i) {
		fscanf(fp, "%d", &num);
		append(list, num);
	}
	fclose(fp);
	print_list(list);
	printf("First: %d\n", list->start->value);
	printf("Last: %d\n", list->end->value);
	
	for (i = 0; i < 2; ++i) {
		printf("Enter a number to find: ");
		scanf("%d", &num);
		if (contains(list, num)) printf("Found %d\n", num);
		else printf("Could not find %d\n", num);
	}

	remove_item(list, list->start);
	printf("First item removed. ");
	print_list(list);
	remove_item(list, list->end);
	printf("Last item removed. ");
	print_list(list);

	printf("Enter number to prepend: ");
	scanf("%d", &num);
	prepend(list, num);
	printf("Prepended %d. ", num);
	print_list(list);

	printf("Enter number to append: ");
	scanf("%d", &num);
	append(list, num);
	printf("Appended %d. ", num);
	print_list(list);

	// clean up memory
	while (list->start != NULL) remove_item(list, list->start);
	delete_list(list);
	return 0;
}