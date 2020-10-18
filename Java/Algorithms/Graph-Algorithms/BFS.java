import java.util.*;

public class BFS {
    /**
     * Breadth-first-search.<br>
     * Based on: https://en.wikipedia.org/wiki/Breadth-first_search
     *
     * @param nodes the nodes in this graph
     * @param root  the root node
     * @param dest  the destination node
     * @return the destination node containing its parents, or null if not found
     */
    public static Node BreadthFirstSearch(Node[] nodes, Node root, Node dest) {
        Edge[] parent = new Edge[nodes.length];
        boolean[] discovered = new boolean[nodes.length];

        Queue<Node> q = new LinkedList<>();
        // Add the root node
        q.add(root);
        while (!q.isEmpty()) {
            Node v = q.remove();
            // If v is the destination node, return it
            if (v.equals(dest)) {
                // Set the path to v and return it
                v.parents = parent;
                return v;
            } else {
                // Go through all adjacent edges of v and add them to the queue if not visited
                for (Edge e : v.adjacentEdges) {
                    if (!discovered[e.dest]) {
                        parent[e.dest] = e;
                        discovered[e.dest] = true;
                        q.add(nodes[e.dest]);
                    }
                }
            }
        }

        // The destination node was not found, return null
        return null;
    }

    public static void main(String[] args) {
        // This will create a small graph, run BFS and print the path
        Edge[] edges = new Edge[6];
        edges[0] = new Edge(0, 1);
        edges[1] = new Edge(0, 2);
        edges[2] = new Edge(1, 3);
        edges[3] = new Edge(1, 4);
        edges[4] = new Edge(2, 5);
        edges[5] = new Edge(2, 6);

        Node[] nodes = new Node[7];
        for (int i = 0; i < nodes.length; i++) {
            nodes[i] = new Node(i);
        }

        nodes[0].addAll(edges[0], edges[1]);
        nodes[1].addAll(edges[2], edges[3]);
        nodes[2].addAll(edges[4], edges[5]);

        System.out.println(BreadthFirstSearch(nodes, nodes[0], nodes[5]));
    }

    /**
     * A node in a graph
     */
    public static class Node {
        public final int id;
        public final ArrayList<Edge> adjacentEdges;
        Edge[] parents;

        /**
         * Create a node
         *
         * @param id the id of the node
         */
        Node(int id) {
            this.id = id;
            this.adjacentEdges = new ArrayList<>();
            this.parents = null;
        }

        /**
         * Add edges to the node connecting to other nodes
         *
         * @param edges the edges to add
         */
        public void addAll(Edge... edges) {
            if (edges.length > 1)
                adjacentEdges.addAll(Arrays.asList(edges));
            else if (edges.length == 1)
                adjacentEdges.add(edges[0]);
        }

        @Override
        public String toString() {
            return "Node{ id: " + this.id + ", parents: " + Arrays.toString(this.parents) + "}";
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
         * Create an edge
         *
         * @param source the id of the source node
         * @param dest   the id of the destination node
         */
        public Edge(int source, int dest) {
            this.source = source;
            this.dest = dest;
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
            return "Edge{source: " + this.source + ", dest: " + this.dest + "}";
        }
    }
}
