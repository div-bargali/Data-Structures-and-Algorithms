//FRACTIONAL KNAPSACK PROBLEM IN C
/*Given weights and values of n items, 
we need to put these items in a knapsack of capacity W
to get the maximum total value in the knapsack.
In Fractional Knapsack, we can break items for maximizing
the total value of knapsack. This problem in which we can 
break an item is also called the fractional knapsack problem. 
*/
#include<stdio.h>

 //Contributed By : Swati Tripathi (@swati-gwc)
 //knapsack function using quicksort
  void swap(float* a, float* b) //for swapping float values
  {
    float t = *a;
    *a = *b;
    *b = t;
  }
  void swapin(int* a, int* b) //for swapping integers
  {
    int t = *a;
    *a = *b;
    *b = t;
  }
//QUICK SORT CODE STARTS

//quicksort partition function
//In the code of quicksort arr,wt,pf and in array are sorted simultaneously 
//on the basis of arr array
//which means main sorting is done on arr array and accordingly other array elements
//change their position in array
int partition (float arr[], float wt[], float pf[], int in[], int l, int h)
{
    //wt is array of  weight of each items
    //pf stands for profit of each item 
    //in stands for index which contains the index of each item
    //arr is the profit to weight ratio on the basis of which items are 
    //considered for adding
    float pivot = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {

        if (arr[j]> pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            swap(&wt[i], &wt[j]);
            swap(&pf[i], &pf[j]);
            swapin(&in[i], &in[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    swap(&wt[i+1], &wt[h]);
    swap(&pf[i+1], &pf[h]);
    swapin(&in[i+1], &in[h]);
    return (i + 1);
}

//recursive quick sort function
void quickSort(float arr[], float wt[], float pf[], int in[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(arr,wt, pf, in, l, h);
        quickSort(arr,wt,pf, in, l, pi - 1);
        quickSort(arr, wt,pf, in, pi + 1, h);
    }
}
//QUICK SORT CODE ENDS HERE

//FRACTIONAL KNAPSACK FUNCTION
//This is the fractional knapsack function 
 void knapsack (int n, int index[], float w[], float p[], float capacity)
{
   float x[20];
   float total_profit = 0;
    int i, j;
    float W = capacity;

     for(i=0;i<n;i++)
        x[i]=0.0;

    float weight=0;

    for(i=0;i<n;i++)
    {
        int a=index[i];
        //if statement is executed only if weight of element + weight of elements
        //already added in bag is less or equal than
        //maximum capacity of Knapsack bag i.e. W
        if(weight+w[i]<=W) 
        {
           
            x[a]=1;
            weight=weight+w[i];
            total_profit=total_profit+p[i];
        }
        else
        {
            //if taking complete weight of considered item is becoming greater than
            //max capacity i.e. W then fraction of weight of that item is considered
            
            x[a]=(W-weight)/w[i];
            total_profit+=(x[a]*p[i]);
            weight=W;
            break;
        }
    }

  //printing the final soultion vector
   printf("\nsolution vector: \n");
   printf("[");
   for(i=0;i<n;i++)
   printf("%0.2f, ",x[i]);
   printf("]");

   //printing the total profit calculated on the basis of fractional Knapsack algo
   printf("\n\nTotal Profit is : %f",total_profit);
}


//Main Function of this program
 int main()
{
    float weight[20] = {0}; //array contains weight of each element/item
    float profit[20] = {0}; //array contains corresponding weight of element/item
    int index[20]={0}; //array to track index of each item/element
    float ratio[20]={0}; //array to calculate profit to weight ratio of each item
    float W; //W is the maximum capacity of Knapsack Bag
    
    int n ,i,j; //n is the no of elements
    
    printf("Fractional Knapsack problem\n");
    printf("Enter size of elements(max upto 20)\n");
    scanf("%d",&n);

   printf("\nEnter the weight and profits of each item : \n ");
   for (i = 0; i < n; i++) {
       printf("item %d : ", i+1);
       index[i]=i;
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("\nEnter maximum capacity of knapsack:- ");
   scanf("%f", &W);
   printf("\n");

   for (i = 0; i < n; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   quickSort(ratio, weight, profit, index, 0, n-1);

   knapsack(n, index, weight, profit, W);
 return 0;
}
/*
OUPUT OF THIS CODE LOOKS LIKE BELOW:
Fractional Knapsack problem
Enter size of elements(max upto 20)
5

Enter the weight and profits of each item : 
 item 1 : 5 30
item 2 : 10 20
item 3 : 20 100
item 4 : 30 90
item 5 : 40 160

Enter maximum capacity of knapsack:- 60


solution vector: 
[1.00, 0.00, 1.00, 0.00, 0.88, ]

Total Profit is : 270.000000


*/
