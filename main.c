#include <stdio.h>
#include "string.h"

int main () {
   char str[50];

   strcpy(str, "This is tutorialspoint.com");

   printf("reverse of |%s| is ", str);
   printf("|%s|\n",strreverse(str)) ;  
   return(0);
}