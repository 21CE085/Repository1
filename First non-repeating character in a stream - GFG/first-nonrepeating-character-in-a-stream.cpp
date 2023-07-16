//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
            // Code here
            string ans;
            
            unordered_map<char,int> freq;
            queue<char> single;
            
            for(int i = 0;i<A.length();i++){
                freq[A[i]]++;
                
                if(freq[A[i]]==1){
                    single.push(A[i]);
                }
                
                while(!single.empty() and freq[single.front()]>1){
                    single.pop();
                }
                
                if(single.empty()) ans.push_back('#');
                else ans.push_back(single.front());
            }
            
            return ans;
        }



};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends