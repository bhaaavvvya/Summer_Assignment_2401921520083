//adding required header files
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//APPROACH:
//We will use Kadane's Algorithm.
//We traverse the array maintaining a running sum.
//At each element, we add it to the current sum and update maxSum if it is better.
//If the running sum drops below 0, we reset it to 0 (no point carrying a negative sum forward).

//Time complexity: O(N) (Single pass through the array)
//Space complexity: O(1) (Only two extra variables used)

int maxSubArray(vector<int>& nums)
{
    //initialise current sum to 0
    int sum = 0;
    //initialise maxSum to INT_MIN to handle all-negative arrays
    int maxSum = INT_MIN;

    for(int i = 0; i < nums.size(); i++)
    {
        //add current element to running sum
        sum += nums[i];

        //update maxSum if running sum is better
        if(sum > maxSum)
            maxSum = sum;

        //reset sum if it goes negative (discard subarray)
        if(sum < 0)
            sum = 0;
    }
    //return the maximum subarray sum found
    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}