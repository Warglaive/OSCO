//part of source file LL.c
#include "LL.h"
#include "stdio.h"
#include "stdbool.h"
void addFrontLL(LL* list, int number) {
	node* newNode;
	newNode = malloc(sizeof(node));

	newNode->value = number;
	newNode->next = list->head;
	list->head = newNode;
}
void constructLL(LL* list) {
	node* n;
	n = malloc(sizeof(node));
	n->next = NULL;
	list->head = n;
	list->tail = n;
}
void destructLL(LL* list) {
	free(list);
}
void printLL(LL* list) {
	//print head
	node* currentHeadNode = list->head;
	while (currentHeadNode->next != NULL)
	{
		printf("LL elements: %d\n", currentHeadNode->value);
		currentHeadNode = currentHeadNode->next;
	}
	// print tail
	node* currentTailNode = list->tail;
	while (currentTailNode->next != NULL)
	{
		printf("LL elements: %d\n", currentTailNode->value);
		currentTailNode = currentTailNode->next;
	}

}
int countLL(LL* list) {
	int result = 0;
	node* currentNode = list->head;
	while (currentNode->next != NULL)
	{
		result++;
		currentNode = currentNode->next;
	}
	return result;
}
void addRearLL(LL* list, int number) {
	node* newNode;
	newNode = malloc(sizeof(node));

	newNode->value = number;
	newNode->next = list->tail;
	list->tail = newNode;
}
void deleteLL(LL* list, int number) {
	//check head 
	node* currentHeadNode = list->head;
	while (currentHeadNode->value == number)
	{
		list->head->value= NULL; //delete
		//return;
	}
	//check tail
	node* currentTailNode = list->tail;
	while (currentTailNode->value == number)
	{
		list->tail->value = NULL; //delete
		return;
	}
}
void copyLL() {

}