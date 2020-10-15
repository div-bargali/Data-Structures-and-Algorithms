/* A matrix contains of only 0 and 1 , 
   One has to find the different ways to reach to the end of the matrix . 
   But the condition is that one cannot encounter 1/ we cannot cross 1 or one has to backtrack when 1 encounters. 
   We need to print all the paths by which we can go to the end of matrix without encountering 1 */

import java.util.*;
public class Floodfill{

    public static void floodFills(int[][] arr,int i,int j,String path){
        // base case
            if(i==arr.length-1 && j==arr[0].length-1){
                System.out.println(path+".");
                return;
            }
        // pre work
            arr[i][j] = 1;
        // up
        if(i-1>=0 && arr[i-1][j] != 1)
            floodFills(arr, i-1, j, path+"up-> ");            
        // left
        if(j-1>=0 && arr[i][j-1] !=1)
            floodFills(arr, i, j-1, path+"left-> ");
        // down
        if(i+1<arr.length && arr[i+1][j] != 1)
            floodFills(arr, i+1, j, path+"down-> ");
        // right
        if(j+1 < arr[0].length && arr[i][j+1] != 1)
            floodFills(arr, i, j+1, path+"right-> ");
        // post work
        arr[i][j] = 0;
    }

  public static void main(String[] args){
      int[][] arr = { {0,0,0,0,0},
                      {0,1,0,1,0},
                      {0,1,0,1,0},
                      {0,1,0,1,0},
                      {0,0,0,0,0}};

        floodFills(arr,0,0,"");
  }
}