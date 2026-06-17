//adding required header files
#include<iostream>
#include<stack>
using namespace std;

//definition for singly-linked list
struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

//APPROACH:
//Store all node values in a stack.
//Since a stack follows LIFO order,
//values will be retrieved in reverse order.
//
//Traverse the linked list again
//and replace each node's value
//with the top element of the stack.
//This reverses the values stored
//in the linked list.
//Time complexity: O(N)
//Space complexity: O(N)

ListNode* reverseList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    stack<int> st;
    ListNode* temp = head;
    while(temp != NULL)
    {
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL)
    {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head = reverseList(head);

    //print reversed list
    ListNode* temp = head;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}