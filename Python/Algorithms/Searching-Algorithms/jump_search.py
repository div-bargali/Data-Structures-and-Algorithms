import sys
import math



'''  variable assignment =

    -n is size of array
    -s_element is element to be searched in the array
''' 


# The function returns location of s_element in given array arr 
# if present, else returns -1 


def jump_search( arr , s_element , n ): 
	
	# Finding block size to be jumped 
	step = math.sqrt(n) 
	
	# Finding the block where element is 
	# present (if it is present) 
	prev = 0
	while arr[int(min(step, n)-1)] < s_element: 
		prev = step 
		step += math.sqrt(n) 
		if prev >= n: 
			return -1
	
	# Doing a linear search for s_element in 
	# block beginning with prev. 
	while arr[int(prev)] < s_element: 
		prev += 1
		
		# If we reached next block or end 
		# of array, element is not present. 
		if prev == min(step, n): 
			return -1
	
	# If element is found 
	if arr[int(prev)] == s_element: 
		return prev 
	
	return -1

# Driver code

if __name__ == '__main__':
	print('enter the number of elements')
	n=int(input())

	print('\nenter the elements in a single line with space')

	arr=list(map(int,input().split()))

	print('\nenter the element to be searched')
	s=int(input())

	result=jump_search(arr,s,n) #calling function

	print("Number" , s, "is at index" ,"%.0f"%result)

	
		