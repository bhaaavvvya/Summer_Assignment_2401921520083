//adding required header files
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//APPROACH:
//Use recursion to reverse each word individually.
//The solve() function finds the boundaries
//of every word separated by spaces.
//For each word, reverseWord() recursively
//reverses characters from both ends.
//After processing all words,
//return the modified string.
//Time complexity: O(N)
//Space complexity: O(N) (recursive stack)

void reverseWord(string &s, int left, int right)
{
    if(left >= right)
        return;
    swap(s[left], s[right]);
    reverseWord(s, left + 1, right - 1);
}

void solve(string &s, int start)
{
    if(start >= s.size())
        return;
    int end = start;
    while(end < s.size() && s[end] != ' ')
        end++;
    reverseWord(s, start, end - 1);
    solve(s, end + 1);
}

string reverseWords(string s)
{
    solve(s, 0);
    return s;
}

int main()
{
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s);
    return 0;
}