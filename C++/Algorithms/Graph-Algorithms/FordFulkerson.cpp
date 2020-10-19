#include <iostream>
#include <vector>
#include <queue>

/**
 * A graph edge
 */
class Edge {
public:
    /**
     * Create an edge
     *
     * @param _source the id of the source node of this edge
     * @param _dest the id of the destination node of this edge
     * @param _capacity the capacity of this edge
     */
    Edge(int _source, int _dest, int _capacity);

    /**
     * Default destructor
     */
    ~Edge() = default;

    const int source;
    const int dest;
    const int capacity;

    /**
     * The reverse edge of this edge
     */
    Edge *reverse;

    /**
     * The flow on this edge
     */
    int flow;
};

/**
 * A node in a graph
 */
class Node {
public:
    /**
     * Create a node
     *
     * @param _id the id (index) of this node
     */
    explicit Node(int _id);

    /**
     * The node destructor. Deletes all adjacent edges of itself.
     */
    ~Node();

    const int id;
    std::vector<Edge *> adjacentEdges;
};

Edge::Edge(int _source, int _dest, int _capacity) : source(_source), dest(_dest), capacity(_capacity) {
    this->reverse = nullptr;
    this->flow = 0;
}

Node::Node(int _id) : id(_id), adjacentEdges() {}

Node::~Node() {
    // Delete every edge next to this node
    for (Edge *e : adjacentEdges) {
        delete e;
    }
}

/**
 * Convert a graph matrix to a node vector
 *
 * @param graph the graph matrix to convert
 * @return the resulting node vector
 */
std::vector<Node *> graphToNodes(const std::vector<std::vector<int>> &graph) {
    std::vector<Node *> nodes;
    // Resize to graph.size
    nodes.reserve(graph.size());

    // Fill in the nodes
    for (int i = 0; i < graph.size(); i++) {
        nodes.emplace_back(new Node(i));
    }

    // Set the edges
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            Edge *a = new Edge(i, j, graph[i][j]);
            // b does not really exist, it is just used as a reverse edge to a
            Edge *b = new Edge(j, i, 0);

            // Set the reverse edges
            a->reverse = b;
            b->reverse = a;

            nodes[i]->adjacentEdges.push_back(a);
            nodes[j]->adjacentEdges.push_back(b);
        }
    }

    return nodes;
}

int FordFulkerson(const std::vector<Node *> &nodes, Node *root, Node *dest) {
    // Set the initial flow to zero
    int flow = 0;
    // The predecessors to get the path travelled
    std::vector<Edge *> pred;

    // Do this as long as a path to dest is found
    do {
        std::queue<Node *> q;
        q.push(root);

        // Set pred to a vector the size of nodes.size with the objects initialized to nullptr
        pred = std::vector<Edge *>(nodes.size(), nullptr);

        // Standard BFS
        while (!q.empty()) {
            // Get the first element in the queue
            Node *cur = q.front();
            // Remove the first element in the queue
            q.pop();

            // Go through every adjacent edge of cur
            for (Edge *e : cur->adjacentEdges) {
                // Only visit the destination node of e, if it has no predecessor (there's no path to it),
                // the destination node of e is not the root node and e still has capacity left.
                if (pred[e->dest] == nullptr && e->dest != root->id && e->capacity > e->flow) {
                    pred[e->dest] = e;
                    q.push(nodes[e->dest]);
                }
            }
        }

        // If a path was found to the destination node, we can add the flow
        // of this path to the overall flow of the whole graph
        if (pred[dest->id] != nullptr) {
            // Initialize the flow through this path to a large value
            int df = INT_MAX;

            // Set the flow through this graph to the smallest amount of flow in the whole path
            for (Edge *e = pred[dest->id]; e != nullptr; e = pred[e->source]) {
                df = std::min(df, e->capacity - e->flow);
            }

            // Set the flow for each edge and their reverse edge
            for (Edge *e = pred[dest->id]; e != nullptr; e = pred[e->source]) {
                e->flow = e->flow + df;
                e->reverse->flow = e->reverse->flow - df;
            }

            // Add the flow of this path to the flow through the whole graph
            flow += df;
        }
    } while (pred[dest->id] != nullptr);

    // Return the flow
    return flow;
}

int main() {
    static const int M = INT_MAX;
    std::vector<Node *> nodes = graphToNodes(
            {
                    {0, M, M, 0, 0, 0, 0, 0},
                    {0, 0, 0, 4, 6, 0, 0, 0},
                    {0, 0, 0, 5, 2, 0, 0, 0},
                    {0, 0, 0, 0, 0, 4, 4, 0},
                    {0, 0, 0, 0, 0, 6, 6, 0},
                    {0, 0, 0, 0, 0, 0, 0, M},
                    {0, 0, 0, 0, 0, 0, 0, M},
                    {0, 0, 0, 0, 0, 0, 0, 0}
            }
    );

    printf("Result of Ford-Fulkerson algo (should be 16): %d", FordFulkerson(nodes, nodes[0], nodes[nodes.size() - 1]));

    // Clean up
    for (Node *n : nodes) {
        delete n;
        n = nullptr;
    }

    return 0;
}
