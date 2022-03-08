
public class SLLSet {
    private int size;
    private SLLNode head;

    public SLLSet() {
    	size=0;
    	head= null;
        
    }

    public SLLSet(int[] sortedArray) {
    	
    	size=sortedArray.length;
    	head= new SLLNode(sortedArray[0],null);
    	SLLNode index=head;
    	
    	for(int i=1; i<sortedArray.length; i++)
    	  {
    		index.next= new SLLNode(sortedArray[i],null);
    		index=index.next;
    	  }
    	
    	       
    }

    public int getSize() {
		
        return this.size;
    }

    public SLLSet copy() {
    	
    	
    	SLLNode index=head;
    	int arr[]= new int[size]; //create a array for the copy
    	int i=0;
    	
    	//the loop duplicate the values of indexes into the array
    	while(index!=null)
    	  {
    		arr[i]=index.value;
    		index=index.next;
    		i++;
    	  }
    	//use the array to create a SLLSet
    	SLLSet copy= new SLLSet(arr);

        return copy;
    }

    public boolean isIn(int v) {
    	
    	SLLNode index=head;  
    	/* 
        loop through all the indexes to see if there is value equal to v
    	*/
    	for(int i=0; i<size; i++)
  	      {
  		    if(index.value==v)
  		      {
  		     	return true;
  		      }
  		    index=index.next;
  	      }
        
        return false;
    }

    public void add(int v) {
    	
    	
    	SLLNode index=head;
    	/*
    	The whole while loop is to deal with the SLLSet that is not null
    	 */
    	while(index!=null)
    	 {
    		//if there is value equals to v, then break directly without any actions
    		if(index.value==v)
    		 {
    			break;
    		 }
    		
    		//when v is smaller than the current index value,
    		//and need to be added before the current index value
    		if(index.value>v)
    		 {
    			SLLNode newnode= new SLLNode(v,head);
    			head=newnode;
    			size=size+1;
    			break;
    		 }
    		
    		//when v need to be added among two adjacent indexes
    		if((index.next!=null)&&(index.value<v)&&(index.next.value>v))
   		     {
    			SLLNode newnode= new SLLNode(v,null);
    			newnode.next=index.next;
    			index.next=newnode;
    			size=size+1;
    			break;
   		     }
    		
    		//when v need to be added at the very end of the link
    		if(index.next==null)
    		 {
    			SLLNode newnode= new SLLNode(v,null);
    			newnode.next=index.next;
    			index.next=newnode;
    			size=size+1;
    			break;
    		 }
    		index=index.next;		    		
    	 }
    	
    	//If we need to add element in a null set
    	if(this.size==0)
    	  {
    		SLLNode newnode= new SLLNode(v,null);
    		head=newnode;
    		size=size+1;
    	  }
    	
     
    }

    public void remove(int v) {
    	  
    	/*
    	 The variable 'check' is the valve value to enter a special case
    	 -- when we need to delete the first element of the link.
    	 The codes for this specific case only will be execute once
    	 --the first execution of the loop.
    	 The check is initialized with 0,
    	 after the first execution, check would be assign the value 1.
    	 */
    	  int check=0;
    	  SLLNode index=head;
    	  while(index!=null)
    	    {
    		  //deal with the case that we need to delete the very first element.
    		  if(check==0)
    		   {
    			  if(index.value==v)
    			   {
    			     head=index.next;
    			     size=size-1;
    			     check=1;
    			     break;
    			   }
    			  if(index.value!=v)
    			   {
    				 check=1;
    			   }   				  
    		   }
    		  
    		  //deal with the case that the value we want to delete is not the first index value.
    		  if((index.next!=null)&&(index.next.value==v))
    		   {
    			  index.next=index.next.next;
    			  size=size-1;
    			  break;
    		   }
    		  index=index.next;
    	    }
    	         
    }

    public SLLSet union(SLLSet s) {
    	
     SLLNode index=head;
     
     //if this SLLSet is empty
     if(this.size==0)
      {
    	 return s;
      }
     
     //if SLLSet s is empty
     if(s.size==0)
      {
    	
        while(index!=null)
          {
        	s.add(index.value);
        	index=index.next;
          }
     	return s;    	
      }
     
     //if both 'this SLLSet' and 'SLLSet s' are not empty
     if((this.size!=0)&&(s.size!=0))
      {
     	
    	while(index!=null)
    	  {  		
   			s.add(index.value);
    		index=index.next;
    	  }
    	return s;
    	
      }
     
         
      return s;
    }

    public SLLSet intersection(SLLSet s) {
    	
    	SLLNode index= this.head;
    	
    	//if one of 'this SLLSet' or 'SLLSet s' is empty,
    	//just return a empty SLLSet
    	if((this.size==0)||(s.size==0))
    	 {
    		SLLSet output= new SLLSet();
    		return output;
    	 }
    	
    	//if both 'this SLLSet' and 'SLLSet s' are not empty
    	if((this.size!=0)&&(s.size!=0))
    	 {
    		//create a empty SLLSet as output
    		SLLSet output= new SLLSet();
    		//if two input SLLSet have same value, add this value into output
    		while(index!=null)
    		  {
    			if(s.isIn(index.value)==true)
    			 {
    				output.add(index.value);
    			 }
    			index=index.next;
    		  }
    		return output;
    	 }
    	 
    	
        

        return s;
    }

    public SLLSet difference(SLLSet s) {
    	
    	SLLNode index=this.head; //head for this SLLSet
    	SLLNode sindex=s.head;   //head for SLLSet s
    	
    	//if this SLLSet is empty
    	if(this.size==0)
    	 {
    		SLLSet output= new SLLSet();
    		return output;
    	 }
    	
    	//if SLLSet s is empty
    	if(s.size==0)
    	 {
    		int arr[]= new int[this.size]; //create a new array for the output
    		//add values of this SLLSet into the array
        	for(int i=0; i<this.size; i++)
        	  {
        		arr[i]=index.value;
        		index=index.next;
        	  }
        	//create a output SLLSet
        	SLLSet output= new SLLSet(arr);
        	return output;
        	
    	 }
    	
    	//if both of input SLLSet are not empty
    	if((this.size!=0)&&(s.size!=0))
    	 {
    		//create a array for the duplication of this SLLSet values
    		int arr[]= new int[this.size];
    		
    		//duplicate this SLLSet
        	for(int i=0; i<this.size; i++)
        	  {
        		arr[i]=index.value;
        		index=index.next;
        	  }
        	SLLSet output= new SLLSet(arr);
        	
        	//remove the repeated values in the duplicated SLLSet
    		while(sindex!=null)
    		  {
    			output.remove(sindex.value);
    			sindex=sindex.next;
    		  }
    		
    		return output;
    	 }
        

        return s;
    }

    public static SLLSet union(SLLSet[] sArray) {
        SLLSet ss = new SLLSet();
        
        int capacity=sArray.length;
        for(int i=0; i<capacity-1; i++)
          {
        	ss=sArray[i].union(sArray[i+1]);        	
          }

        

        return ss;
    }

    @Override
    public String toString() {
    	
    	String output= new String();
    	SLLNode index;
    	index=head;
    	if(size!=0)
    	 {    	 
    	   for(int i=0; i<size-1; i++)
    	     {
    		   output=output+index.value+", ";
    		   index=index.next;
    	     }
    	   
    	   //pick out the last value and add it to the string manually,
    	   //because we do not want the comma and space after if
    	   output=output+index.value;
    	 }
    			
        return output;
    }
}
