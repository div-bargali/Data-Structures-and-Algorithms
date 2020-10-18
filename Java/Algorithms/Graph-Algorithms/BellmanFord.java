import java.util.Arrays;

/**
 * The bellman-ford algorithm to calculate the shortest paths in a Graph with negative weights
 */
public class BellmanFord {

    /**
     * Bellman-Ford algorithm to get the shortest distances to every node in {@code graph} from a start node.
     * Returns an empty array if the graph contains negative-weight cycles<br>
     * Based on: https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm<br>
     * Visualization tool used: https://www-m9.ma.tum.de/graph-algorithms/spp-bellman-ford/index_en.html<br>
     * Complexity: O(n³)
     *
     * @param graph  the input graph
     * @param source the source node
     * @return an array containing the shortest distance to every node from {@code source}, plus an array
     * containing the predecessor for each node.
     */
    private static int[][] impl(final int[][] graph, int source) {
        // Contains the shortest distance from source to each node
        int[] distance = new int[graph.length];

        // Contains the predecessor to each node
        int[] predecessor = new int[graph.length];

        for (int i = 0; i < graph.length; i++) {
            distance[i] = Integer.MAX_VALUE;
            predecessor[i] = -1;
        }

        distance[source] = 0;
        for (int i = 1; i < graph.length; i++) {
            for (int s = 0; s < graph.length; s++) {
                for (int d = 0; d < graph[s].length; d++) {
                    int weight = graph[s][d];
                    if (distance[s] != Integer.MAX_VALUE && distance[s] + weight < distance[d]) {
                        distance[d] = distance[s] + weight;
                        predecessor[d] = s;
                    }
                }
            }
        }

        // Check for negative-weight circles
        for (int u = 1; u < graph.length; u++) {
            for (int v = 0; v < graph.length; v++) {
                if (distance[u] + graph[u][v] < distance[v]) {
                    return new int[0][];
                }
            }
        }

        return new int[][]{distance, predecessor};
    }

    /**
     * Use the bellman-ford algorithm to calculate the shortest distance from and to every node in {@code inGraph}.<br>
     * Complexity: O(n⁴)
     *
     * @param inGraph the input graph matrix
     * @return the 'new' graph matrix, only containing the shortest paths to and from every node or an empty array
     * when {@code inGraph} contains negative-weight cycles
     */
    public static int[][] bellmanFord(final int[][] inGraph) {
        int[][] res = new int[inGraph.length][];
        for (int i = 0; i < inGraph.length; i++) {
            int[][] b_f_res = impl(inGraph, i);
            if (b_f_res.length == 2) {
                // Only fill in the distance, you may use b_f_res[1] to get the nodes visited to
                // get to a specific node
                res[i] = b_f_res[0];
            } else {
                return new int[0][];
            }
        }

        return res;
    }

    public static void main(String[] args) {
        // Print out the graph matrix with the shortest paths to each node of this graph
        System.out.println(Arrays.deepToString(bellmanFord(new int[][]{
                {0, 2, 2, 2, -1},
                {9, 0, 2, 2, -1},
                {9, 3, 0, 2, -1},
                {9, 3, 2, 0, -1},
                {9, 3, 2, 2, 0}
        })));
    }
}
