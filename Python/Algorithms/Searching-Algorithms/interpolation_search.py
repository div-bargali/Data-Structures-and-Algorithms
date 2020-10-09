# Interpolation search is performed by the formula:
# pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]
# where,
# arr[] = Array where elements need to be searched
# x = Element to be searched
# lo = Starting index in arr[]
# hi = Ending index in arr[]

# Function to perform interpolation search
def interpolation_search(array, element):
    lo = 0
    hi = len(array) - 1 

    while lo <= hi and element >= array[lo] and element <= array[hi]:
        # Check if the list is one element list
        if lo == hi:
            if array[lo] == element:
                return lo
            return -1
        
        # Formula for interpolation search
        position = lo + int(((float(hi - lo)/
                    (array[hi]- array[lo])) * (element - array[lo])))

        # Check if the position is correct for the element
        if array[position] == element:
            return position
        
        if array[position] < element:
            lo = position + 1
        
        else:
            hi = position -1
    
    return -1


length = int(input("Enter the number of element you want: "))   # Get the size of the array
my_list = []

# Get the input elements of the list
for i in range(length):
    in_element = int(input(f" Enter {i+1} element: "))
    my_list.append(in_element)

# Get the element whose position is to be known
n= int(input("Enter the element whose position you want to know: "))
index = interpolation_search(my_list, n)

if index != -1:
    print (f"{n} is found at position  ", index + 1) # The output gives the position of the element, not index

else:
    print (f"{n} is not found in the list")