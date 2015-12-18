#ifndef C_MEM_TOOLS
#define C_MEM_TOOLS

#include <cstdlib>

bool safeMalloc(const char& type, void* ptr);
void safeFree(void* ptr);

/* safeMalloc expects a single character to represent the datatype that
   should be allocated for the void ptr. The function supports uppercase and
   lowercase chars for datatype dictation. It expects input 's' or 'S' for
   c-strings. The ptr is expected to be set to 0 if it does not point to
   anything. If it does point to something, the function will attempt to
   delete what the pointer points at.
*/

bool safeMalloc(const char& type, void* ptr){

   safeFree(ptr);

   switch(type){
      case 'c':
      case 'C':
            ptr = malloc(sizeof(char));
            break;
      case 'i':
      case 'I':
            ptr = malloc(sizeof(int));
            break;
      case 'd':
      case 'D':
            ptr = malloc(sizeof(double));
            break;
      case 'f':
      case 'F':
            ptr = malloc(sizeof(float));
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
