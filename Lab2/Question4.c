#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]);

void letter_freq(const char word[], int freq[])
{
//Count the number of characters in the string
   int total=0;
   int i;

   for(i=0; word[i]!='\0'; i++)
     {
	   if(word[i]=='\0')
         {
    	   break;
         }
	   else
	     {
		   total=total+1;
	     }

     }
//************

//Main body of the code
   int hold;  //It holds the character that is going to be checked
   int j;
   int count=0;   //Count the number of the identical character appeared
   int position;  //Indicate which position in the array that the  character should be placed

   for(j=0; j<total; j++)
     {
	   hold=word[j];
	   if((hold>=97)&&(hold<=122))
	     {
		   position=hold-97;
		   count=freq[position];
		   count=count+1;
		   freq[position]=count;
		   count=0;
	     }
	   if((hold>=65)&&(hold<=90))
	   	 {
	   	   position=hold-65;
	   	   count=freq[position];
	   	   count=count+1;
	   	   freq[position]=count;
	   	   count=0;
	   	 }

     }
//*************
   
}
