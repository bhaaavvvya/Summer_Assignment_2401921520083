//adding required header files
#include<iostream>
#include<vector>
using namespace std;

//APPROACH:
//We will use two pointers i and j.
//i points to the last confirmed unique element, j scans ahead.
//If nums[j] is different from nums[i], we place it right after i and advance i.
//At the end, the first i+1 elements are the unique elements in-place.

//Time complexity: O(N) (Single pass through the array)
//Space complexity: O(1) (No extra space used, in-place modification)

int removeDuplicates(vector<int>& nums)
{
    //i tracks the position of the last unique element
    int i = 0;
    for(int j = 1; j < nums.size(); j++)
    {
        //when a new unique element is found
        if(nums[j] != nums[i])
        {
            //place it right after the last unique element
            nums[i + 1] = nums[j];
            //advance the unique pointer
            i++;
        }
    }
    //return count of unique elements
    return i + 1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3};
    int k = removeDuplicates(nums);
    for(int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}