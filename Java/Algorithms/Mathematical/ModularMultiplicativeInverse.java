//Given two integers ‘a’ and ‘m’. The task is to find modular multiplicative inverse of ‘a’ under modulo ‘m’.
//Input: a = 3 m = 11 Output: 4

public int modInverse(int a, int m)
    {
      //Your code here
      for(int i=0;i<m;i++){
          if((i*a)%m==1){
              return i;
          }
      }
      return -1;
    }
