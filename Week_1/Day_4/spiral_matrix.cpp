//adding required header files
#include<iostream>
#include<vector>
using namespace std;

//APPROACH:
//We use four boundaries:
//top, bottom, left and right.
//Traverse the matrix layer by layer
//in spiral order:
//1. Left to right
//2. Top to bottom
//3. Right to left
//4. Bottom to top
//After each traversal, update boundaries.

//Time complexity: O(M × N)
//Space complexity: O(M × N)

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> ans;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    //traverse matrix in spiral form
    while(top <= bottom && left <= right)
    {
        //left to right
        for(int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        top++;

        //top to bottom
        for(int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        //right to left
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }

        //bottom to top
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);

    //print spiral order
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}