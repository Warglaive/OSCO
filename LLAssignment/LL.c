#include "LL.h"
#include<stdio.h>
#include<stdlib.h>

void constructLL(LL* list) {
	Node* n;
	n = malloc(sizeof(Node));
	list->head = n;
	list->tail = n;
	list->head->next = list->tail;
	list->size = 0;
}

void addFrontLL(LL* list, int number) {
	Node* newNode;
	newNode = malloc(sizeof(Node));
	newNode->value = number;

	if (list->size == 0) {
		list->head = newNode;
		list->tail = newNode;
		list->head->next = list->tail;
		list->size++;
	}
	else {
		newNode->next = list->head;
		list->head = newNode;
		list->size++;
	}
}

void addRearLL(LL* list, int number) {
	Node* newNode;
	newNode = malloc(sizeof(Node));
	newNode->value = number;

	if (list->size == 0) {
		list->head = newNode;
		list->tail = newNode;
		list->head->next = list->tail;
		list->size++;
	}
	else {
		list->tail->next = newNode;
		list->tail = newNode;
		list->size++;
	}

}


long countLL(LL* list) {
	return list->size;
}

void printLL(LL* list) {
	Node* no = list->head;
	int i = 0;
	while (i < list->size) {
		printf("element: %d\n", no->value);
		no = no->next;
		i++;
	}
}

void deleteLL(LL* list, Node* node) {
	Node* toBeDeleted = list->head;
	Node* previous = toBeDeleted;
	while (toBeDeleted != node) {
		previous = toBeDeleted;
		toBeDeleted = toBeDeleted->next;
	}

	if (toBeDeleted == list->head) {
		list->head = list->head->next;
	}
	else if (toBeDeleted == list->tail) {
		list->tail = previous;
	}

	previous->next = toBeDeleted->next;
	free(toBeDeleted);
	list->size--;
}

void destructLL(LL* list) {
	int i = 0;
	while (i < list->size) {
		Node* node = list->head;
		deleteLL(list, node);
	}
}

void copyLL(LL* origin, LL* copy) {
	int i = 1;
	Node* node = origin->head;
	constructLL(copy);
	addFrontLL(copy, node->value);
	node = node->next;
	while (i < origin->size) {
		addRearLL(copy, node->value);
		node = node->next;
		i++;
	}
}