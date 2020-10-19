import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Objects;
import java.util.Queue;

public class FordFulkerson {
    /**
     * Ford-Fulkerson Algorithm for calculating max flow in a Graph.<br>
     * Based on (this is the Edmonds-Karp Algorithm, which is basically the Ford-Fulkerson Algorithm):<br>
     * https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm<br>
     * See also: https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm
     *
     * @param nodes the nodes of this graph
     * @param root  the root (source) node
     * @param dest  the destination (sink) node
     * @return the max flow of this Graph
     */
    public static int fordFulkerson(final Node[] nodes, final Node root, final Node dest) {
        // Initialize the max flow to zero
        int flow = 0;
        Edge[] pred;
        // Run this as long as an augmenting path is found
        do {
            // Run a breadth-first-search on the graph, which is defined by the edmonds-karp
            // algorithm. You could also use any other search as a depth-first-search
            // for the ford-fulkerson algorithm.
            Queue<Node> q = new LinkedList<>();
            // Add the root node
            q.add(root);
            // Set the predecessor array
            pred = new Edge[nodes.length];

            // Basic BFS
            while (!q.isEmpty()) {
                Node cur = q.remove();
                for (Edge e : cur.adjacentEdges) {
                    // Only visit the destination node of e, if it has no predecessor (there's no path to it),
                    // the destination node of e is not the root node and e still has capacity left.
                    if (pred[e.dest] == null && e.dest != root.id && e.capacity > e.flow) {
                        pred[e.dest] = e;
                        q.add(nodes[e.dest]);
                    }
                }
            }

            // If a path is found to the destination node, we can start
            // calculating the max flow for this path.
            if (pred[dest.id] != null) {
                // Initialize the flow through this path to infinity, well,
                // or, at least, to a very big number.
                int df = Integer.MAX_VALUE;

                // The flow on this path is the min (remaining) flow on this path, or,
                // to be more precise, the flow of the edge with the least amount
                // of (remaining) flow on this path.
                for (Edge e = pred[dest.id]; e != null; e = pred[e.source]) {
                    // df is the min of df and the remaining flow of e, which is its
                    // capacity minus the flow already 'used' of the edge e
                    df = Math.min(df, e.capacity - e.flow);
                }

                // Set the new flow for each edge and the reverse flow for their reverse edge
                for (Edge e = pred[dest.id]; e != null; e = pred[e.source]) {
                    e.flow = e.flow + df;
                    e.reverse.flow = e.reverse.flow - df;
                }

                // Add the flow through this path to the max flow
                flow += df;
            }
        } while (pred[dest.id] != null);

        // Return the max flow
        return flow;
    }

    /**
     * Convert a graph with one entry and one exit node to a node array.<br>
     * Complexity: O(n²)
     *
     * @param graph the graph to convert
     * @return the resulting node array
     */
    private static Node[] graphToNodes(final int[][] graph) {
        // Create the node list and initialize it
        Node[] nodes = new Node[graph.length];
        for (int i = 0; i < nodes.length; i++) {
            nodes[i] = new Node(i);
        }

        // Create the edges connecting each node
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[i].length; j++) {
                Edge a = new Edge(i, j, graph[i][j]);
                // b does not really exist, it is just needed as a reverse edge for a
                Edge b = new Edge(j, i, 0);

                // Set the reverse edges
                a.reverse = b;
                b.reverse = a;

                // Add the edges to the source and sink nodes
                nodes[i].adjacentEdges.add(a);
                nodes[j].adjacentEdges.add(b);
            }
        }

        return nodes;
    }

    public static void main(String[] args) {
        // Integer.MAX_VALUE is stored in M
        final int M = Integer.MAX_VALUE;

        // Convert the graph to a node list. This graph has a max flow of 16.
        Node[] nodes = graphToNodes(new int[][]{
                {0, M, M, 0, 0, 0, 0, 0},
                {0, 0, 0, 4, 6, 0, 0, 0},
                {0, 0, 0, 5, 2, 0, 0, 0},
                {0, 0, 0, 0, 0, 4, 4, 0},
                {0, 0, 0, 0, 0, 6, 6, 0},
                {0, 0, 0, 0, 0, 0, 0, M},
                {0, 0, 0, 0, 0, 0, 0, M},
                {0, 0, 0, 0, 0, 0, 0, 0}
        });

        // Run the ford-fulkerson algorithm to calculate the max flow of the
        // Graph created earlier. Will print '16', as the max flow of the graph is 16.
        System.out.println(fordFulkerson(nodes, nodes[0], nodes[nodes.length - 1]));
    }

    /**
     * A node in a graph
     */
    public static class Node {
        /**
         * The id (index) of this node
         */
        public final int id;

        /**
         * The adjacent edges to this node
         */
        public final ArrayList<Edge> adjacentEdges;

        /**
         * Create a node
         *
         * @param id the id of the node
         */
        Node(int id) {
            this.id = id;
            this.adjacentEdges = new ArrayList<>();
        }

        @Override
        public String toString() {
            return "Node{ id: " + this.id + ", adjacentEdges: " + adjacentEdges + " }";
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Node node = (Node) o;
            return Objects.equals(this.id, node.id);
        }
    }

    /**
     * An edge connecting nodes
     */
    public static class Edge {
        /**
         * The id of the source node
         */
        public final int source;

        /**
         * The id of the destination node of this edge
         */
        public final int dest;

        /**
         * The reverse edge of this edge
         */
        public Edge reverse;

        /**
         * The flow on this edge
         */
        public int flow;
        /**
         * The capacity of this edge
         */
        public int capacity;

        /**
         * Create an edge
         *
         * @param source the id of the source node
         * @param dest   the id of the destination node
         */
        public Edge(int source, int dest, int capacity) {
            this.source = source;
            this.dest = dest;
            this.flow = 0;
            this.capacity = capacity;
            this.reverse = null;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Edge edge = (Edge) o;
            return Objects.equals(source, edge.source) && Objects.equals(dest, edge.dest);
        }

        @Override
        public String toString() {
            return "Edge{ source: " + this.source + ", dest: " + this.dest + ", capacity: " + this.capacity + " }";
        }
    }
}
