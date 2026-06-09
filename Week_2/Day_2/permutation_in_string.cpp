//adding required header files
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//APPROACH:
//We use the sliding window technique.
//Store frequency of characters of s1
//and frequency of current window in s2.
//First, process the initial window of size s1.length().
//Then slide the window one character at a time.
//If both frequency arrays become equal,
//a permutation of s1 exists in s2.
//Time complexity: O(N)
//Space complexity: O(1)

bool checkInclusion(string s1, string s2)
{
    //if s1 is larger than s2
    if(s1.size() > s2.size())
    {
        return false;
    }

    int freq1[26] = {0};
    int freq2[26] = {0};

    //store frequency of initial window
    for(int i = 0; i < s1.size(); i++)
    {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    //check initial window
    if(equal(freq1, freq1 + 26, freq2))
    {
        return true;
    }

    //slide the window
    for(int right = s1.size(); right < s2.size(); right++)
    {
        freq2[s2[right] - 'a']++;
        freq2[s2[right - s1.size()] - 'a']--;

        //check if frequencies match
        if(equal(freq1, freq1 + 26, freq2))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << (checkInclusion(s1, s2) ? "true" : "false");
    return 0;
}