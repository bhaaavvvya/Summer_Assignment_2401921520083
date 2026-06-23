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
//If both p and q are smaller
//than the current node,
//move to the left subtree.
//
//If both p and q are greater
//than the current node,
//move to the right subtree.
//
//Otherwise,
//the current node is the
//Lowest Common Ancestor.
//Time complexity: O(H)
//Space complexity: O(1)
//where H is the height of the BST

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    while(root)
    {
        if(p->val < root->val && q->val < root->val)
            root = root->left;
        else if(p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }

    return NULL;
}

int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* ans = lowestCommonAncestor(root, p, q);
    cout << ans->val;

    return 0;
}