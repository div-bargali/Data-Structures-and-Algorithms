
class Graph:
    def __init__(self, v):
        self.V = v
        self.adj = [[] for i in range(v+1)]

    def addEdge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def bridge(self):
        vis, par = {}, {}
        low, disc = {}, {}
        bridge_lis = []
        self.node = 0
        
        for i in range(self.V+1): par[i] = -1

        for i in range(1, self.V + 1):
            if i not in vis:
                self.bridgeUtil(i, par, vis, low, disc, bridge_lis)

        del self.node
        return bridge_lis


    def bridgeUtil(self, i, par, vis, low, disc, bridge):
        self.node += 1
        low[i] = disc[i] = self.node
        vis[i] = True
        for child in self.adj[i]:
            if child not in vis:
                par[child] = i
                self.bridgeUtil(child, par, vis, low, disc, bridge)
                low[i] = min(low[i], low[child])

                if low[child] > disc[i]:
                    bridge.append((i, child))
                    
            elif par[i]!=child:
                low[i] = min(low[i], disc[child])

    def articulationPoint(self):
        par, vis = {}, {}
        low, disc = {}, {}
        self.node = 0
        all_points = []

        for i in range(self.V+1): par[i] = -1
        
        for i in range(1, self.V+1):
            if i not in vis:
                self.tmp = []
                self.children = 0
                self.APUtil(i, i, par, vis, low, disc)
                if self.children < 2:
                    if i in self.tmp:
                        self.tmp.remove(i)
                all_points.extend(self.tmp)
        return set(all_points)

    def APUtil(self, root, i, par, vis, low, disc):
        self.node += 1
        low[i] = disc[i] = self.node
        vis[i] = True
            
        for child in self.adj[i]:
            if child not in vis:
                if i == root:
                    self.children += 1
                par[child] = i
                self.APUtil(root, child, par, vis, low, disc)
                low[i] = min(low[i], low[child])

                ## Articulation Point found via bridge
                if low[child] > disc[i]:
                    self.tmp.append(i)

                ## Articulation Point found via cycle
                if low[child] == disc[i]:
                    self.tmp.append(i)
                    
            elif par[i] != child:
                low[i] = min(low[i], disc[child])
