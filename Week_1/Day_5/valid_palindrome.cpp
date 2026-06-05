//adding required header files
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//APPROACH:
//We use two pointers:
//left starts from beginning
//right starts from end.
//
//Ignore all non-alphanumeric characters.
//Compare characters after converting them to lowercase.
//If any pair does not match, return false.
//If all characters match, return true.

//Time complexity: O(N)
//Space complexity: O(1)

bool isPalindrome(string s)
{
    int left = 0;
    int right = s.size() - 1;

    //traverse from both ends
    while(left < right)
    {
        //skip non-alphanumeric characters from left
        while(left < right && !isalnum(s[left]))
            left++;

        //skip non-alphanumeric characters from right
        while(left < right && !isalnum(s[right]))
            right--;

        //compare characters ignoring case
        if(tolower(s[left]) != tolower(s[right]))
            return false;

        left++;
        right--;
    }

    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";

    cout << (isPalindrome(s) ? "true" : "false");

    return 0;
}