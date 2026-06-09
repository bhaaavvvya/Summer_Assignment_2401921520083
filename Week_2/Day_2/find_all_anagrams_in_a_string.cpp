//adding required header files
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//APPROACH:
//We use the sliding window technique.
//Store frequency of characters of p
//and frequency of current window in s.
//First, process the initial window of size p.length().
//Then slide the window one character at a time.
//If both frequency arrays become equal,
//store the starting index of that window.
//Time complexity: O(N)
//Space complexity: O(1)

vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;

    //if p is larger than s
    if(p.size() > s.size())
    {
        return ans;
    }

    int freq1[26] = {0};
    int freq2[26] = {0};

    //store frequency of initial window
    for(int i = 0; i < p.size(); i++)
    {
        freq1[p[i] - 'a']++;
        freq2[s[i] - 'a']++;
    }

    //check initial window
    if(equal(freq1, freq1 + 26, freq2))
    {
        ans.push_back(0);
    }

    //slide the window
    for(int right = p.size(); right < s.size(); right++)
    {
        freq2[s[right] - 'a']++;
        freq2[s[right - p.size()] - 'a']--;

        //check if frequencies match
        if(equal(freq1, freq1 + 26, freq2))
        {
            ans.push_back(right - p.size() + 1);
        }
    }

    return ans;
}

int main()
{
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> ans = findAnagrams(s, p);

    //print starting indices
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}