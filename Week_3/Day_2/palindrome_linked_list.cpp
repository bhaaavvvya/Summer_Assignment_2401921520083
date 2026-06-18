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
//Use slow and fast pointers to find
//the middle of the linked list.
//
//Push the first half elements
//into a stack.
//
//If the list length is odd,
//skip the middle node.
//
//Compare the second half of the list
//with elements popped from the stack.
//If any value differs,
//the list is not a palindrome.
//Time complexity: O(N)
//Space complexity: O(N)

bool isPalindrome(ListNode* head)
{
    stack<int> st;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast != NULL)
    {
        slow = slow->next;
    }
    while(slow != NULL)
    {
        int x = st.top();
        st.pop();
        if(slow->val != x)
            return false;
        slow = slow->next;
    }
    return true;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << (isPalindrome(head) ? "true" : "false");
    return 0;
}