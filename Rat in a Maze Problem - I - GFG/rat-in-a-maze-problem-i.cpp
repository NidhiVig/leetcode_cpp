//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    void helper(vector<string>& ans, string& s,vector<vector<int>> &m, int n,int row,int col,vector<vector<bool>>& vis){
        if(row >= n || col>=n ||row<0 || col<0) return;
        if(vis[n-1][n-1] && row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        if(vis[row][col]==1){
            if(row+1<n && m[row+1][col]==1 && vis[row+1][col]==0){
                s += 'D';
                vis[row+1][col]=1;
                helper(ans,s,m,n,row+1,col,vis);
                vis[row+1][col]=0;
                s.pop_back();
            }
            if(row-1>=0 && m[row-1][col] && vis[row-1][col] == 0){
                s += 'U';
                vis[row-1][col] = 1;
                helper(ans,s,m,n,row-1,col,vis);
                vis[row-1][col] = 0;
                s.pop_back();
            }
            if(col+1<n && m[row][col+1] && vis[row][col+1] == 0){
                s += 'R';
                vis[row][col+1] = 1;
                helper(ans,s,m,n,row,col+1,vis);
                vis[row][col+1] = 0;
                s.pop_back();
            }
            if(col-1>= 0&& m[row][col-1] && vis[row][col-1] == 0){
                s += 'L';
                vis[row][col-1] = 1;
                helper(ans,s,m,n,row,col-1,vis);
                vis[row][col-1] = 0;
                s.pop_back();
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(!m[0][0]) return ans;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        string s ="" ;
        vis[0][0] =1 ;
        helper(ans, s, m, n,0,0, vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends