
/* Algorithm to multiply two numbers
   Based on divide and conquer
   Time complexity - O(n^log₂3)
   n is no of digits
   assumes no of digits to be even if not automatically pads with zero and makes n of both numbers equal by padding zeroes */



public class Karatsuba
{
    public static int count(int num)                           					//count digits in a number
    {
       int cnt =0; 
       while(num != 0)
       {
           num /= 10;
           ++cnt;
       }
       return cnt;
     }
	
    public static int ceil(int num)      							//to return ceil of a number
    {
        return (num%2==1)?(num/2)+1:num/2;
    }
	
    public static int pow10(int num)      							//this function takes number and return 10^number
    {
        if(num==0)
            return 1;
        return 10*pow10(num-1);
    }
    
    public static int karatsuba(int x,int y)                                
    {
        if(x<10 && y<10)
            return x*y;
        
        int n=Math.max(count(x),count(y));
        
        int l=ceil(n/2);                                                                        //take ceil of n/2 in case no. is odd

        int xl=x/pow10(l);                                                                      //left part of x
        int xr=x%pow10(l);									//right part of x
        
        int yl=y/pow10(l);									//left part of y
	int yr=y%pow10(l);									//right part of y
		
	int xlyl=karatsuba(xl,yl);
	int xryr=karatsuba(xr,yr);

	//(xr+xl)(yr+yl) - xlyl - xryr =  xlyr + ylxr
		
        return xlyl*pow10(2*l) +   (karatsuba(xr+xl,yr+yl) - xlyl - xryr)*pow10(l)  + xryr;	
    }
    
	public static void main(String[] args) {
		System.out.print(karatsuba(17243,42));
	}
}
