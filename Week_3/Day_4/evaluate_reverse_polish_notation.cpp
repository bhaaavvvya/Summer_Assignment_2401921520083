//adding required header files
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

//APPROACH:
//Use a stack to evaluate
//the Reverse Polish Notation expression.
//
//If the current token is a number,
//push it onto the stack.
//
//If the token is an operator,
//pop the top two elements,
//perform the operation,
//and push the result back.
//
//After processing all tokens,
//the stack top contains the final answer.
//Time complexity: O(N)
//Space complexity: O(N)

int evalRPN(vector<string>& tokens)
{
    stack<int> st;
    for(string token : tokens)
    {
        if(token != "+" &&
           token != "-" &&
           token != "*" &&
           token != "/")
        {
            st.push(stoi(token));
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if(token == "+")
                st.push(a + b);
            else if(token == "-")
                st.push(a - b);
            else if(token == "*")
                st.push(a * b);
            else
                st.push(a / b);
        }
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens);
    return 0;
}