# Exponential search

# Function to perform recursive binary search
def binary_search(array,low,high,value):
    if high>= low:
        mid=int(low + ( high-low )//2)
        if array[mid] == value:
            return mid
        if array[mid] > value:
            return binary_search(array,low,mid - 1,value)
        else:
            return binary_search(array,mid + 1,high,value)
    if high<low:
        return -1


length = int(input("Enter the number of element you want: "))   # Get the size of the array
my_list = []

# Get the input elements of the list
for i in range(length):
    in_element = int(input(f" Enter {i+1} element: "))
    my_list.append(in_element)

# Get the element whose position is to be known
n= int(input("Enter the element whose position you want to know: "))

i = 1
len_array = len(my_list)

#Finding range for binary search
while(i<len_array and my_list[i]<=n):
        i = i * 2
min1=min(i,len_array)


index= binary_search(my_list,i/2,min(i,len_array),n)

if index == -1:
    print(f"{n} is not found in the list")
else:
    print (f"{n} is present at position {index + 1}")  # The output gives the position of the element, not index


# If you want to know more about the algorithm and the code visit https://www.codespeedy.com/exponential-search-in-python/ 