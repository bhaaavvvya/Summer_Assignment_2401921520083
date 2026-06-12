//adding required header files
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
//APPROACH:
//Two strings are anagrams if their
//sorted forms are identical.
//
//For each string,
//create a sorted version and use it
//as a key in an unordered_map.
//
//Strings having the same sorted key
//are grouped together.
//
//Finally, store all groups from the map
//into the answer vector.
//Time complexity: O(N × K log K)
//Space complexity: O(N × K)

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> mp;
    for(string s : strs)
    {
        string temp = s;
        sort(temp.begin(), temp.end());
        mp[temp].push_back(s);
    }

    vector<vector<string>> ans;
    for(auto it : mp)
        ans.push_back(it.second);

    return ans;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}