//adding required header files
#include<iostream>
#include<vector>
#include<queue>
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
//Use Breadth First Search (BFS)
//with a queue.
//
//Process nodes level by level.
//
//For each level,
//store node values in a vector.
//
//If traversal direction is left to right,
//place values normally.
//
//Otherwise,
//place values from right to left
//using reversed indices.
//
//Toggle the direction after every level.
//Time complexity: O(N)
//Space complexity: O(N)

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty())
    {
        int n = q.size();
        vector<int> level(n);

        for(int i = 0; i < n; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            int index = leftToRight ? i : n - 1 - i;
            level[index] = node->val;

            if(node->left)
                q.push(node->left);

            if(node->right)
                q.push(node->right);
        }

        ans.push_back(level);
        leftToRight = !leftToRight;
    }

    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = zigzagLevelOrder(root);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}