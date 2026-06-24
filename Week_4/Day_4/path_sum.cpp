//adding required header files
#include<iostream>
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
//Use recursion to check
//all root-to-leaf paths.
//
//At each node,
//subtract its value
//from the target sum.
//
//When a leaf node is reached,
//check whether the remaining
//target sum equals the node value.
//
//If any root-to-leaf path
//satisfies the condition,
//return true.
//Time complexity: O(N)
//Space complexity: O(H)
//where H is the height of the tree

bool hasPathSum(TreeNode* root, int targetSum)
{
    if(root == NULL)
        return false;

    if(root->left == NULL && root->right == NULL)
        return targetSum == root->val;

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    cout << (hasPathSum(root, 22) ? "true" : "false");
    return 0;
}