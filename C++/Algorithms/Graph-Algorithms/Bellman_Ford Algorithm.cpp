/*
* This program is a program to find the shortest path through BellmanFord algorithm by receiving graph size and each data in matrix form.

I will explain how to use the main function below.
First, the size of the metrics is input. And enter all the parameters of the matrix. If the input value is 0, there is no connection.
Finally, enter the vertex to start the search and the end vertex. Then the distance and passing vertices are printed out.

ex)
5

0 6 13 0 0
0 0 5 6 0
2 0 0 7 4
0 6 0 0 3
0 0 5 2 0

0 3

result : 12
vertex : 0 1 3
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define IN_FINITY 999999
#define visited true
#define unvisited false
using namespace std;

class Edge
{
private:
    // the key of this edge
    int m_key;
    // the weight of this edge
    int m_weight;
    // the next pointer for the linked list of the edges
    Edge* m_pNext;

public:
    Edge(int key, int weight)
    {
        m_key = key;
        m_weight = weight;
        m_pNext = NULL;
    }

    void SetNext(Edge* pNext) { m_pNext = pNext; }
    int GetKey() const { return m_key; }
    int GetWeight() const { return m_weight; }
    Edge* GetNext() const { return m_pNext; }
};

class Vertex
{
private:
    // the key of this vertex
    int m_key;
    // the number of the edges from this vertex to others
    int m_size;
    // the head pointer for the linked list of the edges
    Edge* m_pEHead;
    // the next pointer for the linked list of the vertics
    Vertex* m_pNext;

public:
    Vertex(int key)
    {
        m_key = key;
        m_size = 0;
        m_pEHead = NULL;
        m_pNext = NULL;
    }

    void SetNext(Vertex* pNext) { m_pNext = pNext; }
    int GetKey() const { return m_key; }
    Vertex* GetNext() const { return m_pNext; }
    int Size() const { return m_size; }
    Edge* GetHeadOfEdge() const { return m_pEHead; }

    void AddEdge(int edgeKey, int weight)   //add edge in sorted
    {
        Edge* newedge = new Edge(edgeKey, weight);
        m_size++;
        if (m_pEHead == NULL)
        {
            m_pEHead = newedge;
            return;
        }

        Edge* cur = m_pEHead;
        Edge* before = NULL;
        while (cur != NULL)
        {
            before = cur;
            cur = cur->GetNext();
            if (cur && cur->GetKey() >= edgeKey)
                break;
        }
        newedge->SetNext(before->GetNext());
        before->SetNext(newedge);
    }
};


class Graph
{
private:
    // the head pointer for the linked list of the vertics
    Vertex* m_pVHead;
    // the number of the vertics
    int m_vSize;

public:
    Graph()
    {
        m_pVHead = NULL;
        m_vSize = 0;
    }

    /// add vertex with vertexNum at the end of the linked list for the vertics
    void AddVertex(int vertexKey)
    {
        Vertex* newvertex = new Vertex(vertexKey);
        m_vSize++;
        Vertex* cur = m_pVHead;
        Vertex* before = NULL;
        if (m_pVHead == NULL)
        {
            m_pVHead = newvertex;
            return;
        }
        else
        {
            while (cur != NULL)
            {
                before = cur;
                cur = cur->GetNext();
                if (cur && cur->GetKey() > vertexKey)
                    break;
            }
            newvertex->SetNext(before->GetNext());
            before->SetNext(newvertex);
        }
    }

    /// add edge from the vertex which the number is startVertexKey to the vertex which the number is endVertexKey
    void AddEdge(int startVertexKey, int endVertexKey, int weight)
    {
        Vertex* dest = FindVertex(startVertexKey);
        dest->AddEdge(endVertexKey, weight);
    }

    /// get the vertex which the key is vertexNum
    Vertex* FindVertex(int key)
    {
        Vertex* cur = m_pVHead;
        while (cur != NULL)
        {
            if (cur->GetKey() == key)
                return cur;
            cur = cur->GetNext();
        }
        return nullptr;
    }

    /// get the number of the vertics
    int Size() const { return m_vSize; }

    /// print out the graph as matrix form
    void Print()
    {
        Vertex* cur = m_pVHead;
        Edge* temp = NULL;
        // while (cur != NULL)
        for (int i = 0; i < m_vSize; i++)
        {
            temp = cur->GetHeadOfEdge();
            //while (temp!=NULL)
            for (int j = 0; j < m_vSize; j++)
            {
                if (temp && temp->GetKey() == j)
                {
                    cout << temp->GetWeight() << " ";
                    temp = temp->GetNext();
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
            cur = cur->GetNext();
        }
    }

    /// find the shortest path from startVertexKey to endVertexKey with Bellman-Ford
    std::vector<int> FindShortestPathBellmanFord(int startVertexKey, int endVertexKey)
    {
        vector<int> s(m_vSize, unvisited);
        vector<int> dist(m_vSize, IN_FINITY);
        vector<int> prev(m_vSize, IN_FINITY);
        Vertex* cur = m_pVHead;
        Edge* curedge = NULL;
        queue<pair<int, int>> q;

        //find start edge
        while (cur != NULL)
        {
            if (cur->GetKey() == startVertexKey)
                break;
            cur = cur->GetNext();
        }

        curedge = cur->GetHeadOfEdge();
        dist[startVertexKey] = 0;
        for (int i = 0; i < m_vSize; i++)
        {
            if (curedge && curedge->GetKey() == i)
            {
                dist[i] = curedge->GetWeight();
                prev[i] = cur->GetKey();
                curedge = curedge->GetNext();
            }
        }

        for (int k = 2; k <= m_vSize - 1; k++)
        {
            cur = m_pVHead;
            for (int w = 0; w < m_vSize; w++)   //w middle vertex
            {
                curedge = cur->GetHeadOfEdge();
                for (int v = 0; v < m_vSize; v++)   //v end vertex
                {
                    if (w == startVertexKey)
                        break;
                    if (curedge && curedge->GetKey() == v)
                    {
                        dist[v] = min(dist[v], dist[w] + curedge->GetWeight());
                        prev[v] = (dist[v] < dist[w] + curedge->GetWeight()) ? prev[v] : w;
                        curedge = curedge->GetNext();
                    }
                }
                cur = cur->GetNext();
            }
        }
        cout << "dist:" << dist[endVertexKey] << endl;
        return prev;
    }


};

int main(void)
{
    Graph g;
    int size;
    int data;
    cout << "size:";    //input matrix size
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        g.AddVertex(i);
        for (int j = 0; j < size; j++)
        {
            cin >> data;        //input matrix data
            if (data != 0) //0 is unconnected
                g.AddEdge(i, j, data);
        }
    }
    g.Print();

    int startVertexKey, endVertexKey;
    cout << "startVertexKey, endVertexKey" << endl;     //input start vertex, end vertex
    cin >> startVertexKey >> endVertexKey;
    vector<int> result = g.FindShortestPathBellmanFord(0, 3);
    int temp;
    stack<int> s;
    s.push(endVertexKey);
    temp = result[endVertexKey];
    s.push(temp);
    while (true)
    {
        temp = result[temp];
        s.push(temp);
        if (temp == startVertexKey)
            break;
    }

    cout << "vertex : ";
    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }
}