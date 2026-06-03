//adding required header files
#include<iostream>
#include<vector>
using namespace std;

//APPROACH:
//We first find the index of the first zero in the array.
//Then we traverse the remaining array elements.
//Whenever a non-zero element is found, we swap it with the zero element.
//This shifts all zeroes to the end while maintaining the relative order
//of non-zero elements.

//Time complexity: O(N)
//Space complexity: O(1)

void moveZeroes(vector<int>& nums)
{
    //initialise index of first zero as -1
    int j = -1;

    //find the first zero element
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    //if no zero found, return
    if(j == -1)
        return;

    //traverse remaining elements
    for(int i = j + 1; i < nums.size(); i++)
    {
        //if non-zero element found
        if(nums[i] != 0)
        {
            //swap current non-zero element with zero element
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            //move j to next zero position
            j++;
        }
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    //print updated array
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    return 0;
}