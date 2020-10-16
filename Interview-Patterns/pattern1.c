#include<stdio.h>
int main()
{
	int i,j,k,n=7,count=0,temp;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		for(j=n;j>i;j--)
		printf("%d",j);
		for(j=1;j<n*2-count;j++)
		printf("%d",i);
		for(j=i;j<n;j++)
		printf("%d",j+1);
		count+=2;
		printf("\n");
	}
	count=0;
	for(i=2;i<=n;i++)
	{
		for(j=n;j>=i;j--)
		printf("%d",j);
		for(j=2;j<=i+count;j++)
		printf("%d",i);
		for(j=i;j<=n;j++)
		printf("%d",j);
		count++;
		printf("\n");
	}
}
