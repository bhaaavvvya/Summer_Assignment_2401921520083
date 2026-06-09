//adding required header files
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//APPROACH:
//We use the sliding window technique.
//Two pointers define the current window:
//left -> starting index
//right -> ending index
//Use a frequency array to track characters
//present in the current window.
//If a duplicate character appears,
//shrink the window from the left side
//until all characters become unique.
//Update the maximum window length throughout.
//Time complexity: O(N)
//Space complexity: O(1)

int lengthOfLongestSubstring(string s)
{
    //frequency array for ASCII characters
    int freq[128] = {0};
    int left = 0;
    int maxLen = 0;
    //expand window using right pointer
    for(int right = 0; right < s.size(); right++)
    {
        freq[s[right]]++;

        //shrink window if duplicate exists
        while(freq[s[right]] > 1)
        {
            freq[s[left]]--;
            left++;
        }

        //update maximum length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    string s = "abcabcbb";
    cout << "Length of longest substring: "
         << lengthOfLongestSubstring(s);
    return 0;
}