n = int(input("Enter a number you want to check:"))

def digisum(n):
    return sum([int(s) for s in str(n)])

def getfactors(n):
    k=2
    result=[]
    while k ** 2 <= n:
        while n%k==0:
            result.append(k)
            n = n // k
        k = k +1
    if n > 1:
        result.append(n)
    return result


if digisum(n)==sum([digisum(i) for i in getfactors(n)]):
    print('It is a smith number')
    
else:
    print('It is not a smith number')
    