//adding required header files
#include<iostream>
#include<string>
using namespace std;
//APPROACH:
//Traverse the haystack string
//and check every possible starting position.
//For each position,
//compare characters of needle one by one.
//If all characters match,
//return the starting index.
//If no match is found,
//return -1.
//Time complexity: O((N - M + 1) × M)
//Space complexity: O(1)

int strStr(string haystack, string needle)
{
    //if needle is larger than haystack
    if(needle.size() > haystack.size())
        return -1;
    //check every possible starting index
    for(int i = 0; i <= haystack.size() - needle.size(); i++)
    {
        int j = 0;

        //compare characters
        while(j < needle.size() && haystack[i + j] == needle[j])
        {
            j++;
        }

        //if full match found
        if(j == needle.size())
            return i;
    }

    return -1;
}

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    cout << strStr(haystack, needle);
    return 0;
}