#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n);

void string_copy(const char source[], char destination[], int n)
{
//Check the total number of characters in the string
	   int total=0;
	   int i;

	   for(i=0; source[i]!='\0'; i++)
	     {
		   if(source[i]=='\0')
	         {
	    	   break;
	         }
		   else
		     {
			   total=total+1;
		     }

	     }
//*****************
//Main body of the code
	   int j;
	   int k=0;

	   for(j=0; j<(n-1); j++)
	      {
		     if(k<total)
		       {
		    	 destination[j]=source[k];
		    	 k++;
		    	 destination[j+1]='\0';
		       }
		     else
		       {
		    	 break;
		       }
	      }
//*****************


	
    
}
