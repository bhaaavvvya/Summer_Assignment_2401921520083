//adding required header files
#include<iostream>
#include<string>
using namespace std;
//APPROACH:
//Concatenate the string with itself.
//Remove the first and last character
//from the new string.
//If the original string exists inside it,
//then the string is formed by repeating
//a substring pattern.
//Time complexity: O(N)
//Space complexity: O(N)

bool repeatedSubstringPattern(string s)
{
    string temp = s + s;
    temp = temp.substr(1, temp.size() - 2);
    return temp.find(s) != string::npos;
}

int main()
{
    string s = "abab";
    cout << (repeatedSubstringPattern(s) ? "true" : "false");
    return 0;
}