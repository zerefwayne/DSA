#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int dest;
    int weight;

    Node(int _dest, int _weight)
    {
        this->dest = _dest;
        this->weight = _weight;
    }

    bool operator==(const Node &b) const
    {
        return this->dest == b.dest;
    }

    bool operator<(const Node &b) const
    {
        return this->weight < b.weight;
    }

    bool operator>(const Node &b) const
    {
        return this->weight > b.weight;
    }
};

class Graph
{

public:
    vector<vector<Node>> adj;
    int V;

    Graph(int V)
    {
        this->V = V;
        this->adj.resize(this->V);
    }

    void addEdge(int src, int dest, int weight, bool isUnidirectional)
    {

        if (src >= 0 && src < V && dest >= 0 && dest < V && dest != src)
        {

            if (find(adj[src].begin(), adj[src].end(), Node(dest, -1)) == adj[src].end())
            {
                adj[src].emplace_back(Node(dest, weight));
            }

            if (isUnidirectional == false)
            {

                if (find(adj[dest].begin(), adj[dest].end(), Node(src, -1)) == adj[dest].end())
                {
                    adj[dest].emplace_back(Node(src, weight));
                }
            }
        }
    }

    void printGraph()
    {

        for (int i = 0; i < V; i++)
        {

            cout << i << "->";

            for (auto &vertex : adj[i])
            {

                cout << vertex.dest << "(" << vertex.weight << ")"
                     << "->";
            }

            cout << '\n';
        }

        cout << '\n';
    }

    void dijkstra(int source)
    {

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<int> distances(this->V, 99999);
        vector<bool> visited(this->V, false);
        unordered_map<int, int> parents;

        distances[source] = 0;
        parents[source] = -1;

        pq.emplace(Node(source, 0));

        while (!pq.empty())
        {

            Node minNode = pq.top();
            pq.pop();

            int u = minNode.dest;
            // visited[u] = true;
            cout << "Current: " << u << " Weight: " << distances[u] << '\n'
                 << '\n';

            for (auto &neighbour : adj[u])
            {

                cout << "Checking " << neighbour.dest << " with weight " << neighbour.weight << '\n';

                int v = neighbour.dest;
                int w = neighbour.weight;
                // if (visited[v])
                //     continue;

                if (distances[v] > distances[u] + w)
                {
                    cout << "Updating " << v << " " << distances[v] << " to " << distances[u] + w << '\n';
                    parents[v] = u;
                    distances[v] = distances[u] + w;
                    pq.emplace(Node(v, distances[v]));
                }
            }

            cout << '\n';
        }

        cout << "Source: " << source << '\n'
             << '\n';

        for (int i = 0; i < this->V; i++)
        {

            if (i == source)
                continue;

            cout << i << " " << distances[i] << " " << parents[i] << '\n';
        }

        cout << '\n';
    }
};

int main()
{

    Graph newGraph = Graph(5);

    newGraph.addEdge(0, 4, 9, false);
    newGraph.addEdge(4, 1, 2, false);
    newGraph.addEdge(1, 2, 5, false);
    newGraph.addEdge(2, 0, 6, false);
    newGraph.addEdge(0, 3, 2, false);
    newGraph.addEdge(3, 1, 3, false);

    newGraph.printGraph();

    newGraph.dijkstra(0);

    return 0;
}