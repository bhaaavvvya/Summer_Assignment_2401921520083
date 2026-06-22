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
//Recursively traverse the tree.
//
//For every node,
//swap its left and right child.
//
//Then recursively invert
//the left and right subtrees.
//
//After processing all nodes,
//the binary tree becomes inverted.
//Time complexity: O(N)
//Space complexity: O(H)
//where H is the height of the tree

void invertNode(TreeNode* root)
{
    if(root == NULL)
        return;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertNode(root->left);
    invertNode(root->right);
}

TreeNode* invertTree(TreeNode* root)
{
    invertNode(root);
    return root;
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    root = invertTree(root);
    cout << root->left->val << " " << root->right->val;
    return 0;
}