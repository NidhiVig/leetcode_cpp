//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    bool helper(int m, int n, int node,vector<int>& color, bool graph[101][101]){
        if(node == n) return true;
        for(int i = 1;i<=m;i++){
            bool flag = 1;
            for(int j = 0;j<n;j++){
                if(j!=node && graph[j][node] && color[j] == i) {
                    flag = 0;
                    break;
                }
            }
            if(flag){
                color[node] = i;
                if(helper(m,n,node+1,color,graph)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n+1,0);
        return helper(m,n,0,color,graph);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends