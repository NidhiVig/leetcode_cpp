//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis,int n,int m){
        queue<pair<int,int>> q;
        vector<int> r = {-1,0,1};
        vector<int> c = {-1,0,1};
        q.push({row,col});
        vis[row][col] = 1;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int i = 0;i<3;i++){
                for(int j = 0;j<3;j++){
                    int a = p.first+r[i], b = p.second+c[j];
                    if(a>=0 && b>=0 && a<n && b<m && !vis[a][b] && grid[a][b] == '1'){
                        vis[a][b] = 1;
                        q.push({a,b});
                    }
                }
            }
            
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid.back().size(),cnt = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,grid,vis,n,m);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends