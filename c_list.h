#ifndef C_LIST
#define C_LIST

#include <stdio.h>
#include <cstdlib>
#include "mem_tools.h"

/* NODE STRUCT */

struct Node{
   void* data;
   Node* next;

   Node(void* d = NULL, Node* n = NULL, const char& type = 'n'){
      safeMalloc(type, d);
      next = n;
   }
};

/* LIST STRUCT */

	/* LIST FUNCTION IMPLEMENTATIONS */

void* frontList_imp() { /* return head; */ }
void* backList_imp() { /* return tail; */ }

void insert_imp(const void* data, const char& type){ }
void deleteNode_imp(Node* node){ }

void printNode_imp(const Node*){ }

void pop_front_imp(){ }
void pop_back_imp(){ }

void push_front_imp(){ }
void push_back_imp(){ }

void isIn_imp(const void* data, const char& type){ }
void* find_imp(const void* data, const char& type){ }


struct List{
	/* LIST DATA */
   Node* head;
   Node* tail;
   char type;

	/* CONSTRUCTOR AND FUNCTION POINTERS */
   List(const char& t)
   {
      type = t;
      tail = Node(NULL);		/* head and tail have type NULL*/
      head = Node(NULL, tail);

      /* Function pointers go here
         Refer to: http://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work
      */

      void* (*frontList)() /*= &frontList_imp*/;
      void* (*backList)() /*= &backList_imp*/;

      void  (*insert)(const void*, const char&) /*= &insert_imp*/;
      void  (*deleteNode)(Node*) /*= &deleteNode*/;

      void  (*printNode)(const Node*) /*= &printNode_imp*/;

      void  (*pop_front)() /*= &pop_front_imp*/;
      void  (*pop_back)() /*= &pop_back_imp*/;

      void  (*push_front)() /*= &push_front_imp*/;
      void  (*push_back)() /*= &push_back_imp*/;

      void  (*isIn)(const void*, const char&) /*= &isIn_imp*/;
      void* (*find)(const void*, const char&) /*= &find_imp*/;
   }

};

#endif
