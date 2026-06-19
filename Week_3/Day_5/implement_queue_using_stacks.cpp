//adding required header files
#include<iostream>
#include<stack>
using namespace std;

//APPROACH:
//Implement a queue using two stacks.
//in  -> stores newly inserted elements.
//out -> stores elements in queue order.
//
//For push operation,
//simply insert into the in stack.
//
//For pop and peek operations,
//if out is empty,
//transfer all elements from in to out.
//This reverses their order and gives
//FIFO behavior.
//
//The queue is empty only when
//both stacks are empty.
//Time complexity:
//push()  -> O(1)
//pop()   -> O(1) amortized
//peek()  -> O(1) amortized
//empty() -> O(1)
//Space complexity: O(N)

class MyQueue
{
public:
    stack<int> in;
    stack<int> out;

    MyQueue()
    {
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        if(out.empty())
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        int x = out.top();
        out.pop();
        return x;
    }

    int peek()
    {
        if(out.empty())
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty()
    {
        return in.empty() && out.empty();
    }
};

int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << (q.empty() ? "true" : "false");
    return 0;
}