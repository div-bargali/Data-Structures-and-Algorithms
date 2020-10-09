import sys


'''  variable assignment =

    -left is left index of array/subarray
    -right is right index of array/subarray
    -s_element is element to be searched in the array
'''

# The function returns location of s_element in given array arr 
# if present, else returns -1 

def binary_search(arr, left, right, s_element): 

	while left <= right: 

		mid = (left + right) // 2; 
		
		# Check if x is present at mid 
		if arr[mid] == s_element: 
			return mid 

		# If x is greater, ignore left half 
		elif arr[mid] < s_element: 
			left = mid + 1

		# If x is smaller, ignore right half 
		else: 
			right = mid - 1
	
	# If we reach here, then the element 
	# was not present 
	return -1

#driver code
if __name__ == '__main__':
	print('enter the number of elements')
	n=int(input())

	print('\nenter the elements in a single line with space')

	arr=list(map(int,input().split()))

	print('\nenter the element to be searched')
	s=int(input())

	result=binary_search(arr,0,n-1,s) #calling function

	if result==-1:
		print('\nelement not present')
	else:
		print('\nelement is present at',result)


