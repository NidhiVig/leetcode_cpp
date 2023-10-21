//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void dfs(int r, int c, vector<vector<char>>& mat, vector<vector<char>>& ans, vector<vector<bool>>& vis, 
    int n,int m, int delr[], int delc[]){
        vis[r][c] = true;
        ans[r][c] = 'O';
        for(int i = 0;i<4;i++){
            int rr = r+delr[i], cc = c+delc[i];
            if(rr>=0 && rr<n && cc>=0 && cc<m && !vis[rr][cc] && mat[rr][cc] == 'O'){
                dfs(rr,cc,mat, ans,vis,n,m,delr,delc);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        int delr[] = {-1,0,1,0}, delc[] = {0,-1,0,1};
        for(int i = 0;i<m;i++){
            if(mat[0][i] == 'O' && !vis[0][i]) dfs(0,i,mat,ans,vis,n,m,delr,delc);
            if(mat[n-1][i] == 'O' && !vis[n-1][i]) dfs(n-1,i,mat, ans,vis,n,m,delr,delc);
        }
        for(int i = 0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0]) dfs(i,0,mat,ans,vis,n,m,delr,delc);
            if(mat[i][m-1] == 'O' && !vis[i][m-1]) dfs(i,m-1,mat,ans, vis,n,m,delr,delc);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends