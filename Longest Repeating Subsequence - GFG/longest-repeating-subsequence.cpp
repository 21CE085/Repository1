//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
            
            int n=str.length();
            int mat[n+1][n+1];
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    mat[i][j]=0;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(str[i-1]==str[j-1]&& i!=j)
                    {
                        mat[i][j]=1+mat[i-1][j-1];
                    }
                    else
                    {
                        mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
                    }
                }
            }
            return mat[n][n];
        }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends