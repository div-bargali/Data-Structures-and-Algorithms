class Node:

    def __init__(self, data, indexloc=None):
        self.data = data
        self.index = indexloc


class Graph:

    @classmethod
    def create_from_nodes(self, nodes):
        return Graph(len(nodes), len(nodes), nodes)

    def __init__(self, row, col, nodes=None):
        # set up an adjacency matrix
        self.adj_mat = [[0] * col for _ in range(row)]
        self.nodes = nodes
        for i in range(len(self.nodes)):
            self.nodes[i].index = i

    # Conncects from node1 to node2
    # Note row is source, column is destination
    # Updated to allow weighted edges (supporting dijkstra's alg)
    def connect_dir(self, node1, node2, weight=1):
        node1, node2 = self.get_index_from_node(node1), self.get_index_from_node(node2)
        self.adj_mat[node1][node2] = weight

    # Optional weight argument to support dijkstra's alg
    def connect(self, node1, node2, weight=1):
        self.connect_dir(node1, node2, weight)
        self.connect_dir(node2, node1, weight)

    # Get node row, map non-zero items to their node in the self.nodes array
    # Select any non-zero elements, leaving you with an array of nodes
    # which are connections_to (for a directed graph)
    # Return value: array of tuples (node, weight)
    def connections_from(self, node):
        node = self.get_index_from_node(node)
        return [(self.nodes[col_num], self.adj_mat[node][col_num]) for col_num in range(len(self.adj_mat[node])) if
                self.adj_mat[node][col_num] != 0]

    # Map matrix to column of node
    # Map any non-zero elements to the node at that row index
    # Select only non-zero elements
    # Note for a non-directed graph, you can use connections_to OR
    # connections_from
    # Return value: array of tuples (node, weight)
    def connections_to(self, node):
        node = self.get_index_from_node(node)
        column = [row[node] for row in self.adj_mat]
        return [(self.nodes[row_num], column[row_num]) for row_num in range(len(column)) if column[row_num] != 0]

    def print_adj_mat(self):
        for row in self.adj_mat:
            print(row)

    def node(self, index):
        return self.nodes[index]

    def remove_conn(self, node1, node2):
        self.remove_conn_dir(node1, node2)
        self.remove_conn_dir(node2, node1)

    # Remove connection in a directed manner (nod1 to node2)
    # Can accept index number OR node object
    def remove_conn_dir(self, node1, node2):
        node1, node2 = self.get_index_from_node(node1), self.get_index_from_node(node2)
        self.adj_mat[node1][node2] = 0

        # Can go from node 1 to node 2?

    def can_traverse_dir(self, node1, node2):
        node1, node2 = self.get_index_from_node(node1), self.get_index_from_node(node2)
        return self.adj_mat[node1][node2] != 0

    def has_conn(self, node1, node2):
        return self.can_traverse_dir(node1, node2) or self.can_traverse_dir(node2, node1)

    def add_node(self, node):
        self.nodes.append(node)
        node.index = len(self.nodes) - 1
        for row in self.adj_mat:
            row.append(0)
        self.adj_mat.append([0] * (len(self.adj_mat) + 1))

    # Get the weight associated with travelling from n1
    # to n2. Can accept index numbers OR node objects
    def get_weight(self, n1, n2):
        node1, node2 = self.get_index_from_node(n1), self.get_index_from_node(n2)
        return self.adj_mat[node1][node2]

    # Allows either node OR node indices to be passed into
    def get_index_from_node(self, node):
        if not isinstance(node, Node) and not isinstance(node, int):
            raise ValueError("node must be an integer or a Node object")
        if isinstance(node, int):
            return node
        else:
            return node.index

    def dijkstra(self, node):
        # Get index of node (or maintain int passed in)
        nodenum = self.get_index_from_node(node)
        # Make an array keeping track of distance from node to any node
        # in self.nodes. Initialize to infinity for all nodes but the
        # starting node, keep track of "path" which relates to distance.
        # Index 0 = distance, index 1 = node hops
        dist = [None] * len(self.nodes)
        for i in range(len(dist)):
            dist[i] = [float("inf")]
            dist[i].append([self.nodes[nodenum]])

        dist[nodenum][0] = 0
        # Queue of all nodes in the graph
        # Note the integers in the queue correspond to indices of node
        # locations in the self.nodes array
        queue = [i for i in range(len(self.nodes))]
        # Set of numbers seen so far
        seen = set()
        while len(queue) > 0:
            # Get node in queue that has not yet been seen
            # that has smallest distance to starting node
            min_dist = float("inf")
            min_node = None
            for n in queue:
                if dist[n][0] < min_dist and n not in seen:
                    min_dist = dist[n][0]
                    min_node = n

            # Add min distance node to seen, remove from queue
            queue.remove(min_node)
            seen.add(min_node)
            # Get all next hops
            connections = self.connections_from(min_node)
            # For each connection, update its path and total distance from
            # starting node if the total distance is less than the current distance
            # in dist array
            for (node, weight) in connections:
                tot_dist = weight + min_dist
                if tot_dist < dist[node.index][0]:
                    dist[node.index][0] = tot_dist
                    dist[node.index][1] = list(dist[min_node][1])
                    dist[node.index][1].append(node)
        return dist


def main():
    a = Node("A")
    b = Node("B")
    c = Node("C")
    d = Node("D")
    e = Node("E")
    f = Node("F")

    graph = Graph.create_from_nodes([a, b, c, d, e, f])

    graph.connect(a, b)
    graph.connect(a, c)
    graph.connect(a, e)
    graph.connect(b, c)
    graph.connect(b, d)
    graph.connect(c, d)
    graph.connect(c, f)
    graph.connect(d, e)

    graph.print_adj_mat()

    print()

    w_graph = Graph.create_from_nodes([a, b, c, d, e, f])

    w_graph.connect(a, b, 5)
    w_graph.connect(a, c, 10)
    w_graph.connect(a, e, 2)
    w_graph.connect(b, c, 2)
    w_graph.connect(b, d, 4)
    w_graph.connect(c, d, 7)
    w_graph.connect(c, f, 10)
    w_graph.connect(d, e, 3)

    w_graph.print_adj_mat()

    print([(weight, [n.data for n in node]) for (weight, node) in w_graph.dijkstra(a)])


if __name__ == "__main__":
    main()

