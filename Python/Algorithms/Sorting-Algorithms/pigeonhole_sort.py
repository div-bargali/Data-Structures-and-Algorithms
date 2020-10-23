# Python method to implement the pigeonhole sorting method on an array of integers
# Sorts the original array in ascending order

def pigeonhole_sort(arr):
    
    # Create empty pigeonholes, each pigeonhole containing an empty array 
    arr_range = max(arr) - min(arr)
    pigeonholes = [[] for _ in range(arr_range + 1)] 
        
    # Assign elements of the original array to the correct pigeonhole
    for i in arr:
        pigeonholes[i - min(arr)].append(i)
        
    # Reassign elements from pigeonholes back into original array
    arr.clear()
    for pigeonhole in pigeonholes:
        for i in pigeonhole: 
            arr.append(i)    
            
# Driver code
if __name__ == "__main__":
	
 # input a list of space separated values
	values = list(map(int, input("Enter list to sort: ").split()))

	print("Before sorting:", values)
	pigeonhole_sort(values)
	print("After sorting:", values)    
    