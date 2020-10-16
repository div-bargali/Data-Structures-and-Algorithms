// This passed Course Schedule in Leetcode

    bool dfs(vector<vector<int>>& g, vector<bool>& todo, vector<bool>& done, int node) {
        if (todo[node]) {
            return true; // There is cycle
        }
        if (done[node]) {
            return false; // No cycle here
        }
        todo[node] = done[node] = true; // Mark current as todo
        for (int v : g[node]) { // Visit all neighbors
            if (dfs(g, todo, done, v)) {
                return true;
            }
        }
        todo[node] = false; // Done visiting all neighbors, mark current as not todo
        return false; // No cycle here
    }
    
    bool hasCycle(int n, vector<vector<int>>& pairs) { // ex. [0,1] in pairs means 1 is a prerequisite of 0 (1 -> 0)
        vector<vector<int>> graph(n);  // Adjacency list
        for(auto p: pairs) {
            graph[p[1]].push_back(p[0]); // p[1] is a prerequisite of p[0]
        }
        
        vector<bool> todo(n, false), done(n, false);
       // we start from a node and keep visiting its neighbors. If we get to another "todo" node, there is cycle. If it is done (already visited in a prev recursion stack), stop

        for (int i = 0; i < n; i++) {
            if (!done[i] && dfs(graph, todo, done, i)) {
                return true; // There is cycle
            }
        }
        return false; // no cycle

    }
