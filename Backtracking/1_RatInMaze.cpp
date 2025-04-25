#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &path,int n){
    if((newx>=0 && newx<n) && (newy>=0 && newy<n) && visited[newx][newy]!=1 && path[newx][newy]==1){
        return true;
    }
    else{
        return false;
    }
}
void solve(int x, int y, int n, vector<vector<int>> &path, vector<string> &ans, vector<vector<bool>> &visited, string way, bool &found)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(way);
        found = true;
        return;
    }

    visited[x][y] = true;

    // Possible moves: D, L, R, U
    int dx[] = {1, 0, 0, -1};           // Change in x for Down, Left, Right, Up
    int dy[] = {0, -1, 1, 0};           // Change in y for Down, Left, Right, Up
    char move[] = {'D', 'L', 'R', 'U'}; // Corresponding movement characters

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isSafe(newX, newY, visited, path, n) && !found)
        {
            solve(newX, newY, n, path, ans, visited, way + move[i], found);
        }
    }

    visited[x][y] = false; // Backtracking
}

void solve1(int x, int y, int n, vector<vector<int>> &path, vector<string> &ans, vector<vector<bool>> &visited, string way,bool &found)
{
    //Base condition
    if(x==n-1 && y==n-1){
        found=true;
        ans.push_back(way);
        return;
    }
    //4Movements-> D,L,R,U
    //down
    visited[x][y]=true;
    if(isSafe(x+1,y,visited,path,n) && !found){
        solve1(x+1,y,n,path,ans,visited,way+"D",found);
    }
    // left
    if (isSafe(x, y - 1, visited, path, n) && !found)
    {
        solve1(x, y - 1, n, path, ans, visited, way + "L",found);
    }
    //Up
    if (isSafe(x - 1, y, visited, path, n) && !found)
    {
        solve1(x - 1, y, n, path, ans, visited, way + "U",found);
    }

    //right
    if (isSafe(x , y+1, visited, path, n) && !found)
    {
        solve1(x , y+1, n, path, ans, visited, way + "R",found);
    }
    visited[x][y]=false;    //for backtracking
}

vector<string> searchMaze(vector<vector<int>> &path)
{
    vector<string>ans;
    int n=path.size();
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    string way="";
    //check if starting point is not 0
    if(path[0][0]==0){
        return ans;
        cout<<"No Path Found"<<endl;
    }
    bool found=false;
    solve(0,0,n,path,ans,visited,way,found);
    return ans;
}

int main(){
    vector<vector<int>> path = {{ 1, 0, 0, 0 }, { 1, 1, 0, 1 }, { 1, 1, 0, 0 }, { 0, 1, 1, 1 }};
    vector<string>ans=searchMaze(path);
    for(auto i:ans){
        cout<<i;
    }
    cout<<endl;
}
