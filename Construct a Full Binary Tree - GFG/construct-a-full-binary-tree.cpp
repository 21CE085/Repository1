//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* solve(int pre[] , int preMirror[] , int& index , int l , int h , int size)
    {
        if(size <= index || l>h)
        {
            return NULL;
        }
        Node* root = new Node(pre[index]);
        index = index+1;
        if(l==h) return root;
        int i;
        for(i=l;i<=h ;i++)
        {
            if(pre[index] == preMirror[i]) break;
        }
        if(i<=h)
        {
            root->left = solve(pre , preMirror , index , i , h , size);
            root->right = solve(pre , preMirror , index , l+1 , i-1 , size);
        }
        return root;
        
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        int index = 0;
        return solve(pre , preMirror , index , 0 , size-1 , size );
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends