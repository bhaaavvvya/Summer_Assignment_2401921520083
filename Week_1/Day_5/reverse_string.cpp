//adding required header files
#include<iostream>
#include<vector>
using namespace std;

//APPROACH:
//We use two pointers:
//left starts from beginning
//right starts from end.
//
//Swap characters at both pointers
//and move them towards the center.
//Repeat until both pointers meet.

//Time complexity: O(N)
//Space complexity: O(1)

void reverseString(vector<char>& s)
{
    int left = 0;
    int right = s.size() - 1;

    //reverse the string
    while(left <= right)
    {
        //swap characters
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    reverseString(s);

    //print reversed string
    for(int i = 0; i < s.size(); i++)
        cout << s[i] << " ";

    return 0;
}