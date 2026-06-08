//adding required header files
#include<iostream>
#include<string>
using namespace std;

//APPROACH:
//Two strings are anagrams if they contain
//the same characters with same frequencies.
//
//First, check if lengths are equal.
//Use a frequency array of size 26
//to count characters of first string
//and decrease count using second string.
//
//If all frequencies become zero,
//both strings are anagrams.

//Time complexity: O(N)
//Space complexity: O(1)

bool isAnagram(string s, string t)
{
    //if lengths are different
    if(s.length() != t.length())
        return false;

    //frequency array for lowercase letters
    int freq[26] = {0};

    //count frequency of characters in s
    for(int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }

    //decrease frequency using t
    for(int i = 0; i < t.length(); i++)
    {
        freq[t[i] - 'a']--;
    }

    //check if all frequencies are zero
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";

    cout << (isAnagram(s, t) ? "true" : "false");

    return 0;
}