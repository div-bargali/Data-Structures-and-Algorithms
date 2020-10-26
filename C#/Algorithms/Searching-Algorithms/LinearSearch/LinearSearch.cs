// C# implementation of a simple linear search 
using System; 
  
class LinearSearch<T> { 

    // Returns the index of the searched for element if present, else returns -1  
    static T LinearSearch(T[] arr, T itemToFind) where T : class  
    { 
        int index = 0;
        foreach (var item in arr)  {
            if (item == itemToFind) {
                return index;
            }
            index ++;
        }
            
        // If this point is reached then element has not been found 
        return -1; 
    } 
  
}

// Driver method to test above 
public static void Main()  { 

    Console.WriteLine("Input array to search through, separated by spaces");

    var arr = Console.ReadLine();

    Console.WriteLine("Input item to search for");

    var itemToFind = Console.ReadLine();

    var result = LinearSearch(arr, itemToFind);

    if (result == -1) 
        Console.WriteLine("Element not present"); 
    else
        Console.WriteLine("Element found at index "
                            + result); 
} 
 


