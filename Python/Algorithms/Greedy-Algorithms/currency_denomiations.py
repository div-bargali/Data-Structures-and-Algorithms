# You enter the amount of money and the program returns the max changes of available denominations

# List for Denomination of Currency and its Type
denom = [2000,500,100,50,20,10,5,2,1]
ctype = lambda x: "coin(s)" if x in [1,2,5] else "note(s)"
def unique(l):
	# Just a Utility Function for Better Display of Results
	s = []
	for i in l:
		if i not in s:
			s.append(i)
	return s

tests = int(input("\nTest Cases : "))
for t in range(tests):
	val = int(input(f"\nCASE #{t+1} ::::: Enter Amount : "))
	change = []
	
	# Greedy Approach : Selecting Max Currency Value
	i = 0
	while val>0:
		while val<denom[i]:
			i+=1
		val-=denom[i]
		change.append(denom[i])

	# Display Results
	print(f"MIN Changes Required : {len(change)}")
	for i in unique(change):
		print(f"   {change.count(i)} {ctype(i)} of Rs. {i}")
