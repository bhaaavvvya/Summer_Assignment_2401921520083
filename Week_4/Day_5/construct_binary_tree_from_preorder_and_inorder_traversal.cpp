//adding required header files
#include<iostream>
#include<vector>
#include<unordered_map>
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
//The first element in preorder
//is always the root node.
//
//Use a hashmap to store the index
//of each value in inorder traversal.
//
//Find the root position in inorder.
//Elements on the left belong to
//the left subtree and elements on the right
//belong to the right subtree.
//
//Recursively build both subtrees.
//Time complexity: O(N)
//Space complexity: O(N)

unordered_map<int, int> mp;
int preIndex = 0;

TreeNode* build(vector<int>& preorder, int left, int right)
{
    if(left > right)
        return NULL;

    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int mid = mp[rootVal];

    root->left = build(preorder, left, mid - 1);
    root->right = build(preorder, mid + 1, right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    for(int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    return build(preorder, 0, inorder.size() - 1);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);
    cout << root->val;

    return 0;
}