#include<stdio.h>
int main()
{
	int i,j,n=7;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==0||j==0||i==n-1||j==n-1)
			printf(" * ");
			else if(i==j||j==(n-1-i))
			printf(" * ");
			else printf("   ");
		}
		printf("\n");
	}
}
