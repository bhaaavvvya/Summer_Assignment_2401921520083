//adding required header files
#include<iostream>
#include<vector>
using namespace std;

//APPROACH:
//Since the array is already sorted, the largest square value
//will come either from the leftmost negative number
//or the rightmost positive number.
//
//We use two pointers:
//left  -> starting index
//right -> ending index
//
//Compare squares of both elements and place the larger one
//at the end of the answer array.
//Move the corresponding pointer inward and continue.

//Time complexity: O(N)
//Space complexity: O(N)

vector<int> sortedSquares(vector<int>& nums)
{
    //create answer vector of same size
    vector<int> ans(nums.size());

    int left = 0;
    int right = nums.size() - 1;

    //index for filling answer array from end
    int index = nums.size() - 1;

    //process until pointers cross
    while(left <= right)
    {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        //place larger square at current index
        if(leftSquare > rightSquare)
        {
            ans[index] = leftSquare;
            left++;
        }
        else
        {
            ans[index] = rightSquare;
            right--;
        }

        index--;
    }

    return ans;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> result = sortedSquares(nums);

    //print sorted squared array
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}