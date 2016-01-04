#ifndef C_LIST
#define C_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mem_tools.c"

/* NODE STRUCT */

typedef struct Node{
   void* data;
   struct Node* next;


}Node;

void setNode(Node* node, void* d, Node* inBefore, const DATA_TYPE type){
   safeMalloc(type, d);	//Allocating room for data
   node->next = inBefore;
}

/* LIST STRUCT */

	/* LIST FUNCTION IMPLEMENTATIONS */

void* front_imp() { /* return head; */ }
void* back_imp() { /* return tail; */ }

bool insert_imp(const void* data, const DATA_TYPE type){ }
bool delete_node_imp(Node* node){ }

void print_node_imp(const Node* node){ }

void pop_front_imp(){ }
void pop_back_imp(){ }

void push_front_imp(const Node* node){ }
void push_back_imp(const Node* node){ }

void is_in_imp(const void* data, const DATA_TYPE type){ }
void* find_imp(const void* data, const DATA_TYPE type){ }


typedef struct List{
	/* LIST DATA */
   Node* head;
   Node* tail;
   char type;

   void* (*front)();
   void* (*back)();

   bool  (*insert)(const void*, const DATA_TYPE);
   bool  (*delete_node)(Node*);

   void  (*print_node)(const Node*);

   void  (*pop_front)();
   void  (*pop_back)();

   void  (*push_front)(const Node*);
   void  (*push_back)(const Node*);

   void  (*is_in)(const void*, const DATA_TYPE);
   void* (*find)(const void*, const DATA_TYPE);
}List;

	/* CONSTRUCTOR AND FUNCTION POINTERS */
set_list(List* l, const char t){
   l->type = t;
   l->tail = (Node*)malloc(sizeof(Node));
   l->head = (Node*)malloc(sizeof(Node));
   setNode(l->tail, NULL, NULL, END);		/* head and tail have type NULL*/
   setNode(l->head, NULL, l->tail, BEGIN);

   /* Function pointers go here
      Refer to: http://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work
   */

   l->front = front_imp;	//Establishing funct. pointer values
   l->back = back_imp;

   l->insert = insert_imp;
   l->delete_node = delete_node_imp;

   l->print_node = print_node_imp;

   l->pop_front = pop_front_imp;
   l->pop_back = pop_back_imp;

   l->push_front = push_front_imp;
   l->push_back = push_back_imp;

   l->is_in = is_in_imp;
   l->find = find_imp;
}

#endif
