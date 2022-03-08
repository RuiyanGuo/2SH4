#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){

	
    char **word_list;
    int n;
    int i;
    char holdword[20];
    /*write your implementation here*/
	FILE *input_file=fopen(input_filename, "r");
	fscanf(input_file,"%d", &n);
	*nPtr=n;
	word_list=(char**)calloc(n,sizeof(char*));
	for(i=0; i<n; i++)
	   {
		 fscanf(input_file,"%s", holdword);
		 word_list[i]=(char*)calloc((strlen(holdword)+1),sizeof(char));
         strcpy(word_list[i],holdword);
	   }

    return word_list;
    fclose(input_file);
}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/
	   int i=0;

       if(str1[i]<str2[i])
         {
    	    return 0;
         }
       if(str1[i]>str2[i])
         {
    	     return 1;
         }
}

void sort_words(char **words, int size){

	/*
	 Each time, choose a word to compare, start from the begging of the words list.
	 compare it with the rests of the words that remains in the list on by one to determine the right insertion point.
	 then swap it with the value at the right insertion point.
	 */
	int i,j;
	char* hold1;
	char* hold2;
	int index;
	/*write your implementation here*/
    for(i=0; i<size; i++)
      {
    	hold1=words[i];
    	index=i;
    	for(j=i+1; j<size; j++)
    	  {
    		if(compare_str(hold1,words[j])==1)
    		 {
    			hold1=words[j];
    			index=j;
    		 }
    	  }
    	if(index!=i)
    	  {
    		hold2=words[i];
    		words[i]=words[index];
    		words[index]=hold2;
    	  }

      }


}

void swap(char **str1, char **str2){
 
	/*this is a helper function that you can implement and use to facilitate your development*/
}

void sort2_words(char **words, int size){
	/*
	  For this question, I placed a infinite do-while loop outside, and defined a valve value:'escape' to use in conjunction with it.
	  The logic: go through the 'words' list again and again until there is nothing to swap.
	  If the escape value remains 0 after one entire loop execution, then it will be sure that the words list are now in increasing order.
	  If this is the case->Terminate the do-while loop.
	  otherwise, keep executing the loop.
	 */

     int i;
     char* temp;
     int escape=0; //determine whether to terminate or not. If it remains 0 then terminate. If equals to 1, keep executing.
	/*write your implementation here*/
do
 {
	for(i=0; i<(size-1); i++)
	  {

		if(compare_str(words[i], words[i+1])==1)
		  {
			temp=words[i];
			words[i]=words[i+1];
			words[i+1]=temp;
			escape=1;
		  }
		if(compare_str(words[i], words[i+1])==0)
		  {
		 	continue;
		  }
	  }
	if(escape==0)
	  {
		break;
	  }
	if(escape==1)
	  {
		escape=0;
		continue;
	  }
 }while(1>0);
}

