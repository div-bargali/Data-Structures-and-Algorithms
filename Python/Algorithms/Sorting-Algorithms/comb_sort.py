# Python program for implementation of Comb Sort
# Flag ascending is used to determine the sorting type i.e. ascending or descending

# Time Complexity: O(n log n) for the best case and O(n^2) for the worst case.
# Space Complexity: O(1)

"""
Comb sort is an improvement on the bubble sort.
The Comb Sort decreases the gap used in comparisons and exchanges in every iteration using a shrink factor.
The shrink factor(decreasing factor) for this sort is 1.3.
"""


# Function to sort array[] using Comb Sort
def combSort(array, ascending=True):
    # Initialize the Shrink Factor
    shrink_factor = 1.3
    array_size = len(array)

    # Initialize the gap as array length
    gap = array_size

    # Initialize swapped as true to make sure that loop runs in first iteration
    swapped = True

    # Keep running while gap is more than 1 and last iteration caused a swap
    while (gap > 1 or swapped):

        # Decrease the gap using shrink_factor
        gap = int(gap // shrink_factor)
        # Initialize swapped as false to check if swap happened or not
        swapped = False

        # Compare all elements with current gap

        for i in range(array_size - gap):
            if (ascending):
                # Swap elements if they are not in ascending order
                if (array[i] > array[i + gap]):
                    change = array[i]
                    array[i] = array[i + gap]
                    array[i + gap] = change
                    swapped = True
            else:
                # Swap elements if they are not in descending order
                if (array[i] < array[i + gap]):
                    change = array[i]
                    array[i] = array[i + gap]
                    array[i + gap] = change
                    swapped = True


# driver code for Test Comb Sort
if __name__ == "__main__":
    array = [4, 10, 15, 35, -30, 23, -9, 50, 0]

    print("Before Sorting : ", array)
    combSort(array, True)
    print("After Sorting : ", array)
