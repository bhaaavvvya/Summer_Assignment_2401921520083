//adding required header files
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//APPROACH:
//We will use an unordered_set to track elements seen so far.
//We traverse the array and check if the current element already exists in the set.
//If yes, a duplicate is found and we return true immediately.
//If no, we insert the element into the set and continue.

//Time complexity: O(N) average case (unordered_set operations are O(1) average)
//Space complexity: O(N) (At most N elements stored in the set)

bool containsDuplicate(vector<int>& nums)
{
    //initialise an unordered_set to store seen elements
    unordered_set<int> st;

    for(int i = 0; i < nums.size(); i++)
    {
        //if element already exists in set, duplicate found
        if(st.find(nums[i]) != st.end())
            return true;

        //else insert current element into the set
        st.insert(nums[i]);
    }
    //no duplicates found
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << (containsDuplicate(nums) ? "true" : "false");
    return 0;
}