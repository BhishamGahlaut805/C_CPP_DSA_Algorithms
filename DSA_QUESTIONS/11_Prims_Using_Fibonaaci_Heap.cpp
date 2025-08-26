#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>
using namespace std;

// Fibonacci Heap Node
struct FibNode
{
    int key, vertex;
    FibNode *parent, *child, *left, *right;
    int degree;
    bool marked;

    FibNode(int v, int k) : vertex(v), key(k), degree(0), marked(false), parent(nullptr), child(nullptr)
    {
        left = right = this;
    }
};

// Fibonacci Heap
class FibonacciHeap
{
private:
    FibNode *min;
    int n;
    unordered_map<int, FibNode *> nodes; // vertex -> node

public:
    FibonacciHeap() : min(nullptr), n(0) {}

    bool empty()
    {
        return min == nullptr;
    }

    void insert(int vertex, int key)
    {
        FibNode *node = new FibNode(vertex, key);
        nodes[vertex] = node;
        min = meld(min, node);
        n++;
    }

    FibNode *extractMin()
    {
        FibNode *z = min;
        if (z)
        {
            if (z->child)
            {
                FibNode *child = z->child;
                do
                {
                    FibNode *next = child->right;
                    child->parent = nullptr;
                    min = meld(min, child);
                    child = next;
                } while (child != z->child);
            }

            removeFromList(z);
            if (z == z->right)
            {
                min = nullptr;
            }
            else
            {
                min = z->right;
                consolidate();
            }
            nodes.erase(z->vertex);
            n--;
        }
        return z;
    }

    void decreaseKey(int vertex, int newKey)
    {
        FibNode *x = nodes[vertex];
        if (!x || newKey > x->key)
            return;

        x->key = newKey;
        FibNode *y = x->parent;
        if (y && x->key < y->key)
        {
            cut(x, y);
            cascadingCut(y);
        }

        if (x->key < min->key)
            min = x;
    }

    bool contains(int vertex)
    {
        return nodes.find(vertex) != nodes.end();
    }

    int getKey(int vertex)
    {
        return nodes[vertex]->key;
    }

private:
    FibNode *meld(FibNode *a, FibNode *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        if (b->key < a->key)
            swap(a, b);

        // insert b into a's list
        b->left = a;
        b->right = a->right;
        a->right->left = b;
        a->right = b;

        return a;
    }

    void consolidate()
    {
        int D = static_cast<int>(log2(n)) + 1;
        vector<FibNode *> A(D, nullptr);

        vector<FibNode *> roots;
        FibNode *w = min;
        do
        {
            roots.push_back(w);
            w = w->right;
        } while (w != min);

        for (FibNode *w : roots)
        {
            FibNode *x = w;
            int d = x->degree;
            while (A[d])
            {
                FibNode *y = A[d];
                if (x->key > y->key)
                    swap(x, y);
                link(y, x);
                A[d] = nullptr;
                d++;
            }
            A[d] = x;
        }

        min = nullptr;
        for (FibNode *x : A)
        {
            if (x)
            {
                if (!min)
                {
                    x->left = x->right = x;
                    min = x;
                }
                else
                {
                    x->left = min;
                    x->right = min->right;
                    min->right->left = x;
                    min->right = x;
                    if (x->key < min->key)
                        min = x;
                }
            }
        }
    }

    void link(FibNode *y, FibNode *x)
    {
        removeFromList(y);
        y->left = y->right = y;
        y->parent = x;
        x->child = meld(x->child, y);
        x->degree++;
        y->marked = false;
    }

    void cut(FibNode *x, FibNode *y)
    {
        if (y->child == x)
        {
            if (x->right != x)
                y->child = x->right;
            else
                y->child = nullptr;
        }

        removeFromList(x);
        x->left = x->right = x;
        min = meld(min, x);
        x->parent = nullptr;
        x->marked = false;
        y->degree--;
    }

    void cascadingCut(FibNode *y)
    {
        FibNode *z = y->parent;
        if (z)
        {
            if (!y->marked)
                y->marked = true;
            else
            {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }

    void removeFromList(FibNode *x)
    {
        x->left->right = x->right;
        x->right->left = x->left;
    }
};

// Edge: { {u, v}, weight }
typedef vector<pair<pair<int, int>, int>> Graph;

Graph PrimsMst_Using_Fibonaaci(int n, int m, Graph &edges, int &minWt)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto e : edges)
    {
        int u = e.first.first;
        int v = e.first.second;
        int wt = e.second;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    FibonacciHeap fib;
    vector<bool> inMST(n + 1, false);
    vector<int> parent(n + 1, -1);

    fib.insert(1, 0); // Start from vertex 1
    for (int i = 2; i <= n; ++i)
        fib.insert(i, INT_MAX);

    Graph mst;
    minWt = 0;

    while (!fib.empty())
    {
        FibNode *minNode = fib.extractMin();
        int u = minNode->vertex;
        int wt = minNode->key;
        inMST[u] = true;
        minWt += wt;

        if (parent[u] != -1)
            mst.push_back({{parent[u], u}, wt});

        for (auto it : adj[u])
        {
            int v= it.first;
            int weight=it.second;
            if (!inMST[v] && fib.contains(v) && weight < fib.getKey(v))
            {
                fib.decreaseKey(v, weight);
                parent[v] = u;
            }
        }
    }

    return mst;
}

// Print MST and weight
void printMST(int n, int m, vector<pair<pair<int, int>, int>> &edges)
{
    int minWt = 0;
    vector<pair<pair<int, int>, int>> mst = PrimsMst_Using_Fibonaaci(n, m, edges, minWt);

    cout << "Minimum Spanning Tree Weight: " << minWt << endl;
    cout << "Edges in MST:\n";
    for (auto e : mst)
        cout << e.first.first << " -- " << e.first.second << " (Weight: " << e.second << ")\n";
}

int main()
{
    int n = 4, m = 4;
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 1}, {{2, 3}, 2}, {{3, 4}, 4}, {{4, 1}, 5}};
    printMST(n, m, edges);
    return 0;
}
