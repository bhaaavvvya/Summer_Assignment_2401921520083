//adding required header files
#include<iostream>
#include<vector>
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
//Use recursive inorder traversal.
//
//Visit nodes in the order:
//1. Left subtree
//2. Root node
//3. Right subtree
//
//Store each visited node value
//in the answer vector.
//Time complexity: O(N)
//Space complexity: O(H)
//where H is the height of the tree

vector<int> ans;

void traverse(TreeNode* root)
{
    if(root == NULL)
        return;
    traverse(root->left);
    ans.push_back(root->val);
    traverse(root->right);
}

vector<int> inorderTraversal(TreeNode* root)
{
    traverse(root);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = inorderTraversal(root);

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}