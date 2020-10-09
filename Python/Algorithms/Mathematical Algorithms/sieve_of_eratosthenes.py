import sys
import math

#function prints prime numbers in a given range

def sieve(n):
	
	ar=[True for i in range(n+1)] #assume all are prime numbers where index is the number

	ar[0],ar[1]=False,False #1 is not prime and zero is not a natural number

	p=2 #starting with 2 as it is the first prime number

	while p*p<=n:

		if ar[p]==True:

			for i in range(p*p,n+1,p):
				ar[i]=False  #every number which is a multiple of p is not a prime number

		p+=1

	ans=[]

	for i in range(2,n+1):
		if ar[i]==True: #add the numbers in answer array and then return it
			ans.append(i)
	return ans


if __name__ == '__main__':
	print('enter the value of n')
	n=int(input())

	print('prime numbers lesser or equals to', n ,'are')
	print(sieve(n))






