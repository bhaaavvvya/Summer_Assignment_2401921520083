//adding required header files
#include<iostream>
#include<vector>
using namespace std;

//APPROACH:
//First, check whether reshaping is possible or not.
//The total number of elements must remain the same.
//Original matrix elements = m × n
//New matrix elements = r × c
//If sizes do not match, return the original matrix.
//We use a single loop to map elements from
//the original matrix to the reshaped matrix
//using row and column calculations.

//Time complexity: O(M × N)
//Space complexity: O(R × C)

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
{
    int m = mat.size();
    int n = mat[0].size();

    //check if reshape is possible
    if(m * n != r * c)
        return mat;

    //create reshaped matrix
    vector<vector<int>> ans(r, vector<int>(c));

    //fill reshaped matrix
    for(int i = 0; i < m * n; i++)
    {
        ans[i / c][i % c] = mat[i / n][i % n];
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat =
    {
        {1, 2},
        {3, 4}
    };

    int r = 1;
    int c = 4;

    vector<vector<int>> result = matrixReshape(mat, r, c);

    //print reshaped matrix
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}