#include<stdio.h>
int main()
{
	int i,j,n=5,side_space,k;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	side_space=n/2+1;
	system("cls");
	for(i=1;i<=n;i++)
	{
		if(i<=side_space)
		{
			for(j=1;j<=side_space-i;j++)
	        printf(" ");
	        for(j=1;j<=i;j++)
	        printf("*");
		}
	   else if(i>side_space)
		{
			for(j=1;j<=i-side_space;j++)
			printf(" ");
			for(j=1;j<=n-i+1;j++)
			printf("*");
		    if(i==n)
			{
				for(j=1;j<=n;j++)
				printf("@");
			}
		}
		printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<side_space+n;j++)
		printf(" ");
		if(i<side_space)
		{
			for(j=1;j<=i;j++)
			printf("*");
			j--;
			for(k=1;k<=n-j*2;k++)
			printf(" ");
			for(j=1;j<=i;j++)
			printf("*");
		}
		if(i==side_space)
		for(j=1;j<=n;j++)
		printf("*");
		if(i>side_space)
		{
			for(j=1;j<=n+1-i;j++)
			printf("*");
			j--;
			for(k=1;k<=n-j*2;k++)
		    printf(" ");
		    for(j=1;j<=n+1-i;j++)
		    printf("*");
		}
		if(i==n)
	{	for(j=1;j<=n;j++)
		printf("@");
      printf("*");
	  }
		printf("\n");
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<n*3+side_space;j++)
		printf(" ");
		if(i<=side_space)
	     	for(j=1;j<=i;j++)
	     	printf("*");
	    else
	    for(j=1;j<=n-i+1;j++)
	    printf("*");
	    printf("\n");
	}
}
