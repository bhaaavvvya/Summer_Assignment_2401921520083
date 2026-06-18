//adding required header files
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//APPROACH:
//Use a monotonic increasing stack
//to store indices of histogram bars.
//
//Whenever the current bar is smaller
//than the bar at the stack top,
//calculate the area for bars that can
//no longer extend further.
//
//Width is determined using the current index
//and the new stack top after popping.
//
//Process all remaining bars by iterating
//one extra step beyond the array.
//Time complexity: O(N)
//Space complexity: O(N)

int largestRectangleArea(vector<int>& heights)
{
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for(int i = 0; i <= n; i++)
    {
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();

            int width;
            if(st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }

    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);
    return 0;
}