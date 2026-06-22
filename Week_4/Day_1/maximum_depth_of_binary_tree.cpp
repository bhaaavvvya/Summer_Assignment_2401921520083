//adding required header files
#include<iostream>
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
//Use recursion to find the depth
//of the left and right subtrees.
//
//The depth of the current node is:
//1 + maximum(left depth, right depth)
//
//If the node is NULL,
//its depth is 0.
//Time complexity: O(N)
//Space complexity: O(H)
//where H is the height of the tree

int maxDepth(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxDepth(root);
    return 0;
}