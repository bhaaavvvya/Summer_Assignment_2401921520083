//adding required header files
#include<iostream>
#include<stack>
using namespace std;

//APPROACH:
//Use two stacks:
//st    -> stores all elements
//minSt -> stores minimum elements
//
//While pushing,
//add the element to minSt if it is
//smaller than or equal to the current minimum.
//
//While popping,
//if the top element of st is equal
//to the top element of minSt,
//remove it from minSt as well.
//
//The top of minSt always stores
//the minimum element in the stack.
//Time complexity:
//push()   -> O(1)
//pop()    -> O(1)
//top()    -> O(1)
//getMin() -> O(1)
//Space complexity: O(N)

class MinStack
{
public:
    stack<int> st;
    stack<int> minSt;

    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        if(minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }

    void pop()
    {
        if(st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};

int main()
{
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << obj.getMin() << endl;
    obj.pop();
    cout << obj.top() << endl;
    cout << obj.getMin();
    return 0;
}