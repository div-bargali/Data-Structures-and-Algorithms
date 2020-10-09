from Kruskal import Kruskals
def main():
    file = open("ewgraph1.txt", 'r')

    edges = []
    linenum = 0
    for line in file:
        #store each line in a tuple
        linenum += 1
        if linenum > 2:
            fields = line.split(" ")
            edges.append((float(fields[2]),int(fields[0]),int(fields[1])))

    file.close()
    print(edges[2])
    Kruskals(edges)
    
