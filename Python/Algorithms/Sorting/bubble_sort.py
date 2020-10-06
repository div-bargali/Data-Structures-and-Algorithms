# function to sort list of integers in place
# flag ascending is used to determine the sorting type i.e. ascending or descending
# in bubble sort, the max or min value bubbles up to the end

# time complexity = O(n^2), but better than selection since best case complexity is O(n)

def bubbleSort(a, ascending=True):
	n = len(a)
	for i in range(n):
		for j in range(n-i-1):
			if ascending:
				if a[j] > a[j+1]:
					# element bubbles up one index
					a[j], a[j+1] = a[j+1], a[j]
			else:
				if -a[j] > -a[j+1]:
					# element bubbles up one index
					a[j], a[j+1] = a[j+1], a[j]

# driver code
if __name__ == "__main__":
	# input a list of space separated integers
	sort_order = input("Enter 'd' for descending order of sort (by default ascending order is selected): ")
	l = list(map(int, input("Enter list to sort: ").split(" ")))

	print("Before sorting:", l)
	if sort_order == 'd':
		bubbleSort(l, False)
		print("Sorting in descending order...")
	else:
		bubbleSort(l)
		print("Sorting in ascending order...")
	print("After sorting:", l)
