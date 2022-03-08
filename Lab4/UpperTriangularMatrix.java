/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author jianfeng
 */
public class UpperTriangularMatrix {
    private int n;
    private int[] array;
    
    public UpperTriangularMatrix(int n){
        
    	if(n<=0)
    	  {
    		this.n=1;
    	  }
    	else
    	  {
    		this.n=n;
    	  }
    	int arr[]= new int[n*(n+1)/2];
        this.array=arr;
    }
    
    public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException{
        
    	 int size=upTriM.getsizeofrows();
    	 this.n= size;
    	 
    	 int arrsize;
    	 arrsize=size*(size+1)/2;
		 int arr[]= new int[arrsize];
         if(upTriM.isUpperTr()==false)
           {
        	 throw new IllegalArgumentException ("Not an upper triangular Matrix");
           }
         else
           {
             int e=0;
             int count=0;
             for (int i = 0; i<upTriM.getsizeofrows(); i++)
      	     {
      	        	 
      	        	 do
      		          {
      	                arr[e]=upTriM.getElement(i, count);
      		            e++;
      		            count++;
      		            if(count>=this.n)
      		              {
      		        	    break;
      		              }
      		          }while(1>0);    
      		         count=i+1;     
      	        
      	     }        	 
           }
         this.array=arr;
    	
    	
    }    
        
    public int getDim(){
        
		
		/* write your implementation here and update return accordingly */
        return this.n; 
    }
    
    public int getElement(int i, int j) throws IndexOutOfBoundsException{
		
		
 		/* write your implementation here and update return accordingly */
    	
    	int position;    //the corresponding position in the array
    	int numofzero=0; //number of 0 need to be deleted when determine the position in the array
    	
    	if((this.n<=i)||(this.n<=j))
    	  {
    		throw new IndexOutOfBoundsException ("Invalid indexes");
    	  }
    	else
    	  {

    		if(i<=j)
    		  {
    			//this piece of code convert the position in matrix to position in the array
    			if(i!=0)
    			  {
    				for(int hold=i; hold>0; hold--)
			          {
				         numofzero=numofzero+hold;
			          }
        		    position=(i*this.n)+(j+1)-numofzero-1; 
        		    numofzero=0;
    			  }
    			else
    			  {
    				position=j;
    			  }
    			//*********************************
        		return this.array[position];
    		  }
    		else
    		  {
    			return 0;
    		  }
    		
    	  }
    	
 
    }
    
    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException,IllegalArgumentException{
       
    	int position;  //the corresponding position in the array
    	int numofzero=0;  //number of 0 need to be deleted when determine the position in the array
    	
    	if((this.n<=i)||(this.n<=j))
  	      {
  		    throw new IndexOutOfBoundsException ("Invalid indexes");
  	      }
    	else
    	  {
    		if(i<=j)
    		  {
    			//this piece of code convert the position in matrix to position in the array
    			if(i!=0)
    			  {
    				for(int hold=i; hold>0; hold--)
  			          {
  				         numofzero=numofzero+hold;
  			          }
        		    position=(i*this.n)+(j+1)-numofzero-1; 
        		    numofzero=0;
    			  }
    			else
    			  {
    				position=j;
    			  }
    			//*********************************
        		this.array[position]=x;
    		  }
    		if((i>j)&&(i!=0))
    		  {
    			throw new IllegalArgumentException ("Incorrect argument");
    		  }
    		
    	  }
    	
    	
    	
    }
    
    public Matrix fullMatrix(){

 //       Matrix full= new Matrix(this.n,this.n);
        
        int arr[][]= new int[this.n][this.n];
        int position;  //the corresponding position in the array
        int numofzero=0;  //number of 0 need to be deleted when determine the position in the array
        for(int i=0; i<this.n; i++)
          {
        	for(int j=0; j<this.n; j++)
        	  {
        		if(i<=j)
        		  {
        			//this piece of code convert the position in matrix to position in the array
        			if(i!=0)
      			     {
        			    for(int hold=i; i>0; hold--)
        			      {
        				    numofzero=numofzero+hold;
        			      }
          		        position=(i*this.n)+(j+1)-numofzero-1; 
          		        numofzero=0;
      			      }
      			    else
      			      {
      				    position=j;
      			      }
        			//*********************************
        		    arr[i][j]=this.array[position];
        		  }
        		else
        		  {
        			arr[i][j]=0;
        		  }
        	  }
          }
        
        Matrix full= new Matrix(arr);
        
		
        return full; 
    }
    
   
      
    public String toString(){
         
       String output = new String();
       int e=0;
       int count=0;
       for (int i = 0; i<this.n; i++)
	     {
	        	 if(i>0)
	        	   {
	        		 for(int k=0; k<i; k++)
	        		   {
	        			 output=output+0+" ";
	        		   }
	        	   }
	        	 do
		          {
		            output=output+this.array[e]+" ";
		            e++;
		            count++;
		            if(count>=this.n)
		              {
		        	    break;
		              }
		          }while(1>0);    
		         output=output+"\n";
		         count=i+1;     
	        
	     }
	   return output;
            
    }
    
    public int getDet(){
        
    	int product=1;    	
    	int position;  //the corresponding position in the array
    	int numofzero=0; //number of 0 need to be deleted when determine the position in the array
        for(int i=0; i<this.n; i++)
         {
        	//this piece of code convert the position in matrix to position in the array
        	if(i!=0)
        	  {
        		for(int hold=i; hold>0; hold--)
			      {
				    numofzero=numofzero+hold;
			      }
        	    position=(i*this.n)+(i+1)-numofzero-1;
        	    numofzero=0;
        	  }
        	else
        	  {
        		position=i;
        	  }
        	//*********************************
        	product=product*this.array[position];
          }
    	
    	
       return product; 
    }

    
    public double[] effSolve(double[] b) throws IllegalArgumentException{

        /* fix the following and write your implementation */
    	double[] sol = new double[this.n];
    	int arrayPos=(this.n)*((this.n)+1)/2;
    	int solPos=this.n;
    	double sum=0;
    	if(getDet()==0)
    	  {
    		throw new IllegalArgumentException ("The determinant of the matrix is 0");
    	  }
    	if(b.length!=this.n)
    	  {
    		throw new IllegalArgumentException ("The dimension of the matrix is not defined for operation");
    	  }
    	for(int i=(this.n-1); i>=0; i--)
    	  {
    		sum=0;
    		solPos=this.n;
    		for(int j=(this.n-1); j>=0; j--)
    		  {
    			if(j>=i)
    			  {
    				arrayPos--;
    				solPos--;
    			    sum=sum+this.array[arrayPos]*sol[solPos];
    			  }
    		  }
    		sol[solPos]=(b[solPos]-sum)/(this.array[arrayPos]);
    	  }

  
   
       
        return sol;  
    }   
}