#include <stdio.h>
#include <string.h>

int main () {
   char dest[29]="Aman  Gupta";
   char src[29];
   int len;

   strcpy(src, "Tutorials Point    .");
   len = strxfrm(dest, src, 500);

   printf("Length of string |%s| is: |%d|", dest, len);
   
   return(0);
}