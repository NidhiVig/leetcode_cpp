//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int time = 0;
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<int> delr = {-1,0,1,0};
        vector<int> delc = {0,-1,0,1};
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1) cnt++;
        while(!q.empty()){
            int sz = q.size();
            bool flag = 0;
            for(int i = 0;i<sz;i++){
                pair<int,int> p = q.front();
                q.pop();
                for(int ii = 0;ii<4;ii++){
                    int r = p.first+delr[ii], c = p.second+delc[ii];
                    if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1){
                        q.push({r,c});
                        grid[r][c] = 2;
                        flag = 1;
                        cnt--;
                    }
                }
            }
            if(!flag) break;
            time++;
        }
        // for(int i = 0;i<n;i++)
        //     for(int j = 0;j<m;j++)
        //         if(grid[i][j] == 1) time = -1;
        return cnt==0?time:-1;
        // TC: O(n*m)
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends