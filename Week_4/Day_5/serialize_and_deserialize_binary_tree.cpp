//adding required header files
#include<iostream>
#include<string>
#include<sstream>
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
//For serialization,
//perform preorder traversal.
//
//Store node values separated by commas.
//Use "#" to represent NULL nodes.
//
//For deserialization,
//read values one by one using stringstream.
//
//If the value is "#",
//return NULL.
//
//Otherwise create a node
//and recursively build its
//left and right subtrees.
//Time complexity: O(N)
//Space complexity: O(N)

void preorder(TreeNode* root, string& s)
{
    if(root == NULL)
    {
        s += "#,";
        return;
    }
    s += to_string(root->val) + ",";
    preorder(root->left, s);
    preorder(root->right, s);
}

string serialize(TreeNode* root)
{
    string s;
    preorder(root, s);
    return s;
}

TreeNode* build(stringstream& ss)
{
    string val;
    getline(ss, val, ',');

    if(val == "#")
        return NULL;

    TreeNode* root = new TreeNode(stoi(val));

    root->left = build(ss);
    root->right = build(ss);

    return root;
}

TreeNode* deserialize(string data)
{
    stringstream ss(data);
    return build(ss);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    string data = serialize(root);
    cout << data << endl;

    TreeNode* newRoot = deserialize(data);
    cout << newRoot->val;

    return 0;
}