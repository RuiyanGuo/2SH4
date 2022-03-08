#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;
    int n;
    int i;
	/*write your implementation here*/
	FILE *input_file=fopen(filename, "r");
	fscanf(input_file,"%d", &n );
	*sizePtr=n;
	class_list=(student**)calloc(n,sizeof(student*));
	for(i=0; i<n; i++)
	   {
		class_list[i]=(student*)calloc(6,sizeof(student));
		fscanf(input_file,"%d", &class_list[i]->student_id);
		fscanf(input_file,"%s", class_list[i]->first_name);
		fscanf(input_file,"%s", class_list[i]->last_name);
	   }
    fclose(input_file);


	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	int i;
	int index;
	/*write your implementation here and update the return accordingly*/
	for(i=0; i<size; i++)
	   {
		 if((list[i]->student_id)==idNo)
		   {
			 index=i;
			 return index;
		   }

	   }
	 return -1;
}

void input_grades(char *filename, student **list, int size)
{
	int i;
    int idcheck;
    int proj1;
    int proj2;
    int index;
	/*write your implementation here*/
    FILE *input_file=fopen(filename, "r");
    for(i=0; i<size; i++)
       {
    	  fscanf(input_file,"%d", &idcheck);
    	  fscanf(input_file,"%d", &proj1);
    	  fscanf(input_file,"%d", &proj2);
    	  index=find(idcheck, list, size);
    	  if(index!=-1)
    	    {
    		  (list[index]->project1_grade)=proj1;
    		  (list[index]->project2_grade)=proj2;
    	    }
       }
    fclose(input_file);

}

void compute_final_course_grades(student **list, int size)
{
	int i;
	/*write your implementation here*/
	for(i=0; i<size; i++)
	   {
		(list[i]->final_grade)=((list[i]->project1_grade)+(list[i]->project2_grade))/2.0;
	   }
}

void output_final_course_grades(char *filename, student **list, int size)
{
	int i;
	/*write your implementation here*/
	FILE *output_file=fopen(filename, "w");
	fprintf(output_file,"%d\n", size );
	for(i=0; i<size; i++)
	   {
		fprintf(output_file,"%d %f\n", list[i]->student_id, list[i]->final_grade);
	   }
	fclose(output_file);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	int index;
	int i;
	/*write your implementation here*/
	index=find(idNo, list, *sizePtr);
	if(index==-1)
	  {
		printf("No such person");
	  }
	if(index!=-1)
	  {
	     for(i=index; i<(*sizePtr-1); i++)
	        {
		      list[i]=list[i+1];
	        }
	     free(list[*sizePtr-1]);
	   }
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	free(list);
	*sizePtr=0;
}
