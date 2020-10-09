import sys 


'''  variable assignment =

    -n is size of array
    -s_element is element to be searched in the array
''' 


# The function returns location of s_element in given array arr 
# if present, else returns -1 

def linear_search(arr,s_element):
	n=len(arr)
	for i in range(n): #comparing each element with s_element and if found then return its index
		if arr[i]==s_element:
			return i
	return -1

# Driver code

if __name__ == '__main__':
	print('enter the number of elements')
	n=int(input())

	print('\nenter the elements in a single line with space')

	arr=list(map(int,input().split()))

	print('\nenter the element to be searched')
	s=int(input())

	result=linear_search(arr,s) #calling function

	print("Number" , s, "is at index" ,"%.0f"%result)