
# Input Cases 
t = int(input("\nTotal Test Cases : "))
for i in range(1,t+1):
	print(f"\n------------  CASE #{i}  -------------")
	n = int(input("\nTotal Items  : "))
	m = int(input("Max Capacity : "))
	v = [int(i) for i in input("\nValues  : ").split(" ")]
	w = [int(i) for i in input("Weights : ").split(" ")]
	
	# Tabulation (DP) 
	dp = [[0 for x in range(m+1)] for x in range(n+1)] 
	for i in range(n+1):
		for j in range(m+1):
			if i == 0 or j == 0:
				dp[i][j] = 0
			elif w[i-1]<=j:
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1])
			else:
				dp[i][j] = dp[i-1][j]
	
	print(f"\nMax Value Picked : {dp[n][m]}")