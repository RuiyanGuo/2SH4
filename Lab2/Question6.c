#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void efficient(const int source[], int val[], int pos[], int size);
void reconstruct(int source[], int m, const int val[], const int pos[], int n);


void efficient(const int source[], int val[], int pos[], int size)
{
    int i;
    int j=0;

    for(i=0; i<size; i++)
       {
    	  if(source[i]==0)
    	    {
    		  continue;
    	    }
    	  if(source[i]!=0)
    	    {
    		  val[j]=source[i];
    		  pos[j]=i;
    		  j++;
    	    }
       }
	

}

void reconstruct(int source[], int m, const int val[], const int pos[], int n)
{
	int i;
	int j=0;
	int position;  //Holds the values in pos[]
	int value;     //Holds the values in val[]
//Fill all the position in source[] with 0
	for(i=0; i<m; i++)
	   {
		 source[i]=0;
	   }
 //***************
//Change the required position to the values in val[]
	while(j<n)
	   {
		  position=pos[j];
		  value=val[j];
		  source[position]=value;
		  j++;
	   }
//*****************

}
