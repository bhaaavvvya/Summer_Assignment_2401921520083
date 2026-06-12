//adding required header files
#include<iostream>
#include<string>
using namespace std;
//APPROACH:
//Treat each character as the center
//of a palindrome.
//Expand around the center in two cases:
//1. Odd length palindrome (i, i)
//2. Even length palindrome (i, i + 1)
//
//While expanding, update the starting
//index and maximum length whenever
//a longer palindrome is found.
//Finally, return the longest palindromic substring.
//Time complexity: O(N²)
//Space complexity: O(1)

void expand(string& s, int l, int r, int &start, int &maxLen)
{
    while(l >= 0 && r < s.size() && s[l] == s[r])
    {
        if(r - l + 1 > maxLen)
        {
            maxLen = r - l + 1;
            start = l;
        }
        l--;
        r++;
    }
}

string longestPalindrome(string s)
{
    int start = 0;
    int maxLen = 1;
    for(int i = 0; i < s.size(); i++)
    {
        expand(s, i, i, start, maxLen);
        expand(s, i, i + 1, start, maxLen);
    }
    return s.substr(start, maxLen);
}

int main()
{
    string s = "babad";
    cout << longestPalindrome(s);
    return 0;
}