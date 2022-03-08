#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"

void add_vectors(double vector1[],double vector2[],double vector3[],int size);
double scalar_prod(double vector1[],double vector2[],int size);
double norm2(double vector1[], int size);


void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	double* v1;
	double* v2;
	double* v3;
	int i;

	v1=vector1;
	v2=vector2;
	v3=vector3;
	
	for(i=0; i<size; i++)
	   {
		v3[i]=v1[i]+v2[i];
	   }
	

}
double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;
    int i;
    double temp_sum;
	//write your code below to calculate the prod value
	for(i=0; i<size; i++)
	  {
		temp_sum=vector1[i]*vector2[i];
		prod=prod+temp_sum;
      }
    
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	double holder;
    
	//write your code here
	// you should call function scalar_prod().
	holder=scalar_prod(vector1,vector1,size);
	L2=sqrt(holder);
	
	//finally, return the L2 norm 
    return L2;
}
/*
int main(void)
{
	   // Add vector check
	   double a[]={2,4,6};
	   double b[]={0,1,2};
	   double c[3];
	   int size1=3;
	   add_vectors(a, b, c, size1);

	   // scalar product check
	   double d[]={2,4,6};
	   double e[]={0,1,2};
	   int size2=3;
	   double product;

	   product=scalar_prod(d, e, size2);

	   // norm check
	   double f[]={2,2,2};
	   int size3=3;
	   double norm;

	   norm=norm2(f, size3);

}

*/




