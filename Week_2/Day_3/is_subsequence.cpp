//adding required header files
#include<iostream>
#include<string>
using namespace std;
//APPROACH:
//We use two pointers.
//left traverses string s
//and right traverses string t.
//Whenever characters match,
//move left pointer forward.
//Always move right pointer forward.
//If left reaches the end of s,
//then s is a subsequence of t.
//Time complexity: O(N)
//Space complexity: O(1)

bool isSubsequence(string s, string t)
{
    //empty string is always a subsequence
    if(s.size() == 0)
        return true;

    //if s is larger than t
    if(s.size() > t.size())
        return false;

    int left = 0;
    int right = 0;

    //traverse string t
    while(right < t.size())
    {
        //if characters match
        if(s[left] == t[right])
        {
            left++;
        }

        right++;
    }

    //if all characters of s not matched
    if(left <= s.size() - 1)
        return false;

    return true;
}

int main()
{
    string s = "abc";
    string t = "ahbgdc";
    cout << (isSubsequence(s, t) ? "true" : "false");
    return 0;
}