# ##BOGO SORT##
# This is a Bogo Sort sorting algorithm implemented in Python
# It is a really (really) slow algorithm, and has expected time complexity of n!, given that random.shuffle is uniform.

import random

# Checks if a list is sorted.
def is_sorted(lst):
    for i in range(1,len(lst)):
        if lst[i-1] > lst[i]:
            return False
    return True

# Sorts and returns the list
def bogo_sort(lst):
    while not is_sorted(lst):
        random.shuffle(lst)
    return lst

# Driver
array = [53, 43, 67, 0, 1, 4, 5, -1, 0.43]
print(bogo_sort(array))


