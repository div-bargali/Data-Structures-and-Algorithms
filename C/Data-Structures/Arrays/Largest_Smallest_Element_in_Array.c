#include<stdio.h>
main()
{
	int arr[5],l,s;
	printf("\tACCESSING THE LARGEST AND THE SMALLEST ELEMENT IN AN ARRAY\n");
	int i;
	printf("\nEnter 5 Elements in the Array");
	for(i=0;i<=4;i++)
	{
		printf("\nEnter the Element:");
		scanf("%d",&arr[i]);
	}
	l=s=arr[0];
	for(i=0;i<=4;i++)
	{
		if(arr[i]>l)
		  l=arr[i];
		else if(arr[i]<s)
		  s=arr[i];
	}
	printf("\nThe Array is:");
	for(i=0;i<=4;i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n\n\tThe Largest Element is %d. ",l);
	printf("\n\n\tThe Smallest Element is %d.",s);
}