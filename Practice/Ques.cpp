#include<bits/stdc++.h>
using namespace std;

// conventional->O(n)
int exp(int n,int p){
    int ans = 1;
    for (int i = 0; i < p;i++){
        ans *= n;
    }
    return ans;
}

//Divide and conquer O(log n)
int exp_DivideNconquer(int n,int p){
    // int ans = 0;
    if (p==0){
        return 1;
    }

    else{
        int temp=exp_DivideNconquer(n,p/2);
        if(p%2==0){
            return  temp* temp;
        }
        else{
            return temp * temp * n;
        }
    }
    return -1;
}
pair<int,int> maxi(vector<int> arr){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i:arr)
    {
        if(i>maxi){
            maxi = i;
        }
        else{
            mini = i;
        }
    }
    return {maxi,mini};
}

vector<vector<int>>Multiply(vector<vector<int>>&m1,vector<vector<int>>&m2){
    int n = m1.size();
    int m = m1[0].size();;
    int l = m2[0].size();

    vector<vector < int >> ans(n,vector<int>(l,0));
    for (int i = 0;i<n;i++){
        for (int j = 0; j < m;j++){
            for (int k = 0; k < l;k++){
                ans[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }
    return ans;
}
int main(){

    vector<vector<int>> m1 = {{1, -2, 3, -11}, {-3, 4, 6, -11}, {8, -9, 10, -11}, {8, -9, 10, -11}};
    vector<vector<int>> m2 = {{4, -5, 6, -11}, {6, 7, -8, -11}, {10, 11, -12, -11}, {8, -9, 10, -11}};
    vector<vector<int>> ans;

    ans = Multiply(m1, m2);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

//    cout<< exp_DivideNconquer(2, 3);
// vector<int> arr = {1, 4, 2, 42, 211};
// pair<int, int> ans = maxi(arr);
// cout << "Max " << ans.first << " Min " << ans.second;