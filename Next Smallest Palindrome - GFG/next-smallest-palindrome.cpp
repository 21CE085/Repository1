//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
bool isall(int u[],int n){
        for(int i=0;i<n;i++){
            if(u[i]!=9) return 0;
        }return 1;
    }
    vector<int> generateNextPalindrome(int u[], int n)
    {
        int r = n - 1;
        vector<int> v(n, 0);
        int p1 = 0;
        bool m = 1;
        for (int i = 0; i < n; i++)  v[i] = u[i];
        if (n == 1)
        {
            if (v[0] < 9) v[0]++;
            else
            {
                v[0] = 1;
                v.push_back(1);
            }
            return v;
        }
        while (p1 < n / 2)
        {
            if (v[p1] > v[r])
            {
                m = 0;
                v[r--] = v[p1++];
            }
            else if (v[p1] < v[r])
            {
                m = 0;
                v[r] = v[p1];
                int  j = r - 1;
                while (1)
                {
                    if (v[j] < 9)
                    {
                        v[j]++;
                        break;
                    }
                    else  v[j--] = 0;
                }
            }
            else p1++, r--;
        }
        if (m)
        {
            if (v.size() % 2 == 1)
            {
                if (v[n/2] < 9) v[n/2]++;
                else
                {
                    for (int i = (v.size() / 2) - 1; i < v.size() / 2; i++)
                    {
                        if (v[i] < 9)
                        {
                            v[i]++;
                            v[v.size() - i - 1]++;
                            break;
                        }
                    }
                }
            }
            else
            {
                for (int i = (v.size() / 2) - 1; i < v.size() / 2; i++)
                {
                    if (v[i] < 9)
                    {
                        v[i]++;
                        v[v.size() - i - 1]++;
                        break;
                    }
                }
            }
        }
        if(isall(u,n)){
            for(int i=0;i<n+1;i++){
                if(i==0||i==n)cout<<"1 ";
                else cout<<"0 ";
            }
            return {};
        }
        return v;
    }

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends