
#include "Questions.h"



int Q1_for(){
	int sum=0;
	int i;
	// calculate your sum below..this has to use for loop
	for (i=30; i<=1000; i++)
	{
		if ((i%4)==0)
		   {
			sum=sum+i;
		   }
		else
		{
			continue;
		}
	}
	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_while(){
	int sum=0;
    int j=30;
	// calculate your sum below..this has to use while loop

    while (j<=1000)
       {
       	if ((j%4)==0)
       	   {
       		 sum=sum+j;
       		 j=j+1;
       	   }
       	else
       		{
       		  j=j+1;
       		}
       }

	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_do(){
	int sum=0;
	int k=30;
	// calculate your sum below..this has to use do-while loop
	do
	  {
		if ((k%4)==0)
		   {
			  sum=sum+k;
			  k=k+1;
		   }
		else
		   {
			  k=k+1;
		   }
	  }while (k<=1000);
	
	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit;
	
	// Do your coding below to check
//This if..else turn the negative input into positive number
	if(Q2_input<0)
	  {
		Q2_input=Q2_input*(-1);
	  }
	else{Q2_input=Q2_input*1;}
//The code below test if the input are 5 digits
	if((Q2_input>99999)||(Q2_input<10000))
	  {
		IsFiveDigit=0;
	  }
	else
	  {
		IsFiveDigit=1;
	  }
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and prints:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program should print a message to signal an invalid input.
*/	
	// this is the varaible that holds the out value to return
	float GPA;

	// Do your coding below to calculate the GPA variable value
	
	if((Q3_input>=90)&&(Q3_input<=100))
	  {
		GPA=4;
	  }
	if((Q3_input>=80)&&(Q3_input<=89))
	  {
		GPA=3;
      }
	if((Q3_input>=70)&&(Q3_input<=79))
	  {
	    GPA=2;
	  }
	if((Q3_input>=60)&&(Q3_input<=69))
	  {
		GPA=1;
	  }
	if((Q3_input>=0)&&(Q3_input<=59))
	  {
	    GPA=0;
	  }
	if((Q3_input<0)||(Q3_input>100))
	  {
		GPA=-1;
	  }
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return
	double pi=0;
	int x=0;
	int check=0;
	// Do your coding below to calculate the pi value
//This block of code corresponds the input to the last specific term in the series that we want to calculate.
//And, the code also determine whether the last term is positive or negative.
//The 'x' in the code carries the value of the denominator as well as the sign of the last term.
	x=Q4_input+(Q4_input-1);
	if((Q4_input%2)==0)
	  {
		x=x*(-1);
	  }
	else
	  {
		x=x*1;
	  }
//Codes' main body start here...
/*
 The main body are divided into three different scenarios,
 1.The last term is minus/ 2.There is only one term in the series/ 3.The last term is positive
 In each scenario. When I calculate the value of pi, I separate the series into many parts.
 Each part contains two terms: one positive, one negative.
 So, there are two terms in the formula that I calculate the value of pi.
 Conclusively, the principle of the code is to calculate the series from the end of it, and each time they
 only accumulate two terms until it reaches the very first two terms of the series.
 */
//1. when x is minus
	if(x<0)
	{
		do
		{
		   pi=pi+(4.0/x)+(4.0/(x*(-1)-2));
		   x=x+4;
		   if(x==1)
		     {
			  x=0;
			  break;
		     }
		   else
		     {
			  continue;
		     }

		}while(check==0);
	}
//2. when x is positive and x is equal to 1
	if(x==1)
	{
		pi=pi+4.0;
	}
//3. when x is positive and x is not equal to 1
	if(x>1)
	{
	  do
	    {
		  pi=pi+(4.0/x)+(4.0/((x-2)*(-1)));
		  x=x-4;
		  if(x==1)
		    {
			  pi=pi+4.0;
			  x=0;
			  break;
		    }
		  else
		     {
			   continue;
		     }
	     }while(check==0);
	}
	
	
	
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	int x; //The shorter side
	int y; //The longer side
	int z; //The hypotenuse
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		print each triple on a separate line, 
		and update the total number of triples if needed
	*/
	
    for(x=1; x<=400; x++)
       {
    	for(y=1; y<=400; y++)
    	   {
    		 if(x>y)
    		   {
    			 continue;
    		   }
    		 for(z=1; z<=400; z++)
    		    {
    			 if(((x*x)+(y*y))>160000)
    			   {
    				 break;
    			   }
    			 if((x*x)+(y*y)==(z*z))
    			   {
    				 totNumTribles=totNumTribles+1;
    			   }
    		    }

    	   }

       }



	//this is the format that you MUST print the found tribles..uncomment this line and fill in the missings to get it working correctly
	//printf("A trible found: side1=%d, side2=%d, side3=%d\n", ...)
	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is teh variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;
        int x;
        int y;
        int sum=0;
        int z=0;
		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    for(x=1; x<=Q6_input; x++)    //This for loop is used to hold the numbers that need to be checked.
	       {
	    	 for(y=1; y<x; y++)       //This for loop is used to check the factors
	    	    {
	    		  if((x%y)==0)
	    		    {
	    			  sum=sum+y;
	    		    }
	    	    }
	    	 if(sum==x)               //This if..else is used to check if the sum of the factors equal to the number itself.
	    	   {
	    		 sum=0;
	    		 perfect[z]=x;
	    		 counts=counts+1;
	    		 z=z+1;
	    	   }
	    	 else
	    	    {
	    		 sum=0;
	    	    }
	       }
		
		
		
		

	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	int a,b,c=1,check=0;
	int bakup,x,sum=0,ensure;
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
//This block of code determines the total digits of the given input
	bakup=Q7_input;
	do
	 {
	   x=bakup/10;
	   bakup=bakup/10;
	   sum=sum+1;
	 }while(x!=0);
	ensure=sum*1;
//Main body of the code starts here...
	do
	 {
	   a=Q7_input%10;
	   for(b=1; b<sum; b++)
	      {
		    c=c*10;
	      }
	   sum=sum-1;
	   check=check+1;
	   reversedInt=reversedInt+a*c;
	   Q7_input=Q7_input/10;
       c=1;

	 }while(check<ensure);


	
	
		return reversedInt;
	
}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	int a,b,c=1,check=0;
	int bakup,x,sum=0,ensure;
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits

	/*
	 I use the same code in The part b of Q7 as the part a.
	 */

//Determine the total digits of the given input
		bakup=Q7b_input;
		do
		 {
		   x=bakup/10;
		   bakup=bakup/10;
		   sum=sum+1;
		 }while(x!=0);
		ensure=sum*1;
//.......
		do
		 {
		   a=Q7b_input%10;
		   for(b=1; b<sum; b++)
		      {
			    c=c*10;
		      }
		   sum=sum-1;
		   check=check+1;
		   reversedInt=reversedInt+a*c;
		   Q7b_input=Q7b_input/10;
	       c=1;

		 }while(check<ensure);


	
	
	return reversedInt;

	
	
	
}
