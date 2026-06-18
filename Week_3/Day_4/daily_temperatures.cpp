//adding required header files
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//APPROACH:
//Use a monotonic decreasing stack
//to store indices of temperatures.
//
//For each temperature,
//if it is greater than the temperature
//at the index on top of the stack,
//then it is the next warmer day.
//
//Calculate the difference in indices
//and store it in the answer array.
//
//Push the current index into the stack.
//Time complexity: O(N)
//Space complexity: O(N)

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    vector<int> ans(temperatures.size(), 0);
    stack<int> st;

    for(int i = 0; i < temperatures.size(); i++)
    {
        while(!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(temperatures);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}