// Implementation of a generic linear search for C#
using System;

class LinearSearch { 
	
	// Returns the index of the searched for element if present, else returns -1  
	public static int Search<T>(T[] arr, T itemToFind)
	{ 
		for (int i = 0; i < arr.Length; i++)  {
            if (arr[i].Equals(itemToFind)) {
                return i;
			}
		}

		// If this point is reached then element has not been found 
		return -1; 
	} 

	// Driver method to test above 
	public static void Main()  { 

		Console.WriteLine("Input array to search through, separated by spaces");

		var arr = Console.ReadLine();

		Console.WriteLine("Input item to search for");

		var itemToFind = Console.ReadLine();

		var result = Search(arr.Split(' '), itemToFind);

		if (result == -1) 
			Console.WriteLine("Element not present"); 
		else
			Console.WriteLine("Element found at index "
								+ result); 
	}
	
}
