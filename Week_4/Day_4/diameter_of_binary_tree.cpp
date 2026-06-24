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
//The diameter of a binary tree
//is the maximum number of edges
//between any two nodes.
//
//For each node,
//calculate the height of its
//left and right subtrees.
//
//The path passing through
//the current node is:
//left height + right height
//
//Update the maximum diameter
//while computing heights.
//Time complexity: O(N)
//Space complexity: O(H)
//where H is the height of the tree

int diameter = 0;

int height(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root)
{
    height(root);
    return diameter;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree(root);
    return 0;
}