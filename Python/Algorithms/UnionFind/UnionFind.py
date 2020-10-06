
class UnionFind():
    def __init__(self, n):
        self.parent = []
        self.rank = []
        self.size = n
    def makeset(self,x):
        self.parent[x] = x
        self.rank[x]=0
    def find(self, x):
        while x != self.parent[x]:
            x = self.parent[x]
        return x
    def union(self,x,y):
        i = self.find(x)
        j = self.find(y)
        if i == j:
            return
        if rank[i] > rank[j]:
            parent[j] = i
        else:
            parent[i] = j
            if rank[i] == rank[j]:
                rank[j] = rank[j] + 1

        
