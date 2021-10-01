#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int l1,l2,i,j,check=0;
    char *ar1=(char*)malloc(50*sizeof(char));
    char *ar2=(char*)malloc(50*sizeof(char));
    printf("enter string 1 and string 2\n");
    scanf("%s %s",ar1,ar2);
    l1=strlen(ar1);
    l2=strlen(ar2);

    //CREATING DP TABLE
    int **arr=(int **)malloc((l1+1)*sizeof(int *));//2D array with constitutes the DP table
    for(i=0;i<=l1;i++)
        arr[i]=(int *)malloc((l2+1)*sizeof(int *));

    //PREPROCESSING DP TABLE
    for(i=0;i<=l1;i++)
        arr[i][0]=0;
    for(i=0;i<=l2;i++)
        arr[0][i]=0;

    //DP ITERATION STARTS
    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            if(ar1[i-1]==ar2[j-1])
                arr[i][j]=arr[i-1][j-1]+1;
            else
            {
                if(arr[i-1][j]>arr[i][j-1])
                    arr[i][j]=arr[i-1][j];
                else
                    arr[i][j]=arr[i][j-1];
            }
        }
    }
    //arr[l1][l2] contains the length of the longest common subsequence
    printf("The length of Longest Common Subsequence is %d\n", arr[l1][l2]);
    
    return 0;
}

