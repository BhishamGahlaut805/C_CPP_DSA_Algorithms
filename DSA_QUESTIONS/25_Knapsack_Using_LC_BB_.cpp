#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Structure which store weight and corresponding value
struct item
{
    float weight;
    int val;

};

// structure storing information of decision
struct node
{
    int level;
    int profit;
    int bound;
    float weight;
    vector<int> path;
};

// Sort each item according to val/weight ratio
bool cmp(item a, item b)
{
    double r1 = (double)a.val / a.weight;
    double r2 = (double)b.val / b.weight;
    return r1 > r2;
}

// Returns bound of profit in subtree rooted with Node u(Using Greedy Method)
int bound(node u, int n, int W, item arr[])
{
    if (u.weight >= W)
    {
        return 0;
    }
    int profit_bound = u.profit;

    int j = u.level + 1;
    int totalweight = u.weight;

    while ((j < n) && (totalweight + arr[j].weight <= W))
    {
        totalweight += arr[j].weight;
        profit_bound += arr[j].val;
        j++;
    }

    // Include last item Partially if k!=n
    if (j < n)
    {
        profit_bound += (W - totalweight) * arr[j].val / arr[j].weight;
    }
    return profit_bound;
}

// Returns max profit We can Get with Capacity W
int knapsack(int W, item arr[], int n)
{
    sort(arr, arr + n, cmp);

    queue<node> Q;
    node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    u.path.clear();
    Q.push(u);

    int maxProfit = 0;
    vector<int> bestPath;

    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;

        // Include current item
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].val;
        v.path = u.path;
        v.path.push_back(v.level);

        if (v.weight <= W && v.profit > maxProfit)
        {
            maxProfit = v.profit;
            bestPath = v.path;
        }

        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);

        // Exclude current item
        v.weight = u.weight;
        v.profit = u.profit;
        v.path = u.path;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    cout << "Items included (0-based index): ";
    for (int idx : bestPath){
        cout << idx << " "; }
    cout << endl;

    return maxProfit;
}

int main()
{
    int W = 10;
    item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    cout << "Maximum possible profit = "
         << knapsack(W, arr, 5);

    return 0;
}


