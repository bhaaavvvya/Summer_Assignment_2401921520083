//adding required header files
#include<iostream>
#include<string>
using namespace std;

//APPROACH:
//First, count frequency of each character
//using a frequency array of size 26.
//
//Then traverse the string again
//and return the index of the first character
//whose frequency is 1.
//
//If no unique character exists,
//return -1.

//Time complexity: O(N)
//Space complexity: O(1)

int firstUniqChar(string s)
{
    //frequency array for lowercase letters
    int freq[26] = {0};

    //count frequency of characters
    for(int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }

    //find first unique character
    for(int i = 0; i < s.length(); i++)
    {
        if(freq[s[i] - 'a'] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string s = "leetcode";

    cout << "First unique character index: "
         << firstUniqChar(s);

    return 0;
}