//adding required header files
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

//APPROACH:
//Use a deque to store indices
//of useful elements for the current window.
//
//Remove indices that are outside
//the current window.
//
//Maintain the deque in decreasing order
//of values by removing smaller elements
//from the back.
//
//The front of the deque always stores
//the index of the maximum element
//for the current window.
//Time complexity: O(N)
//Space complexity: O(K)

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++)
    {
        while(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        if(i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}