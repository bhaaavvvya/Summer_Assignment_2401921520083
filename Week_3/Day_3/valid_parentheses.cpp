//adding required header files
#include<iostream>
#include<stack>
#include<string>
using namespace std;

//APPROACH:
//Use a stack to keep track of
//opening brackets.
//
//If an opening bracket is found,
//push it onto the stack.
//
//For a closing bracket,
//check whether the stack is empty.
//If empty, the string is invalid.
//
//Otherwise, verify that the current
//closing bracket matches the top
//opening bracket.
//
//At the end, the stack should be empty
//for the string to be valid.
//Time complexity: O(N)
//Space complexity: O(N)

bool isValid(string s)
{
    stack<char> st;
    for(auto it : s)
    {
        if(it == '[' || it == '{' || it == '(')
        {
            st.push(it);
        }
        else
        {
            if(st.empty())
            {
                return false;
            }
            if((st.top() == '[' && it == ']') || (st.top() == '{' && it == '}') || (st.top() == '(' && it == ')'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "()[]{}";
    cout << (isValid(s) ? "true" : "false");
    return 0;
}