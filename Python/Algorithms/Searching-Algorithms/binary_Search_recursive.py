import sys

sys.setrecursionlimit(10**4) #increasing recursion limit for large arrays


'''  variable assignment =

    -left is left index of array/subarray
    -right is right index of array/subarray
    -s_element is element to be searched in the array
'''

# The function returns location of s_element in given array arr 
# if present, else returns -1 

def binary_search(arr,left,right,s_element):
	
	if right>=left: #base case

		mid=(left+right)//2 #setting middle index of the array
         
		if arr[mid]==s_element: 
			return mid  #if element is present at the middle then return it

		elif arr[mid]>s_element:
			return binary_search(arr,left,mid-1,s_element) #if element is smaller than mid, then it can only be present in left subarray

		else:
			return binary_search(arr,mid+1,right,s_element) # Else the element can only be present in right subarray 
	else: 
		return -1    #element is not present


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


	

	