# function to sort list of integers in place
# flag ascending is used to determine the sorting type i.e. ascending or descending
# insertion sort inserts elements into the left part of the array such that the left part is always sorted

# time complexity = O(n^2), but better than selection since best case complexity is O(n)

def insertionSort(a, ascending=True):
	n = len(a)
	# ranging from 1 and not 0 because 
	# a[0] by itself is always sorted
	for i in range(1, n):
		key = a[i]
		j = i-1

		while j > -1:
			if ascending:
				if key < a[j]:
					a[j], a[j+1] = a[j+1], a[j]
				else:
					break
			else:
				# for descenfing sort just compare -1 * value of elements
				if -key < -a[j]:
					a[j], a[j+1] = a[j+1], a[j]
				else:
					break
			j -= 1
		a[j+1] = key


# driver code
if __name__ == "__main__":
	# input a list of space separated integers
	sort_order = input("Enter 'd' for descending order of sort (by default ascending order is selected): ")
	l = list(map(int, input("Enter list to sort: ").split(" ")))

	print("Before sorting:", l)
	if sort_order == 'd':
		insertionSort(l, False)
		print("Sorting in descending order...")
	else:
		insertionSort(l)
		print("Sorting in ascending order...")
	print("After sorting:", l)
