public class BubbleSort {

//Sorts a given array using bubblesort algorithm. 
	
	int[] bubblesort(int[] arr)
	{
		boolean sorted = false; //set flag to check if sorting is completed
		
		int mark = arr.length-1; 
		
		while(!sorted)
		{
			sorted = true; //for each pass, assume sorting is done
			
			for(int j=0;j<mark;j++)
			{
				if(arr[j] > arr[j+1]) //if current element is larger than next element, swap them 
				{
					swap(arr, j, j+1);
					sorted = false; // to check if further bubbling is necessary
				}
			}
			mark--; //Length for iteration can be decremented for each pass since the largest element is bubbled to the end of the array
		}
		return arr;
	}
	
	void swap(int[] arr, int m, int n)
	{
		//basic swapping method
		
		int temp = arr[m];
		arr[m] = arr[n];
		arr[n] = temp;
	}

}
