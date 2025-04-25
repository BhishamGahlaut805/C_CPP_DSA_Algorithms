#include<bits/stdc++.h>
using namespace std;

void DFS_VISIT(vector<vector<int>>&graph,int node,vector<int>&color,vector<int>&parent,int&time,vector<int>&discoveryTime,vector<int>&finishTime){
    color[node]=1; // Grey
    time++;
    discoveryTime[node]=time;
    cout<<node<<" ";
    for(int i=0;i<graph[node].size();i++){
        if(graph[node][i]==1 && color[i]==0){
            parent[i]=node;
            DFS_VISIT(graph,i,color,parent,time,discoveryTime,finishTime);
        }
    }
    color[node]=2; // Black
    time++;
    finishTime[node]=time;
}
void printTime(vector<int>&discoveryTime,vector<int>&finishTime){
    cout<<endl;
    cout<<"Discovery Time: ";
    for(int i=0;i<discoveryTime.size();i++){
        cout<<discoveryTime[i]<<" ";
    }
    cout<<endl;
    cout<<"Finish Time: ";
    for(int i=0;i<finishTime.size();i++){
        cout<<finishTime[i]<<" ";
    }
    cout<<endl;
}
// Function to implement DFS using Graph coloring
void DFS(vector<vector<int>>&graph){
    int n=graph.size();
    vector<int> color(n,0);
    vector<int> parent(n,-1);
    vector<int>discoveryTime(n,-1);
    vector<int> finishTime(n,-1);
    int time=0;
    for(int i=0;i<n;i++){
        if(color[i]==0){
        DFS_VISIT(graph,i,color,parent,time,discoveryTime,finishTime);
        }
    }
// printTime(discoveryTime,finishTime);
}

int main(){
    vector<vector<int>> graph = {{0, 1, 1, 0, 0},
                                 {1, 1, 0, 1, 1},
                                 {1, 0, 1, 1, 0},
                                 {0, 1, 1, 0, 1},
                                 {0, 0, 0, 1, 0}};
    DFS(graph);
}
