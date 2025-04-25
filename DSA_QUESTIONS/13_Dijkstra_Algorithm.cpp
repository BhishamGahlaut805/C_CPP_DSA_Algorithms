#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
            vector<int> dist(V, INT_MAX);
            dist[S] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, S});
            while(!pq.empty()) {
                int u = pq.top().second;
                pq.pop();
                for(auto it : adj[u]) {
                    int v = it[0];
                    int weight = it[1];
                    if(dist[v] > dist[u] + weight) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        }
};

int main(){
    Solution sol;
    vector<vector<int>> adj[5]={{{2,3},{1,10}},{{2,1},{3,2}},{{1,4},{3,8},{4,2}},{{4,7}},{{3,9}}};
    vector<int> ans = sol.dijkstra(5, adj, 0);
    cout<<"Single-Source Shortest Path starting with first node : ";
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

//T.C: O(E*log(V))  ->using binary min heap
