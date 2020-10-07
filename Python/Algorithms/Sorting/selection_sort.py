# function to sort list of integers in place
# flag ascending is used to determine the sorting type i.e. ascending or descending
# selection sort selects the i-th minimun or i-th maximum element to be placed in index i

# time complexity = O(n^2) even fro best case

def selectionSort(a, ascending=True):
	n = len(a)
	# ranging to n-1 and not n because
	# if we put all the other elements in their right positions, 
	# the last elemet will be in the right position too
	for i in range(n-1):
		index = i
		# find index of minimum/ maximum value on the right side
		for j in range(i+1, n):
			if ascending:
				if a[j] < a[i]:
					index = j
			else:
				if -a[j] < -a[i]:
					index = j
		# swap a[index] with a[i]
		a[index], a[i] = a[i], a[index]



# driver code
if __name__ == "__main__":
	# input a list of space separated integers
	sort_order = input("Enter 'd' for descending order of sort (by default ascending order is selected): ")
	l = list(map(int, input("Enter list to sort: ").split(" ")))

	print("Before sorting:", l)
	if sort_order == 'd':
		selectionSort(l, False)
		print("Sorting in descending order...")
	else:
		selectionSort(l)
		print("Sorting in ascending order...")
	print("After sorting:", l)
