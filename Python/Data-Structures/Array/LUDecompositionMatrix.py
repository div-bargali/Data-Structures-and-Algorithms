#function for finding lower and upper decompositions
def LU(mat, n): 

    #initialising
	low = [[0 for x in range(n)] 
				for y in range(n)]
	up = [[0 for x in range(n)] 
				for y in range(n)] 
				
	#Decompose the matrix into Upper and Lower triangular matrix 
	for i in range(n): 

		#Upper Triangle
		for k in range(i, n): 

			#do sum of L(i, j) * U(j, k) 
			sum = 0
			for j in range(i): 
				sum += (low[i][j] * up[j][k]) 

			#finding U(i, k) 
			up[i][k] = mat[i][k] - sum

		#Lower Triangle 
		for k in range(i, n): 
			if (i == k): 
				low[i][i] = 1 # Diagonal 1 
			else: 

				#Sum of L(k, j) * U(j, i) 
				sum = 0
				for j in range(i): 
					sum += (low[k][j] * up[j][i]) 

				#finding L(k, i) 
				low[k][i] = int((mat[k][i] - sum) /
									up[i][i])


	print("Lower Triangular\t\tUpper Triangular") 

	#sow the result 
	for i in range(n): 
		
		#Lower triangle
		for j in range(n): 
			print(low[i][j], end = "\t")
		print("", end = "\t")

		#Upper triangle
		for j in range(n): 
			print(up[i][j], end = "\t")
		print("")

#set the required matrix 
mat = [[4, -1, 0], 
	[-1, 4, -1], 
	[0, -1, 4]]

#call the function with the matrix
LU(mat, 3)
