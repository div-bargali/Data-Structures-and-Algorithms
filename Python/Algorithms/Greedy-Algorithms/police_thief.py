import sys

# Python3 program to find maximum 
# number of thieves caught 

# Returns maximum number of thieves 
# that can be caught. 
def policeThief(arr, n, k): 
	i = 0
	l = 0
	r = 0
	res = 0
	thi = [] 
	pol = [] 

	# store indices in list 
	while i < n: 
		if arr[i] == 'P': 
			pol.append(i) 
		elif arr[i] == 'T': 
			thi.append(i) 
		i += 1

	# track lowest current indices of 
	# thief: thi[l], police: pol[r] 
	while l < len(thi) and r < len(pol): 
		
		# can be caught 
		if (abs( thi[l] - pol[r] ) <= k): 
			res += 1
			l += 1
			r += 1
			
		# increment the minimum index 
		elif thi[l] < pol[r]: 
			l += 1
		else: 
			r += 1

	return res 

# Driver program 
if __name__=='__main__': 

	print('enter the array containing position of policeman and thief exa:["P","T","P"....]')
	arr=list(input().split())
	print('enter the max distance unit police can catch thief')
	k = int(input())
	n = len(arr) 
	print(("Maximum thieves caught: {}". 
		format(policeThief(arr, n, k)))) 


