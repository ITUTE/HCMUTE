#include <stdio.h>
#include <string.h>


int main()
{
   char haystack[100] = "Hello ever";
   char needle[10] = "lo";
   char *ret;

   ret = strstr(haystack, needle);

   printf("Chuoi con la: %s\n", ret);
   
   return(0);
}
