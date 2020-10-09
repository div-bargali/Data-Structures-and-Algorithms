# time complexity = O(nlogn)
# space complexity = O(n) since we need to store the merged array b in merge()
# merge sort uses divide and conquer
# we keep on dividing an array along the middle index into adjacent sub-arrays and sorting them recursively

# function to merge 2 sorted sub-arrays/halves of array a
# sort_order is used to determine if the array will be sorted in ascending or descending order
def merge(a, start, mid, end, sort_order):
	i = start # starting index of subarray 1
	j = mid + 1 # starting index of subarray 2
	b = []
  # compare i-th and j-th element sub-array 1 and 2 respectively
  # append whichever is smaller or both if both are equal
  # loop break when we reach the end or one or both of the sub arrays
	while i <= mid and j <= end:
		if sort_order*a[i] < sort_order*a[j]:
			b.append(a[i])
			i += 1
		elif sort_order*a[j] < sort_order*a[i]:
			b.append(a[j])
			j += 1
		else:
			b.append(a[i])
			i += 1
			b.append(a[j])
			j += 1
	# if any element is left in sub array1, append to b
	while i <= mid:
		b.append(a[i])
		i += 1
	# if any element is left in sub array2, append to b
	while j <= end:
		b.append(a[j])
		j += 1
	
	# copy the sorted array into a
	# subarray 1 and subarray 2 are adjacent hence we just sorted array a from index start to end
	for i in range(start, end+1):
		a[i] = b[i - start]


def mergeSort(a, start, end, sort_order=1):
	# if start == end i.e. sort one element
	# array of one element is always sorted
	if start != end:
		mid = (start + end) // 2
		# sort subarray 1 - left half
		mergeSort(a, start, mid, sort_order)
		# sort subarray 2 - right half
		mergeSort(a, mid+1, end, sort_order)
		# merge sorted subarrays/ halves
		merge(a, start, mid, end, sort_order)

# driver code
if __name__ == "__main__":
	sort_order = input("Enter 'd' for descending order of sort (by default ascending order is selected): ")
	l = list(map(int, input("Enter list to sort: ").split(" ")))

	print("Before sorting:", l)
	if sort_order == 'd':
		mergeSort(l, 0, len(l) - 1, -1)
		print("Sorting in descending order...")
	else:
		mergeSort(l, 0, len(l) - 1)
		print("Sorting in ascending order...")
	print("After sorting:", l)