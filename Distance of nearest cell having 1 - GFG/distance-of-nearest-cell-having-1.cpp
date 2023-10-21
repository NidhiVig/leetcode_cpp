//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<bool>> vis(n,vector<bool>(m,0));
	    int delr[] = {-1,0,1,0};
	    int delc[] = {0,-1,0,1};
	    vector<vector<int> > ans(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>> q;
	    int dist = 0;
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<m;j++){
	            if(grid[i][j] == 1){
	                ans[i][j] = 0;
	                vis[i][j] = 1;
	                q.push({i,j});
	            }
	        }
	    }
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i<sz;i++){
                pair<int,int> p = q.front();
                q.pop();
                for(int ii = 0;ii<4;ii++){
                    int r = p.first+delr[ii], c = p.second+delc[ii];
                    if(r>=0 && r<n && c>=0 && c<m && !vis[r][c]){
                        ans[r][c] = min(ans[r][c],dist+1);
                        vis[r][c] = 1;
                        q.push({r,c});
                    }
                }
            }
            dist++;
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends