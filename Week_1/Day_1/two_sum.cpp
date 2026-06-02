//adding required header files
#include<iostream>
#include<vector>
#include<map>
using namespace std;

//APPROACH:
//We will initialise a map to store values already traversed in the array.
//We will traverse through the entire array.
//If we get the remainder (target - current value) in map, we will return the index pairs
//Else we will store the current value with index in the map.

//Time complexity: O(N) (Best and Avg case) & O(N^2) (Worst case)
//Space complexity: O(N) (When all elements of array stored in hashmap)


vector<int> twoSum(vector<int>& nums, int target) 
{
    //using a map to store (value, index) pairs
    map<int, int> mpp;
    for(int i = 0; i < nums.size(); i++)
    {
        //calculating remainder
        int rem = target - nums[i];
        //when remainder found in map
        if(mpp.find(rem) != mpp.end())
        {
            //return index of remainder value and the current value index
            return {mpp[rem], i};
        }
        //else store the current value with corresponding index in map
        mpp[nums[i]] = i;
    }
    //dummy return value to avoid compilation error
    return {};
}

int main()
{
    vector<int> nums = {3, 2, 4};
    int target = 6;
    for(auto it : twoSum(nums, target))
    {
        cout << it << " ";
    }
    return 0;
}