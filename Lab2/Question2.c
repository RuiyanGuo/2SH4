#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]);

int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	 double fabs(double x);
	 int i,j;
	 int k=0;
	 int sum=0;
	 int diag_val;
	 int count=0;  //this variable is to check if there are other numbers in the same row that equal to the diagonal value
	 int escape=0; //this variable is to make sure that if any row does not meet the requirement, then exit the whole checking mechanism with isDiag==0.
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise

	 for(i=0; i<N2; i++)
	   {
		 if(escape==1)
		   {
			 isDiag=0;
			 break;
		   }

		 diag_val=mat[i][k++]; //Pick out the diagonal value

		 for(j=0; j<N2; j++)
		   {
			 // This piece of code is to check if there are other numbers in the same row that equal to the diagonal value
			 if(mat[i][j]==diag_val)
			   {
				 count=count+1;
			   }
			 //*************

			 //This piece of code is to deal with the 'sum' if other value also equal to the diagonal value
			 if((mat[i][j]==diag_val)&&(count==1))
			   {
				 sum=sum+0;
			   }
			 if((mat[i][j]==diag_val)&&(count!=1))
			   {
			 	 sum=sum+fabs(mat[i][j]);
			   }
			 //*************

			 if(mat[i][j]!=diag_val)
			   {
				 sum=sum+fabs(mat[i][j]);
			   }
		   }
		 if(fabs(diag_val)>sum)
		   {
			 isDiag=1;
			 escape=0;
		   }
		 if(fabs(diag_val)<=sum)
		   {
			 isDiag=0;
			 escape=1;
		   }
         count=0;
		 sum=0;

	   }
	


    return isDiag;
}
