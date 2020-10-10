'''
	Given 2 strings we have to find the longest common subsequence. 

	First we find the length of the longest common subsequence. In order to do so we divide the problem into simpler sub-problems.
	We find the length of the longest subsequence of "b" and "a", then of "b" and "ab" and so on. 
	So dp[i][j] = length of lcs if s1[0:i] and s2[0:j] which depends on dp[i-1][j] and dp[i][j-1].
	A dp table for s1 = "abcd" and s2 = "baca" is shown below.

	  | 0 a b c d
	--|----------
	0 | 0 0 0 0 0 
	b | 0 0 1 1 1
	a | 0 1 1 1 1
	c | 0 1 1 2 2
	a | 0 1 1 2 2

	Here the lowest rigth most value is the length of the longest sub sequence of s1 and s2.
	The space complexity for this is O(m*n) m being the lenght of s1 and n being the length of s2.
	Populating the dp matrix is O(mn) time complexity.

	Now to find one of the lcs (there can be more that 1) we use an algorithm explained here in the link below.
  (https://en.wikipedia.org/wiki/Longest_common_subsequence_problem#Reading_out_a_LCS)
  This algorithm traverses the dp matric hence the time complexit of the whole process is still O(mn).

'''


# function to find the longest common subsequence of two strings s2 and s2
# the function is not case dependent
# we are using a matrix to store results of subproblems 
# hence it has a space complexity of O(n*m)
def longestCommonSubsequence(s1, s2):
	# change the strings into strictly lowercase or uppercase
	# we are doing this becase our algorithm does not depend on case
	s1 = s1.lower()
	s2 = s2.lower()
	m = len(s1)
	n = len(s2)

  # creating a matrix to store the results of sub problems
	dp = [[0 for i in range(n+1)] for i in range(m+1)]

	# the subproblem is finding the longest common subsequence of s1[0:i] with s2[0:j]
	# length of longest common subsequence will be in dp[m][n] 
	for i in range(1, m+1):
		for j in range(1, n+1):
			if s1[i-1] == s2[j-1]:
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1
			else:
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])

	return getLCS(dp, s1, s2)

def getLCS(dp, s1, s2):
	i = len(s1) 
	j = len(s2)
	k = dp[-1][-1] - 1
	s = [0 for i in range(k + 1)]

	while k >= 0 and i > 0 and j > 0:
		# if s[i-1] and s[j-1] are the same, it means that that letter is part of the subsequence
		if s1[i-1] == s2[j-1]:
			s[k] = s1[i-1]
			k -= 1
			i -= 1
			j -= 1
		# if they are not equal then we change path in the dp matrix 
		# our new path will be chosen by which of dp[i-1][j] and dp[i][j-1] is greater
		else:
			if dp[i-1][j] > dp[i][j-1]:
				i -= 1
			else:
				j -= 1

	return "".join(s)


# driver code
if __name__ == "__main__":
	s1 = ["abcd", "baca", "aa", ""]
	s2 = ["baca", "babca", "aa", ""]

	for i in range(len(s1)):
		print("For s1 = %s, s2 = %s, "%(s1[i], s2[i]))
		print("the longest common subsequence is:", longestCommonSubsequence(s1[i], s2[i]))
		print()

