//C# implementation of the bubble sort algorithm
using System;

public class BubbleSort
{
	public static T[] bubbleSort<T>(T[] array, bool ascending) where T : IComparable
    {
        //Clone the array so that the original is not overwritten
        T[] result = (T[])array.Clone();

        //Run through the array once for every item in it
        for(int i = 0; i < result.Length; i++){
            //Run through the first i-1 items in the array.
            //This will ignore any items that have already "bubbled up" to the top,
            //as well as the last item, so that it doesn't try to compare it with an item outside the array.
            for (int j = 0; j < result.Length - i - 1; j++)
            {
                //Compare the current and next item and check if they are ascending
                bool comparedItemsAscend = result[j].CompareTo(result[j+1]) < 0;

                //If the items are not in the order they should be, swap them
                if(comparedItemsAscend != ascending)
                {
                    T buffer = result[j];
                    result[j] = result[j+1];
                    result[j+1] = buffer;
                }
            }
        }

        //Return the reordered array
        return result;
    }

    //Driver method to test above
    private static void Main()
    {
        //Ask the user for a list of floats and convert it to a float array
        Console.WriteLine("Write a list of floats, separated by spaces.");
        string[] inputArray = Console.ReadLine().Split(' ');
        float[] arrayToSort = Array.ConvertAll<string, float>(inputArray, float.Parse);

        //Ask the user wether to sort ascending or descending
        Console.WriteLine("Press D to sort descending, press anything else to sort ascending.");
        bool sortAscending = Console.ReadKey(true).Key != ConsoleKey.D;

        //Sort the array
        float[] sortedArray = bubbleSort(arrayToSort, sortAscending);

        //Print original and sorted array
        Console.WriteLine("Original array: " + string.Join(", ", arrayToSort));
        Console.WriteLine("Sorted array: " + string.Join(", ", sortedArray));
    }
}
