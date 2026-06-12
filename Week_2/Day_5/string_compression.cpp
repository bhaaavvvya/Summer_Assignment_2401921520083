//adding required header files
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//APPROACH:
//Traverse the array and count
//consecutive occurrences of each character.
//Write the character once at the current
//write position.
//If its frequency is greater than 1,
//convert the count into a string and
//write its digits one by one.
//The write pointer gives the length
//of the compressed array.
//Time complexity: O(N)
//Space complexity: O(1)

int compress(vector<char>& chars)
{
    int i = 0;
    int write = 0;
    while(i < chars.size())
    {
        char curr = chars[i];
        int cnt = 0;
        while(i < chars.size() && chars[i] == curr)
        {
            i++;
            cnt++;
        }
        chars[write++] = curr;
        if(cnt > 1)
        {
            string freq = to_string(cnt);
            for(char c : freq)
                chars[write++] = c;
        }
    }
    return write;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << compress(chars);
    return 0;
}