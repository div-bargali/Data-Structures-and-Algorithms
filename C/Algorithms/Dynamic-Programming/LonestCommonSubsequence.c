#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
    return (a>b)? a: b;
}
int LCS(char * a,char * b,int n1,int n2){
    if(n1==0 || n2==0) return 0;

    // if two character are common than check for subproblems 
    if(a[n1-1]==b[n2-1])
      return 1+LCS(a,b,n1-1,n2-1);
    // If two character is not common than two cases are arises
    // case 1:  to leave the character of first string and check for subproblem with second string
    // case 2: to leave the character of second string and check for subproblem with first string
    return max(LCS(a,b,n1-1,n2),LCS(a,b,n1,n2-1));
}
int main(){
    int n1,n2; scanf("%d %d",&n1,&n2);

    char a[n1],b[n2];
    scanf("%s",a);
    scanf("%s",b);
    printf("longest common subsequence is %d\n",LCS(a,b,n1,n2));
    return 0;
}