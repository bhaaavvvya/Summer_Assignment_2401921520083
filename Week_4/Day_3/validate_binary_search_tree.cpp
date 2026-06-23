//adding required header files
#include<iostream>
#include<climits>
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
//For every node,
//maintain a valid range
//(low, high).
//
//A node value must be:
//low < node->val < high
//
//For the left subtree,
//update the upper bound
//to the current node value.
//
//For the right subtree,
//update the lower bound
//to the current node value.
//
//If any node violates the range,
//the tree is not a valid BST.
//Time complexity: O(N)
//Space complexity: O(H)
//where H is the height of the tree

bool solve(TreeNode* root, long long low, long long high)
{
    if(root == NULL)
        return true;

    if(root->val <= low || root->val >= high)
        return false;

    return solve(root->left, low, root->val) &&
           solve(root->right, root->val, high);
}

bool isValidBST(TreeNode* root)
{
    return solve(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << (isValidBST(root) ? "true" : "false");
    return 0;
}