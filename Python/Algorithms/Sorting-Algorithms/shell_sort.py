# Python program for implementation of Shell Sort

# Shell sort is an algorithm that first sorts the elements far apart
# from each other and successively reduces the interval 
# between the elements to be sorted. It is a generalized version of insertion sort.'''

def shellSort(values): 

    # Start with a somewhat big gap, then reduce the gap
    n = len(values)
    gap = n//2

    # Do a gapped insertion sort for this gap size.
    # The first gap elements  are already in gapped
    # order keep adding one more element until the entire array
    # is gap sorted
    while gap > 0: 

        for i in range(gap,n): 

            # add a[i] to the elements that have been gap sorted
            # save a[i] in temp and make a hole at position i
            temp = values[i]

            # shift earlier gap-sorted elements up until the correct
            # location if a[i] is found
            j = i
            while j >= gap and values[j-gap] >temp:
                values[j] = values[j-gap]
                j -= gap

            # put temporary variable in its correct location
            values[j] = temp
        gap //= 2


# Insert Test Values
values = [1, 2, 4, 12, 34, 54, 2, 3, 9, 15, 20]
n = len(values)

print ("Array before sorting: "+ str(values))

shellSort(values)

print ("Array after sorting:"+ str(values))

