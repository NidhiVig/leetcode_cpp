//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    int n = s.length(),pow_set = pow(2,n)-1;
		    for(int i = 1 ; i<=pow_set;i++){
		        string str = "";
		        for(int j = 0;j<n;j++){
		            if(i&(1<<j)) str+=s[j];
		        }
		      //  cout<<str<<endl;
		        ans.push_back(str);
		    } 
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends