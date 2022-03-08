#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr [N3*N3]);

void diag_scan(int mat [][N3], int arr [])
{
//For block1
   int i;
   int j=0;
   int holdi, holdj;
   int k=1;
//For block2
   int diag=N3-1;
   int x=0;
//For block3
   int a;
   int b=1;
   int holda;
   int holdb;

//Block1:
   //Place the very top left value of the matrix manually into the first element of arr[].
   arr[0]=mat[0][0];
   /*
   Then deal with the numbers row by row until the diagonal.
   (The row that parallel with the diagonal.Note: the diagonal I use is the one start from top right corner of the matrix)
    */
   for(i=1; i<(N3-1); i++)
      { holdi=i;
	        holdj=j;
	    	 while(holdi>=0)
	    	    {
	    		  arr[k]=mat[holdi][holdj];
	    		  holdi--;
	    		  holdj++;
	    		  k++;
	    	    }
	         j=0;
      }

//Block2:
   //Deal with the numbers in the diagonal(Note: the diagonal I use is the one start from top right corner of the matrix)
   while(diag>=0)
      {
	    arr[k]=mat[diag][x];
	    diag--;
	    x++;
	    k++;
      }

//Block3:
   //Deal with numbers on the right hand side of the diagonal(Note: the diagonal I use is the one start from top right corner of the matrix)
   for(a=(N3-1); a>b; a--)
      { a=N3-1;
	    holda=a;
	    holdb=b;
	    while(holdb<=a)
	       {
	    	 arr[k]=mat[holda][holdb];
	    	 holda--;
			 holdb++;
			 k++;
	       }
	    b++;
      }
   //Place the very bottom right value of the matrix manually into the last element of arr[].
   arr[k]=mat[N3-1][N3-1];

	
}
