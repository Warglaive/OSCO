#ifndef LL_H
#define LL_H

typedef struct Snode {
	int value;
	struct Snode* next;
} Node;

typedef struct list {
	Node* head;
	Node* tail;
	long size;
} LL;

void constructLL(LL* list);

void addFrontLL(LL* list, int number);

void addRearLL(LL* list, int number);

void printLL(LL* list);

long countLL(LL* list);

void deleteLL(LL* list, Node* n);

void destructLL(LL* list);

void copyLL(LL* original, LL* copy);

#endif