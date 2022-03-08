#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2);

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2)
{
//For block1
    int i;
    int j;

//For block2
    int k=0;
    int count=0;
    int temppos;
    int tempval;
    count=k1+k2;

//For block3
    int e=0;

//For block4
    int h;
    int total=0;

//For block5
    int f=0;
    int g;
    int valve=0;
//********************************************

//Block1: Insert values in pos1,val1 and pos2,val2 into pos3,val3, consecutively and respectively
    for(i=0; i<k1; i++)
       {
    	 pos3[i]=pos1[i];
    	 val3[i]=val1[i];
       }
    i=0;
    for(j=k1; j<count; j++)
           {
        	 pos3[j]=pos2[i];
        	 val3[j]=val2[i];
        	 i++;
           }

//Block2: Order the pos3,val3 in increasing order
    do
      {
    	if(pos3[k]<=pos3[k+1])
    	  {
    		k=k+1;
    		continue;
    	  }
    	if(pos3[k]>pos3[k+1])
    	  {
    		temppos=pos3[k];
    		tempval=val3[k];

    		pos3[k]=pos3[k+1];
    		val3[k]=val3[k+1];

    		pos3[k+1]=temppos;
    		val3[k+1]=tempval;

    		k=k+1;
    	  }

      }while(k<(count-1));

//Block3: Identify if there are numbers in pos3 equal with each other. Then mark one of them with '0'.
    do
      {
       	if(pos3[e]<pos3[e+1])
       	  {
       		e++;
       		continue;
       	  }
       	if(pos3[e]==pos3[e+1])
       	  {
       		val3[e]=val3[e]+val3[e+1];
       		val3[e+1]=0;

       		pos3[e+1]=0;

       		e++;
       	  }

       }while(e<(count-1));

//Block4: Count how many 0 are there in the pos3 in total. This value will be used in Block5
    for(h=0; h<count; h++)
       {
    	 if(pos3[h]==0)
    	   {
    		 total++;
    	   }
       }

//Block5: Make sure all the '0' value are placed in the end of the pos3,val3.
//In this do-while loop. A valve value is integrated to determine whether to 'break' or not. As a result a '0<1' is placed in to the bracket of 'while'.
//The valve value is set in case of there are more than one '0' in the array.
//When there are more than one '0', the valve value could make the loop execute until all the '0' are placed in the end of the array.
    do
    {
    	if(pos3[f]!=0)
    	  {
    		f++;
    		continue;
    	  }
    	if(pos3[f]==0)
    	  {
    		for(g=f; g<(count-1); g++)
    		   {
    			temppos=pos3[g];
    			tempval=val3[g];

    			pos3[g]=pos3[g+1];
    			val3[g]=val3[g+1];

    		    pos3[g+1]=temppos;
    			val3[g+1]=tempval;
    		   }
   	         valve++;
   	         f=0;
    	  }
    	if(valve<total)
    	  {
    		continue;
    	  }
    	if(valve>=total)
    	  {
    		break;
    	  }


    }while(0<1);
}
