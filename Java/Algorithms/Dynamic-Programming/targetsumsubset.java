/*  1. You are given a number n, representing the count of elements.
    2. You are given n numbers.
    3. You are given a number "tar".
    4. You are required to calculate and print true or false, if there is a subset the elements of which add 
       up to "tar" or not.
  
   Example:  arr={4,2,7,1,3}
             target sum= 10
             output: true
      */       

import java.util.*;
public class targetsumsubset{

     public static boolean targetsum(int[] arr,int target){
        boolean[][] dp=new boolean[arr.length+1][target+1];
        dp[0][0]=true;
        for(int i=1;i<dp.length;i++){
            for(int j=0;j<dp[0].length;j++){
                if(dp[i-1][j]==true){
                    dp[i][j]=true;
                }
                else if(j-arr[i-1] >=0 && dp[i-1][j-arr[i-1]] == true){
                    dp[i][j]=true;
                }
            }
        }
        
        return dp[dp.length-1][dp[0].length-1];
    }

    public static void main(String[] args) {
    Scanner scn=new Scanner(System.in);
    int n=scn.nextInt();
    int[] arr=new int[n];
    for(int i=0;i<arr.length;i++){
        arr[i]=scn.nextInt();
        
    }
    int target=scn.nextInt();
    System.out.println(targetsum(arr,target));
    }
}