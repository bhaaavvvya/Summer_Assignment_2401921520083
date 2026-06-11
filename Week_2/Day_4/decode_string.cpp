//adding required header files
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
//APPROACH:
//We use recursion to decode nested patterns.
//If a character is alphabetic,
//add it directly to the result.
//If a number is encountered,
//extract the complete number,
//recursively decode the substring inside brackets,
//and append the decoded string 'num' times.
//The recursion stops when a closing bracket is found.
//Time complexity: O(N × K)
//Space complexity: O(N)

string solve(string &s, int &i)
{
    string result;
    while(i < s.size() && s[i] != ']')
    {
        if(isalpha(s[i]))
        {
            result += s[i];
            i++;
        }
        else
        {
            int num = 0;
            while(i < s.size() && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i++;
            string temp = solve(s, i);
            i++;
            while(num--)
                result += temp;
        }
    }
    return result;
}

string decodeString(string s)
{
    int i = 0;
    return solve(s, i);
}

int main()
{
    string s = "3[a2[c]]";
    cout << decodeString(s);
    return 0;
}