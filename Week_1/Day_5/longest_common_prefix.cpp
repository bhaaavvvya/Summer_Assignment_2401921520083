//adding required header files
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//APPROACH:
//After sorting the array of strings,
//the common prefix between the first
//and last string will be the answer.
//
//Compare characters of both strings
//until characters stop matching.

//Time complexity: O(N log N)
//Space complexity: O(1)

string longestCommonPrefix(vector<string>& strs)
{
    //if array is empty
    if(strs.empty())
        return "";

    //sort strings
    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[strs.size() - 1];

    string ans = "";

    //minimum length among first and last string
    int minLength = min(first.size(), last.size());

    //find common prefix
    for(int i = 0; i < minLength; i++)
    {
        if(first[i] != last[i])
            break;

        ans += first[i];
    }

    return ans;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    cout << "Longest common prefix: "
         << longestCommonPrefix(strs);

    return 0;
}