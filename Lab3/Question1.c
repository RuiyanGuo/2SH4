#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

char *my_strcat(const char * const str1, const char * const str2);

char *my_strcat(const char * const str1, const char * const str2)
{

	/* this is the pointer holding the string to return */
	char *z = NULL;
	int z_size;
    int i;
    int j;
	/*write your implementation here*/
    z_size=strlen(str1)+strlen(str2)+1;
    z=malloc(z_size*sizeof(char));
    for(i=0; i<strlen(str1); i++)
       {
    	 z[i]=str1[i];
       }
    i=0;
    for(j=strlen(str1); j<(z_size-1); j++)
       {
       	 z[j]=str2[i];
       	 i++;
       }


	/* finally, return the string*/
	return z;
	
}
