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
//A tree is symmetric if
//its left and right subtrees
//are mirror images of each other.
//
//Compare corresponding nodes
//from both sides.
//
//Their values must be equal and:
//left->left should mirror right->right
//left->right should mirror right->left
//
//Recursively check all pairs.
//Time complexity: O(N)
//Space complexity: O(H)
//where H is the height of the tree

bool mirror(TreeNode* left, TreeNode* right)
{
    if(left == NULL && right == NULL)
        return true;

    if(left == NULL || right == NULL)
        return false;

    if(left->val != right->val)
        return false;

    return mirror(left->left, right->right) &&
           mirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root)
{
    if(root == NULL)
        return true;

    return mirror(root->left, root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << (isSymmetric(root) ? "true" : "false");
    return 0;
}