from random import randint


class BinaryInsertionSort:
    """ A class to demonstrate Binary Insertion Sort """

    def __init__(self, array):
        """ Takes the argument array of which is to be sorted """

        self.array = array

    def __repr__(self):
        return f"Array: {self.array}"

    def binarySearch(self, array, element, startIdx, endIdx):
        """ Performs binary search in the sorted sub-array to insert the next element correctly """

        low, high = startIdx, endIdx

        while low <= high:
            mid = (low + high) // 2

            if low == high:
                if array[low] == element:
                    return low + 1
                if array[low] > element:
                    return low

            if array[mid] < element:
                low = mid + 1

            if array[mid] > element:
                high = mid - 1

            if array[mid] == element:
                return mid + 1

        if low > high:
            return low

    def insertionSort(self):
        """ Performs Insertion Sort """

        print(f"The given array: {self.array}")

        for i in range(1, len(self.array)):
            currentElement = self.array[i]
            j = i - 1

            # Searches the location at which the current element is to be inserted

            searchedLocation = self.binarySearch(
                self.array, currentElement, 0, i-1)

            # Inserting the current element in the searched location
            while j >= searchedLocation:
                self.array[j + 1] = self.array[j]
                j -= 1
            self.array[j + 1] = currentElement

        print(f"The sorted array: {self.array}")

        return self.array


array = [randint(1, 100) for i in range(10)]

demo = BinaryInsertionSort(array)

sorted_array = demo.insertionSort()

assert (sorted(array) == sorted_array)
