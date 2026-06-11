//adding required header files
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//APPROACH:
//We use backtracking to generate
//all valid combinations of parentheses.
//Keep track of:
//open  -> number of opening brackets used
//close -> number of closing brackets used
//
//An opening bracket can be added
//if open < n.
//A closing bracket can be added
//if close < open.
//
//When the current string length
//becomes 2 * n, store it in the answer.
//Time complexity: O(4^N / √N)
//Space complexity: O(N)

vector<string> ans;

void solve(int open, int close, int n, string curr)
{
    if(curr.length() == 2 * n)
    {
        ans.push_back(curr);
        return;
    }
    if(open < n)
        solve(open + 1, close, n, curr + '(');
    if(close < open)
        solve(open, close + 1, n, curr + ')');
}

vector<string> generateParenthesis(int n)
{
    solve(0, 0, n, "");
    return ans;
}

int main()
{
    int n = 3;
    vector<string> result = generateParenthesis(n);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}