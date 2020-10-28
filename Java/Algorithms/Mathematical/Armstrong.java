//Program to check whether a number is an armstrong number or not. 
//A positive integer is called an Armstrong number of order n if the sum of cubes of each digits is equal to the number itself.

import java.util.Scanner;

public class Armstrong {

    public static void main(String[] args) 
	{
		System.out.println("Enter any number: ");
        Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m, rem, res = 0;

        m = n;
		
        while(m!= 0)
        {
            rem = m % 10;
            res+= Math.pow(rem, 3);
            m /= 10;
        }

        if(res == n)
            System.out.println(n + " is an Armstrong number.");
        else
            System.out.println(n + " is not an Armstrong number.");
    }
}