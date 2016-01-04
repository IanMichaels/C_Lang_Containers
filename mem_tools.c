#ifndef C_MEM_TOOLS
#define C_MEM_TOOLS

#include <stdlib.h>
#include <stdbool.h>

typedef enum DATA_TYPE{

   CHAR,
   UNSIGNED_CHAR,
   SIGNED_CHAR,
   INT,
   UNSIGNED_INT,
   SHORT,
   SHORT_INT,
   UNSIGNED_SHORT,
   UNSIGNED_SHORT_INT,
   LONG,
   LONG_INT,
   UNSIGNED_LONG,
   UNSIGNED_LONG_INT,
   FLOAT,
   DOUBLE,
   LONG_DOUBLE,
   BEGIN,
   END
}DATA_TYPE;

bool safeMalloc(const DATA_TYPE type, void* ptr);
void safeFree(void* ptr);

/* safeMalloc expects the item that memory will be allocated for and pointed
   to by the second parameter. The ptr is expected to be set to 0 if it
   does not point to anything. If it does point to something, the function
   will attempt to delete what the pointer points at.
*/

bool safeMalloc(const DATA_TYPE type, void* ptr){

   safeFree(ptr);

   switch(type){
      case CHAR:
            ptr = malloc(sizeof(char));
            break;
      case UNSIGNED_CHAR:
            ptr = malloc(sizeof(unsigned char));
            break;
      case SIGNED_CHAR:
            ptr = malloc(sizeof(signed char));
            break;
      case INT:
            ptr = malloc(sizeof(int));
            break;
      case UNSIGNED_INT:
            ptr = malloc(sizeof(unsigned int));
            break;
      case SHORT:
      case SHORT_INT:
            ptr = malloc(sizeof(short));
            break;
      case UNSIGNED_SHORT:
      case UNSIGNED_SHORT_INT:
            ptr = malloc(sizeof(unsigned short));
            break;
      case LONG:
      case LONG_INT:
            ptr = malloc(sizeof(long));
            break;
      case UNSIGNED_LONG:
      case UNSIGNED_LONG_INT:
            ptr = malloc(sizeof(unsigned long));
            break;
      case FLOAT:
            ptr = malloc(sizeof(float));
            break;
      case DOUBLE:
            ptr = malloc(sizeof(double));
            break;
      case LONG_DOUBLE:
            ptr = malloc(sizeof(long double));
            break;
      case BEGIN:
      case END:
            break;

      default:
         ptr = NULL;
   }

   if(ptr != NULL)
      return true;
   else
      return false;
}

void safeFree(void* ptr){

      free(ptr);
      ptr = NULL;
}

#endif
