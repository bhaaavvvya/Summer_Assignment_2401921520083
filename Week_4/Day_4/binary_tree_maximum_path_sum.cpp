//adding required header files
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

//definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

//APPROACH:
//For each node,
//calculate the maximum path sum
//starting from that node and extending
//to one of its children.
//
//Ignore negative path sums
//by taking max(0, subtree sum).
//
//The path passing through the current node is:
//left contribution + right contribution + root->val
//
//Update the global maximum path sum.
//
//Return the best single-side path
//to the parent node.
//Time complexity: O(N)
//Space complexity: O(H)
//where H is the height of the tree

int maxi = INT_MIN;

int dfs(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int left = max(0, dfs(root->left));
    int right = max(0, dfs(root->right));

    maxi = max(maxi, left + right + root->val);

    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root)
{
    dfs(root);
    return maxi;
}

int main()
{
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root);
    return 0;
}