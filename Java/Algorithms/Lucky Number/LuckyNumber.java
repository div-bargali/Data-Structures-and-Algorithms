// Java program to check Lucky Number 
import java.io.*; 
  
class GFG  
{ 
    public static int counter = 2;     
  
    // Returns 1 if n is a lucky no. ohterwise returns 0 
    static boolean isLucky(int n) 
    { 
        // variable next_position is just for readability of 
        // the program we can remove it and use n only  
        int next_position = n; 
        if(counter > n) 
            return true; 
        if(n%counter == 0) 
            return false;       
   
        // calculate next position of input no 
        next_position -= next_position/counter; 
     
        counter++; 
        return isLucky(next_position); 
    } 
      
    // driver program 
    public static void main (String[] args)  
    { 
        int x = 5; 
        if( isLucky(x) ) 
            System.out.println(x+" is a lucky no."); 
        else
            System.out.println(x+" is not a lucky no."); 
    } 
} 
