import java.util.Scanner;
class Fibonacci{
    public static void fibonacci(int n){
        //checking for invalid input
        if(n<=0) 
        {
            System.out.print("Invalid input");
            return;
        }
        //base case
        if(n==1) 
        {
            System.out.print("0 ");
            return;
        }
        //if n>1 then print 0 and 1 (the first two fibonacci numbers)
        System.out.print("0 1 ");
        int a=0;
        int b=1;
        int c=a+b;
        while(n-2 > 0){
            System.out.print(c + " ");
            a=b;
            b=c;
            c=a+b;
            n--;
        }
    }
    public static void main(String[] args) {
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number of Fibonacci numbers: ");
        n=sc.nextInt();
        fibonacci(n);
    }
}