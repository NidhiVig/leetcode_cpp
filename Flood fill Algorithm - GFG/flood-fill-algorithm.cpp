//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void dfs(int row, int col, int initial, vector<vector<int>>& image, vector<vector<int>>& ans, int newColor,int n, int m,
    vector<int>& delr, vector<int>& delc){
        ans[row][col] = newColor;
        for(int i = 0;i<4;i++){
            int r = row+delr[i], c = col+delc[i];
            if(r>=0 && c>=0 && r<n && c<m && image[r][c] == initial && ans[r][c] != newColor)
                dfs(r, c, initial, image, ans, newColor,n,m,delr,delc);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initial = image[sr][sc];
        vector<vector<int>> ans = image;
        int n = image.size(), m = image.back().size();
        vector<int> delr = {-1,0,1,0};
        vector<int> delc = {0,-1,0,1};
        dfs(sr,sc, initial, image, ans, newColor,n,m, delr, delc);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends