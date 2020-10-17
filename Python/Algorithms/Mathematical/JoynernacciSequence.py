#function to return the nth joynernacci term
def joynernacci(n):
    l = []
    l.append(0)    #0 at 0th index
    l.append(1)    #1 at 1st index
    l.append(1)    #2 at 2nd index
    
    #computing terms for index 3 to n
    for i in range(3,n+1):
        #for even terms
        if (i)%2==0:
            l.append(l[i-1] + l[i-2])
        #for odd terms
        else:
            l.append(abs((l[i-1]) - l[i-2]))
      
    #print the nth 
    print(l[n])
        
#call function for 5th term
joynernacci(5)

#call function for 12th term
joynernacci(12)
