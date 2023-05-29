//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> d, string p) {

        vector<string> v;
        for(int i=0;i<n;i++){
            string s=d[i],a="";
            for(int j=0;j<s.size();j++){
                if(s[j]>=65 && s[j]<=90){
                    a.push_back(s[j]);
                }
            }
            v.push_back(a);
        }
        vector<string> ans;
        for(int i=0;i<v.size();i++){
            if(v[i].size()==p.size()){
                if(v[i]==p){
                    ans.push_back(d[i]);
                }
            }else if(v[i].size()>p.size()){
                int c=0;
                for(int j=0;j<p.size();j++){
                    if(v[i][j]==p[j]) c++;
                }
                if(c==p.size()){
                    ans.push_back(d[i]);
                }
            }
        }
        if(ans.empty()) return {"-1"};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends