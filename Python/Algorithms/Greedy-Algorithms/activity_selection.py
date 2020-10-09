import sys

"""Prints a maximum set of activities that can be done by a 
single person, one at a time"""
# n --> Total number of activities 
# start--> An array that contains start time of all activities 
# finish --> An array that contains finish time of all activities 

#utility function
def compare(a):
	return a[1] #creturn finish time of that activity



def printMaxActivities(arr,n): 

	s_arr=sorted(arr,key=compare) #sorting the array on the basis of finish time, using the key function we have just created above
	

	print("The following activities are selected")

	# The first activity is always selected 
	i = 0
	print(s_arr[i])

	# Consider rest of the activities 
	for j in range(n): 

		# If this activity has start time greater than 
		# or equal to the finish time of previously 
		# selected activity, then select it 
		if s_arr[j][0] >= s_arr[i][1]: 
			print(s_arr[j]) 
			i = j 

# Driver code
if __name__ == '__main__':
	print('enter the number of activities')
	n=int(input())

	print('enter the start time and end time of activities')
	print('start time___end time')
	arr=[]
	for i in range(n):
		arr.append(list(map(int,input().split()))) #example list [[1,3],[2,4],[4,6]]

	printMaxActivities(arr,n)



