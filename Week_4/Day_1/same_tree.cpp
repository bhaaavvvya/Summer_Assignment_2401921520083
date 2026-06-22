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
//Recursively compare both trees.
//
//If both nodes are NULL,
//they are identical at this position.
//
//If one node is NULL and the other is not,
//the trees are different.
//
//Compare current node values.
//Then recursively compare
//the left subtrees and right subtrees.
//Time complexity: O(N)
//Space complexity: O(H)
//where H is the height of the tree

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;
    if(p->val != q->val)
        return false;
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main()
{
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    cout << (isSameTree(p, q) ? "true" : "false");
    return 0;
}