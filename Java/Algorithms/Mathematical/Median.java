import java.util.*;
import java.io.*;
import java.lang.*;
class Median
{
	public static void main(String args[]) 
    { 
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number of elements in the array"); 
		int n=sc.nextInt();
		double[] input=new double[n];
		System.out.println("Enter the elements of the array(" +n+ "): ");
		for(int i=0;i<n;i++) 
		{
			input[i]=sc.nextDouble();
		}
		double res = calcMedian(n,input);
		System.out.println("The median of the array is : " + res);     
    }
	static double calcMedian(int n, double arr[])
	{
		double k=0;	
		if(n%2==1)
		{
			k = arr[((n+1)/2)-1];
		}
		else
		{
			k = (arr[n/2-1]+arr[n/2])/2;
		}
		return k;
	}
}