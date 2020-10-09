from min_heap import MinHeap
from UnionFind import UnionFind
vertices = set()
def Kruskals(G):
    #put all the vertices into a set so that we don't have duplicates in the parent or rank arrays
    for i in G:
        x = UnionFind(len(vertices))
        if i[1] in vertices or i[2] not in vertices:
            vertices.add(i[2])
            x.makeset(i[2])
            print(vertices)
        if i[1] not in vertices or i[2] in vertices:
            vertices.add(i[1])
            x.makeset(i[1])
            print(vertices)
        if i[1] in vertices and i[2] in vertices:
            continue

        
