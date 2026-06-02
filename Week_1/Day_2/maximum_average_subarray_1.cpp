//adding required header files
#include<iostream>
#include<vector>
using namespace std;

//APPROACH:
//We will use the sliding window technique.
//First we calculate the sum of the first window of size k.
//Then we slide the window forward by adding the next element and removing the first element.
//We update maxSum whenever the current window sum is greater.
//At the end we return maxSum divided by k to get the maximum average.

//Time complexity: O(N) (Single pass through the array)
//Space complexity: O(1) (Only a few extra variables used)

double findMaxAverage(vector<int>& nums, int k)
{
    //calculate sum of first window of size k
    double windowSum = 0;
    for(int i = 0; i < k; i++)
        windowSum += nums[i];

    //initialise maxSum to the first window sum
    double maxSum = windowSum;

    for(int i = k; i < nums.size(); i++)
    {
        //slide the window: add next element, remove first element of previous window
        windowSum += nums[i] - nums[i - k];

        //update maxSum if current window sum is greater
        if(windowSum > maxSum)
            maxSum = windowSum;
    }
    //return maximum average
    return maxSum / k;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << findMaxAverage(nums, k);
    return 0;
}