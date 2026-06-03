//adding required header files
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//APPROACH:
//We use the two pointer technique.
//
//One pointer starts from the beginning
//and the other starts from the end.
//
//The area formed is:
//width × minimum height between the two lines.
//
//To maximize area, we move the pointer
//having smaller height because the smaller height
//limits the container capacity.

//Time complexity: O(N)
//Space complexity: O(1)

int maxArea(vector<int>& height)
{
    //initialise two pointers
    int left = 0;
    int right = height.size() - 1;

    //store maximum area
    int maxi = 0;

    //traverse until pointers meet
    while(left < right)
    {
        //calculate width
        int width = right - left;

        //minimum height between two lines
        int h = min(height[left], height[right]);

        //update maximum area
        maxi = max(maxi, width * h);

        //move pointer with smaller height
        if(height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxi;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Maximum water area: " << maxArea(height);

    return 0;
}