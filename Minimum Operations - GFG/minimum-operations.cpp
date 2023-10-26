//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int rec(int n){
      if(n<=3){
          return n;
      }
    
      if(n%2==0){
          return 1+rec(n/2);
      }else{
          return 2+rec(n/2);
      }
  }
    int minOperation(int n)
    {
        //code here.
        return rec(n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends