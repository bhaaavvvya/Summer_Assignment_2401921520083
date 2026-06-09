//adding required header files
#include<iostream>
#include<string>
using namespace std;

//APPROACH:
//Count frequency of all characters
//present in the magazine string.
//Then traverse the ransomNote string
//and decrease the corresponding frequency.
//If any frequency becomes negative,
//that character is not available enough times
//in the magazine, so return false.
//Otherwise, return true.

//Time complexity: O(N + M)
//Space complexity: O(1)

bool canConstruct(string ransomNote, string magazine)
{
    //frequency array for lowercase letters
    int freq[26] = {0};

    //count characters in magazine
    for(int i = 0; i < magazine.size(); i++)
    {
        freq[magazine[i] - 'a']++;
    }

    //check characters for ransom note
    for(int i = 0; i < ransomNote.size(); i++)
    {
        freq[ransomNote[i] - 'a']--;
        //if character unavailable
        if(freq[ransomNote[i] - 'a'] < 0)
            return false;
    }
    return true;
}

int main()
{
    string ransomNote = "aa";
    string magazine = "aab";
    cout << (canConstruct(ransomNote, magazine) ? "true" : "false");
    return 0;
}