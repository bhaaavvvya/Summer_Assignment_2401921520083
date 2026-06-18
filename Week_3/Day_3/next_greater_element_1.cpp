//adding required header files
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

//APPROACH:
//Use a monotonic decreasing stack
//to find the next greater element
//for every number in nums2.
//
//Whenever the current number is greater
//than the stack top, it becomes the next
//greater element for that stack element.
//
//Store these mappings in a hash map.
//
//Finally, traverse nums1 and use the map
//to get the next greater element.
//If not present, answer is -1.
//Time complexity: O(N + M)
//Space complexity: O(N)

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    stack<int> st;
    unordered_map<int, int> mp;

    for(int num : nums2)
    {
        while(!st.empty() && st.top() < num)
        {
            mp[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    vector<int> ans;

    for(int num : nums1)
    {
        if(mp.find(num) != mp.end())
            ans.push_back(mp[num]);
        else
            ans.push_back(-1);
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElement(nums1, nums2);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}