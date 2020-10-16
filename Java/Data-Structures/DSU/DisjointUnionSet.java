//CLean Disjoint Union Set implementation in Java, Optimized with adding Wieghted Disjoints

class DSU {
    int[] parent;
    int[] size;
    int count;
    //Count Variable will keep track of total number of connected components in the disjoint set
    public DSU(int N) {
        parent = new int[N];
        count = N;
        size = new int[N];
        for (int i = 0; i < N; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    public int find(int x) {
        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    public boolean union(int x, int y) { /// x and y should be provided in zero based
        int a = find(x);
        int b = find(y);
        if(a == b)
            return false;
        if(size[a] < size[b]){
        /// if the size of A subtree smaller than the b one we should merge the A to B
        /// so we make the parent of A is the B parent and increase the size of B subtree by the size of A subtree
            parent[a] = parent[b];
            size[b] += size[a];
        }else{
        /// if the size of B subtree smaller than the b one we should merge the B to A
        /// so we make the parent of B is the A parent and increase the size of A subtree by the size of B subtree
            parent[b] = parent[a];
            size[a] += size[b];
        }
        count--;
        //Each time we connect two component irrespective of there sizes, we will have only 1 single component left.
        //even the operations are large and set becomes dense this will still follow the motive
        return true;
    }
}
