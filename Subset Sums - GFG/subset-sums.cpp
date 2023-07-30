//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    void helper(vector<int>& arr,int N,int sum, int idx, vector<int>& ans){
        if(idx == N) ans.push_back(sum);
        if(idx>N) return;
        helper(arr,N,sum+arr[idx],idx+1,ans);
        helper(arr,N,sum,idx+1,ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        helper(arr,N,0,0,ans);
        return ans;
        // int n = pow(2,N);
        // vector<int> ans;
        // for(int i = 0;i<n;i++){
        //     int s=0;
        //     for(int j = 0;j<N;j++){
        //         if(i&(1<<j)) s+=arr[j];
        //     }
        //     ans.push_back(s);
        // }
        // return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends