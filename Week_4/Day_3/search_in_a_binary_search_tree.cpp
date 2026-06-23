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
//Use the BST property.
//
//If the current node is NULL
//or contains the target value,
//return that node.
//
//If the target value is smaller,
//search in the left subtree.
//
//Otherwise,
//search in the right subtree.
//Time complexity: O(H)
//Space complexity: O(H)
//where H is the height of the BST

TreeNode* searchBST(TreeNode* root, int val)
{
    if(root == NULL || root->val == val)
        return root;
    if(val < root->val)
        return searchBST(root->left, val);
    return searchBST(root->right, val);
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* ans = searchBST(root, 2);

    if(ans)
        cout << ans->val;
    else
        cout << "Not Found";

    return 0;
}