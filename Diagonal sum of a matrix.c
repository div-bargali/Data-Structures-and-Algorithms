#include<stdio.h>
#include<conio.h>
 int main()
{
	int a[3][3],i,j,sum1=0,sum2=0;
	printf("Enter the numbers=");       
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("In matrix form\n");
	for(i=0;i<=2;i++)                   
	{
		for(j=0;j<=2;j++)
		{
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<=2;i++)                  
	{      
	   
		for(j=0;j<=2;j++)
		{
			if(i==j)               
			{
				sum1=sum1+a[i][j];
			}
			if(i+j==2)            
			{
				sum2=sum2+a[i][j];
			}
		}
		
	}
	printf("sum of left diagonal=%d\n",sum1);
	printf("sum of right diagonal=%d",sum2);
	return 0;
	
}
