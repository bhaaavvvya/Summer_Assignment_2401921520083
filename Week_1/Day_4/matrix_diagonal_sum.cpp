//adding required header files
#include<iostream>
#include<vector>
using namespace std;

//APPROACH:
//We traverse the matrix row by row.
//Primary diagonal elements are:
//mat[i][i]
//Secondary diagonal elements are:
//mat[i][n - i - 1]
//For odd-sized matrices, the middle element
//belongs to both diagonals, so we add it only once.

//Time complexity: O(N)
//Space complexity: O(1)

int diagonalSum(vector<vector<int>>& mat)
{
    int n = mat.size();

    //store diagonal sum
    int sum = 0;

    //traverse matrix
    for(int i = 0; i < n; i++)
    {
        //add primary diagonal element
        sum += mat[i][i];

        //avoid adding middle element twice
        if(i != (n - i - 1))
            sum += mat[i][n - i - 1];
    }

    return sum;
}

int main()
{
    vector<vector<int>> mat =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Diagonal sum: " << diagonalSum(mat);

    return 0;
}