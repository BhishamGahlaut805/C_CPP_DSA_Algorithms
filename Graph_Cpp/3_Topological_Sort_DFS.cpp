#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.

//Fuction to perform DFS
void toplogicalSort(int v,vector<vector<int>>&edges,vector<bool>&visited,stack<int>&s){

    //Marking current node as visited true
    visited[v]=true;

    //then recur for the adjacent nodes
    for(int i:edges[v]){
        if(!visited[i]){
            toplogicalSort(i,edges,visited,s);
        }
    }
    //push current vertex into stack which stores the result
    s.push(v);
}

vector<int>toplogical(vector<vector<int>>&edges){
    int v=edges.size();
    stack<int>s;
    vector<bool>visited(v,false);

    for(int i=0;i<v;i++){
        if(!visited[i]){
            toplogicalSort(i,edges,visited,s);
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main(){
    vector<vector<int>> edges = {{1}, {2}, {}, {1, 2}};
    vector<int>ans=toplogical(edges);

    for (auto node : ans)
    {
        cout << node << " ";
    }
    cout << endl;
}