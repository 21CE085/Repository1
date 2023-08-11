//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int amount) {

        vector<long long int> dp(amount + 1);
        dp[0] = 1;

        for (int t=0; t<N; t++)
          for (int i = coins[t]; i <= amount; ++i)
            dp[i] += dp[i - coins[t]];
    
        return dp[amount];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends