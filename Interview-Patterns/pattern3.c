#include<stdio.h>
int main()
{
	int i,j,n=14,count2=0,count=2;
	printf("Enter the even no greater than 7 : ");
	scanf("%d",&n);
	if(n>7&&n%2==0)
	{
			system("cls");
			for(i=1;i<n/2;i++)
			{
				for(j=1;j<n/2-i;j++)
				printf(" ");
				for(j=1;j<=4+count2;j++)
				printf("*");
				for(j=1;j<n-count;j++)
				printf(" ");
				count+=2;
				for(j=1;j<=4+count2;j++)
				printf("*");
				count2+=2;
				printf("\n");
			}
			count=0;
		    for(i=0;i<=n;i++)
		    {
		    	for(j=1;j<=i;j++)
		    	printf(" ");
		    	for(j=1;j<=n*2+1-count;j++)
		    	printf("*");
		    	printf("\n");
		    	count+=2;
			}
    }
    else printf("Please enter correct input");
}
