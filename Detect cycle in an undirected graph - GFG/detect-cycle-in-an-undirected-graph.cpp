//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(int node, vector<bool>& vis, vector<int>& parent, vector<int> adj[]){
        vis[node] = 1;
        for(int it: adj[node]){
            if(!vis[it]){
                parent[it] = node;
                // vis[it] = 1;
                if(dfs(it, vis, parent, adj)) return true;
            }
            else if(it!=parent[node]) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> parent(V,-1);
        vector<bool> vis(V,0);
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                // vis[i] = 1;
                bool ans = dfs(i, vis, parent, adj);
                if(ans) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends