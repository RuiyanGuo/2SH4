/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author jianfeng
 */
public class Matrix {
	
	//comment
    
	private int[][]  matrixData;
	private int    rowsNum;	
	private int    colsNum;	
	
	public Matrix( int row, int col ) 
	{   
		/*
		* constructs a row-by-col matrix with
		* all elements equal to 0; if row <= 0, the number of rows of the matrix is set to
		* 3; likewise, if col <= 0 the number of columns of the matrix is set to 3.		
		*/
		
		if(row>0)
		  {
			this.rowsNum=row;
		  }
		if(row<=0)
		  {
			this.rowsNum=3;
		  }
		if(col>0)
		  {
			this.colsNum=col;
		  }
		if(col<=0)
		  {
			this.colsNum=3;
		  }
		int arr[][]= new int[this.rowsNum][this.colsNum];
		this.matrixData=arr;
	}

	public Matrix( int[][] table) 
	{	

		/*
		* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
		* element in each position as array table.
		*/
		this.rowsNum=table.length;
		this.colsNum=table[0].length;
		int arr[][]= new int[this.rowsNum][this.colsNum];
		this.matrixData=arr;
		for(int i=0; i<(table.length); i++)
		  {
		    for(int j=0; j<(table[0].length); j++)
		      {
		    	this.matrixData[i][j]=table[i][j];
		      }
		  }
	}
	
	public int getElement(int i, int j) throws IndexOutOfBoundsException
	{ 	
		/*
		* returns the element on row i and column j of this matrix; 
		* it throws an exception (IndexOutOfBoundsException) if any of indexes i and j is not in the required range 
		* (rows and columns indexing starts with 0)
		*  the detail message of the exception should read: "Invalid indexes".
		*/
		if((i>=this.rowsNum)||(j>=this.colsNum))
		  {
			throw new IndexOutOfBoundsException ("Invalid indexes.");
		  }
		else
		  {
			return this.matrixData[i][j];
		  }

	}
        
    public boolean setElement(int x, int i, int j){ 
            
        /* the detail message of the exception should read: "Invalid indexes" */
    	if((i>=this.rowsNum)||(j>=this.colsNum))
    	  {
    		return false;
    	  }
    	else
    	  {
    		this.matrixData[i][j]=x;
    		return true;
       	  }
    	
    } 

    public Matrix copy(){ 
        
    	/* fix the code and write your implementation below */
	     Matrix copy= new Matrix (this.matrixData);	
		
        return  copy; 
    }    
                
	public void addTo( Matrix m ) throws ArithmeticException
	{
		
		/* the detail message of the exception should read: "Invalid operation". */
		if((matrixData.length!=m.rowsNum)||(matrixData[0].length!=m.colsNum))
		  {
			throw new ArithmeticException ("Invalid operation");
		  }
		else
		  {
			for(int i=0; i<m.rowsNum; i++)
			{
			   for(int j=0; j<m.colsNum; j++)
			     {
				   matrixData[i][j]=matrixData[i][j]+m.matrixData[i][j];
			     }
			}
			
		  }
	
	}
	
    public Matrix subMatrix(int i, int j) throws ArithmeticException{ 
        
		/* The exception detail message should read: "Submatrix not defined"*/
    	
    	/* fix the code and write your implementation below */
		Matrix subM = new Matrix (i+1,j+1);
		if((matrixData.length<i)||(matrixData[0].length<j))
		  {
			throw new ArithmeticException ("Submatrix not defined");
		  }
		else
		  { 
			for(int m=0; m<=i; m++)
		  	  {
				 for(int n=0; n<=j; n++)
				   {
					 subM.matrixData[m][n]=matrixData[m][n];
				   }
			  }
		  }
		
		
		
		
        return  subM; 
        
    }
        
    public int getsizeofrows(){ 
           
		/* update below return */
		return rowsNum;
    }
        
    public int getsizeofcols(){
		
		/* update below return */
        return colsNum; 
    }
        
    public boolean isUpperTr(){
            
		/* write your implementation here and update return accordingly */
    	int row;
    	row=matrixData.length;
    	row=row-1; //exclude the first row
    	for(int i=1; i<=row; i++)
    	  {
    		for(int j=0; j<i; j++)
    		  {
    			if(matrixData[i][j]!=0)
    			  {
    				return false;
    			  }
    		  }
    	  }
    	
        return true;  
	}
        
    public static Matrix sum(Matrix[] matArray) throws ArithmeticException{
            
    	
        for(int i=0; i<(matArray.length-1); i++)
          {
        	if((matArray[i].rowsNum!=matArray[i+1].rowsNum)||(matArray[i].colsNum!=matArray[i+1].colsNum))
        	  {
        		throw new ArithmeticException ("Invalid operation");
        	  }
        
          }
        Matrix superMatrix = new Matrix (matArray[0].rowsNum,matArray[0].colsNum);
        for(int j=0; j<matArray.length; j++)
          {
        	superMatrix.addTo(matArray[j]);
          }
            
        return superMatrix; 
    }
        
	public String toString(  )
	{
		String output = new String(); 
	
		   for (int i = 0; i<this.rowsNum; i++)
		     {
		        for(int j = 0; j<this.colsNum; j++)
		           {
		        	output=output+this.matrixData[i][j]+" ";
		           }     
		        output=output+"\n";
		     }
		return output;
	}
    
}