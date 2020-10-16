#Divide and Conquer Algorithm in Python3. By Th3-N3rd

#Divide and Conquer is a three-step process:

#1) Divide → The first step is to break the problem into smaller subproblems. For example, take an example of any big organization. It would be quite difficult for a single person to directly handle all the work of the organization himself. So, the organization is divided into several departments and different people are appointed to assist those departments. In short, we are breaking our problem into smaller subproblems.
#2) Conquer → This is basically solving of the smaller subproblems. In the example of the organizations, the problems of the departments will be solved individually by the departments.
#3) Combine → In the last step, we combine the solutions of the smaller subproblems to get the solution of the bigger problem. For example, the whole point of an organization would be to earn profit, so whatever the departments are doing, in last, they would sum up to generate some profit for the organization.

#The given is an example of the implementation of Divide and Conquer(Binary Search Implementation)

def bsearch(list, val):

    list_size = len(list) - 1

    idx0 = 0
    idxn = list_size
# Find the middle most value

    while idx0 <= idxn:
        midval = (idx0 + idxn)// 2

        if list[midval] == val:
            return midval
# Compare the value the middle most value
        if val > list[midval]:
            idx0 = midval + 1
        else:
            idxn = midval - 1

    if idx0 > idxn:
        return None
# Initialize the sorted list
list = [2,7,19,34,53,72]

# Print the search result
print(bsearch(list,72))
print(bsearch(list,11))

#Output :

#5
#None