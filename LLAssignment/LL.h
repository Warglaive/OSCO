/*part of header file LL.h*/
#ifndef LL_H
#define LL_H

struct Snode {
	int value; //node data
	struct Snode* next; //next node
};

typedef struct Snode node;

struct list {
	node* head;
	node* tail;
};

typedef struct list LL;

// .....
//void addFrontLL(LL* list,int number);
// .....

#endif
/*eof LL.h*/
//  On the /*???*/ part in later steps you need to add a node pointer there. On the dots ..... other prototypes need to be defined