//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
         void Rearrange(int arr[], int n)
        {
            
            vector<int>negative;
            vector<int>positive;
            for(int i=0;i<n;i++)
            {
                if(arr[i]<0)
                {
                   negative.push_back(arr[i]);
                }
                else
                positive.push_back(arr[i]);
            }

            //for negative numbers
            int ne=negative.size();
            for(int i=0;i<ne;i++)
            arr[i]=negative[i];
            int pe=positive.size();
            for(int i=ne;i<ne+pe;i++)
            arr[i]=positive[i-ne];
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends